#include <QFileDialog>
#include <exceptions/base_exception.hpp>
#include <iostream>
#include <QInputDialog>
#include "commands/model/model_commands.hpp"
#include "commands/scene/scene_commands.hpp"
#include "commands/camera/camera_commands.hpp"
#include "commands/light/light_commands.hpp"
#include "mainwindow.h"

#include "drawer/factory/qt_drawer_factory.hpp"
#include "../../consts.hpp"

#include "design_light_add_popup.h"

#define CAM_SHIFT 2

#define NONE_TXT "None"


float3 MainWindow::_readModCoords() {
    return {
            (float)ui->x_box->value(),
            (float)ui->y_box->value(),
            (float)ui->z_box->value()
    };
}

float3 MainWindow::_readLightCoords() {
    return {
            (float)ui->light_x_box->value(),
            (float)ui->light_y_box->value(),
            (float)ui->light_z_box->value()
    };
}

float3 MainWindow::_readModColor() {
    return {
            (float)ui->color0_box->value(),
            (float)ui->color1_box->value(),
            (float)ui->color2_box->value()
    };
}

float4 MainWindow::_readAlbedo() {
    return {
            (float)ui->alb0_box->value(),
            (float)ui->alb1_box->value(),
            (float)ui->alb2_box->value(),
            (float)ui->alb3_box->value()
    };
}

float3 MainWindow::_readLocationCoords(int& turn, int& fov) {
    turn = ui->cam_turn_box->value();
    fov = ui->cam_fov_box->value();
    return {
            (float)ui->cam_x_box->value(),
            (float)ui->cam_y_box->value(),
            (float)ui->cam_z_box->value()
    };
}

Material MainWindow::_readMaterial() {
    return {
            (float)(ui->refr_idx_box->value()),
            this->_readAlbedo(),
            this->_readModColor(),
            (float)(ui->spec_exp_box->value()),
            (float)(ui->ambient_box->value())
    };
}


void MainWindow::setupScene() {
    this->scene = std::make_shared<QGraphicsScene>(this);
    ui->graphicsView->setScene(this->scene.get());
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    this->scene->setSceneRect(0, 0, WIDTH, HEIGHT);

    auto factory = std::make_shared<QtDrawerFactory>(this->scene);
    this->drawer = factory->createDrawer();


    this->on_cam_add_btn_clicked();
    this->updateScene();

    this->_updateSceneLightData();
}

void MainWindow::updateScene() {
    try {
        this->facade->execute(std::make_shared<RenderScene>(this->drawer));
        this->drawer->updateScene();
    } catch (BaseException& ex) {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
}


void MainWindow::on_move_btn_clicked() {
    if (!this->checkModel()) return;

    try {
        this->facade->execute(std::make_shared<TranslateModel>(_currModId(), this->_readModCoords()));
        this->updateScene();
    } catch (const BaseException& ex) {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
}

void MainWindow::on_scale_btn_clicked() {
    if (!this->checkModel()) return;

    auto cords = this->_readModCoords();

    if (cords.x * cords.y * cords.z == 0.) {
        QMessageBox msgBox;
        msgBox.setText("Один из коэффициентов равен нулю");
        msgBox.setInformativeText("Продолжить?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        auto ret = msgBox.exec();
        if (ret == QMessageBox::No) return;
    }

    try {
        this->facade->execute(std::make_shared<ScaleModel>(this->_currModId(), cords));
        this->updateScene();
    } catch (const BaseException& ex) {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
}

void MainWindow::on_rotate_btn_clicked() {
    if (!this->checkModel()) return;

    try {
        this->facade->execute(std::make_shared<RotateModel>(this->_currModId(), this->_readModCoords()));
        this->updateScene();
    } catch (BaseException& ex) {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
}


void MainWindow::on_mod_load_btn_clicked() {
    if (!this->_camSelected()) {
        QMessageBox::critical(nullptr, "Ошибка", "Сначала выберите камеру");
        return;
    }

    QStringList items;
    items << tr("Полигональная") << tr("Сфера");

    bool ok;
    QString item = QInputDialog::getItem(this, tr("Выбор типа"),
                                         tr("Модель:"), items, 0, false, &ok);
    if (!ok || item.isEmpty())
        return;

    auto mod_list = ui->models_list;
    auto filename = QFileDialog::getOpenFileName();
    if (filename.isNull()) return;

    try {
        if (items.indexOf(item) == FigureType::POLYGONAL)
            this->facade->execute(std::make_shared<LoadTriangularModel>(filename.toUtf8().data()));
        else
            this->facade->execute(std::make_shared<LoadSphere>(filename.toUtf8().data()));

        this->updateScene();
        mod_list->addItem(QString("Model#") + QString::number(++this->last_mod_id) + " : " +
                          filename.section('/', -1).section('.', 0, 0));

        ui->mod_curr_lbl->setText(mod_list->item(mod_list->count() - 1)->text());

    }
    catch (const BaseException& ex) {
        QMessageBox::warning(this, "Error", QString(ex.what()));
        return;
    }

    this->_updateMaterialInfo();
}

void MainWindow::on_light_load_btn_clicked() {
    if (!this->_camSelected()) {
        QMessageBox::critical(nullptr, "Ошибка", "Сначала выберите камеру");
        return;
    }

    auto filename = QFileDialog::getOpenFileName();
    if (filename.isNull()) return;

    try {
        this->facade->execute(std::make_shared<LoadLight>(filename.toUtf8().data()));
        this->updateScene();
        ui->lights_list->addItem(QString("Light#") + QString::number(++this->last_light_id));
    }
    catch (const BaseException& ex) {
        QMessageBox::warning(this, "Error", QString(ex.what()));
        return;
    }

    auto lights_list = ui->lights_list;
    ui->light_curr_lbl->setText(lights_list->item(lights_list->count() - 1)->text());
    this->updateLightInfo();
}

//void MainWindow::on_clear_scene_btn_clicked() {
//    auto mod_list = ui->models_list;
//    if (!mod_list->count()) {
//        QMessageBox::information(nullptr, "OK!", "Сцена уже очищена");
//        return;
//    }
//
//    std::shared_ptr<Command> remove_cmd;
//
//    this->_modReset();
//    for (int i = mod_list->count() - 1; i >= 0; --i)
//        if (mod_list->item(i)->text().contains("Model")) {
//            remove_cmd = std::make_shared<RemoveModel>(i);
//            this->facade->execute(remove_cmd);
//            mod_list->takeItem(i);
//        }
//
//    if (this->_camSelected()) this->updateScene();
//
//    auto cam_list = ui->cams_list;
//
//    this->_camReset();
//    for (int i = cam_list->count() - 1; i >= 0; --i)
//        if (cam_list->item(i)->text().contains("Camera")) {
//            remove_cmd = std::make_shared<RemoveCamera>(i);
//            this->facade->execute(remove_cmd);
//            cam_list->takeItem(i);
//        }
//}

void MainWindow::on_light_add_btn_clicked() {
    try {
        this->facade->execute(std::make_shared<AddLight>(this->_readLightCoords(), _readLightIntensity()));
        this->updateScene();
        ui->lights_list->addItem(QString("Light#") + QString::number(++this->last_light_id));
        auto lights_list = ui->lights_list;
        ui->light_curr_lbl->setText(lights_list->item(lights_list->count() - 1)->text());
    }
    catch (BaseException& ex) {
        QMessageBox::warning(this, "Error", QString(ex.what()));
        return;
    }

    this->updateLightInfo();
}

void MainWindow::on_cam_add_btn_clicked() {
    try {
        this->facade->execute(std::make_shared<AddCamera>(float3{0., 0., -1.}));
        ui->cams_list->addItem(QString("Camera#") + QString::number(++this->last_cam_id));
    }
    catch (BaseException& ex) {
        QMessageBox::warning(this, "Error", QString(ex.what()));
        return;
    }

    auto cams_list = ui->cams_list;
    ui->cam_curr_lbl->setText(cams_list->item(cams_list->count() - 1)->text());
    this->updateLocation();
}

void MainWindow::updateLightInfo() {
    auto cords = std::make_shared<float3>();
    auto intensity = std::make_shared<float>();

    this->facade->execute(std::make_shared<GetLightInfo>(_currLightId(), cords, intensity));

    ui->light_x_box->setValue(cords->x);
    ui->light_y_box->setValue(cords->y);
    ui->light_z_box->setValue(cords->z);

    ui->light_intensity_box->setValue(*intensity);
}


void MainWindow::updateLocation() {
    auto cords = std::make_shared<float3>();
    this->facade->execute(std::make_shared<GetLocation>(_currCamId(), cords));


    ui->cam_x_box->setValue(cords->x);
    ui->cam_y_box->setValue(cords->y);
    ui->cam_z_box->setValue(cords->z);

//    TODO
//    ui->cam_turn_box->setValue(cords->turn);
//    ui->cam_fov_box->setValue(cords->fov);

}


//void MainWindow::on_change_model_btn_clicked() {
//    if (ui->models_list->currentRow() < 0) {
//        QMessageBox::critical(nullptr, "Ошибка", "Выберите модель, которую хотите сделать текущей");
//        return;
//    }
//
//    auto curr_item = ui->models_list->currentItem();
//
//    if (curr_item->text().contains("Model"))
//        ui->curr_model_lbl->setText(curr_item->text());
//    else
//        QMessageBox::critical(nullptr, "Ошибка", "Выберите корректную модель");
//}




//void MainWindow::on_change_camera_btn_clicked() {
//    if (ui->cams_list->currentRow() < 0) {
//        QMessageBox::critical(nullptr, "Ошибка", "Выберите камеру, которую хотите сделать текущей");
//        return;
//    }
//
//    auto curr_item = ui->cams_list->currentItem();
//    if (!curr_item->text().contains("camera")) {
//        QMessageBox::critical(nullptr, "Ошибка", "Выберите корректную камеру");
//        return;
//    }
//
//    auto camera_set_cmd = std::make_shared<SetCamera>(ui->cams_list->currentRow());
//
//    try {
//        this->facade->execute(camera_set_cmd);
//        this->updateScene();
//        ui->curr_camera_lbl->setText(curr_item->text());
//    } catch (BaseException& ex) {
//        QMessageBox::warning(this, "Error", QString(ex.what()));
//        return;
//    }
//}


void MainWindow::on_mod_rm_btn_clicked() {
    auto curr_row = ui->models_list->currentRow();
    if (curr_row < 0) {
        QMessageBox::critical(nullptr, "Ошибка", "Выберите модель, которую хотите удалить");
        return;
    }

    auto text_item = ui->models_list->currentItem()->text();
    auto rm_mod_cmd = std::make_shared<RemoveModel>(curr_row);

    try {
        this->facade->execute(rm_mod_cmd);
        ui->models_list->takeItem(curr_row);
        this->updateScene();
    } catch (BaseException& ex) {
        QMessageBox::warning(this, "Error", QString(ex.what()));
        return;
    }
}

void MainWindow::on_cam_rm_btn_clicked() {
    auto curr_row = ui->cams_list->currentRow();
    if (curr_row < 0) {
        QMessageBox::critical(nullptr, "Ошибка", "Выберите камеру, которую хотите удалить");
        return;
    }

    auto rm_cam_cmd = std::make_shared<RemoveCamera>(curr_row);

    try {
        this->facade->execute(rm_cam_cmd);
        ui->cams_list->takeItem(curr_row);
        this->updateScene();
    } catch (BaseException& ex) {
        QMessageBox::warning(this, "Error", QString(ex.what()));
        return;
    }
}

void MainWindow::on_light_rm_btn_clicked() {
    auto curr_row = ui->lights_list->currentRow();
    if (curr_row < 0) {
        QMessageBox::critical(nullptr, "Ошибка", "Выберите источник света, который хотите удалить");
        return;
    }

    try {
        this->facade->execute(std::make_shared<RemoveLight>(curr_row));
        ui->lights_list->takeItem(curr_row);
        this->updateScene();
    } catch (BaseException& ex) {
        QMessageBox::warning(this, "Error", QString(ex.what()));
        return;
    }
}


void MainWindow::on_cam_zoom_in_btn_clicked() {
    if (!this->checkCam()) return;

    auto camera_move_cmd = std::make_shared<MoveCamera>(this->_currCamId(), float3{0, 0, -CAM_SHIFT});
    try {
        this->facade->execute(camera_move_cmd);
        this->updateScene();
    } catch (BaseException& ex) {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }

    this->updateLocation();
}

void MainWindow::on_cam_zoom_out_btn_clicked() {
    if (!this->checkCam()) return;

    auto camera_move_cmd = std::make_shared<MoveCamera>(this->_currCamId(), float3{0, 0, CAM_SHIFT});
    try {
        this->facade->execute(camera_move_cmd);
        this->updateScene();
    } catch (BaseException& ex) {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
    this->updateLocation();

}

void MainWindow::on_cam_move_right_btn_clicked() {
    if (!this->checkCam()) return;

    auto camera_move_cmd = std::make_shared<MoveCamera>(this->_currCamId(), float3{CAM_SHIFT, 0, 0});
    try {
        this->facade->execute(camera_move_cmd);
        this->updateScene();
    } catch (BaseException& ex) {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
    this->updateLocation();

}

void MainWindow::on_cam_move_left_btn_clicked() {
    if (!this->checkCam()) return;

    auto camera_move_cmd = std::make_shared<MoveCamera>(this->_currCamId(), float3{-CAM_SHIFT, 0, 0});
    try {
        this->facade->execute(camera_move_cmd);
        this->updateScene();
    } catch (BaseException& ex) {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
    this->updateLocation();
}

void MainWindow::on_cam_move_up_btn_clicked() {
    if (!this->checkCam()) return;

    auto camera_move_cmd = std::make_shared<MoveCamera>(this->_currCamId(), float3{0, CAM_SHIFT, 0});
    try {
        this->facade->execute(camera_move_cmd);
        this->updateScene();
    } catch (BaseException& ex) {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
    this->updateLocation();

}

void MainWindow::on_cam_move_down_btn_clicked() {
    if (!this->checkCam()) return;

    auto camera_move_cmd = std::make_shared<MoveCamera>(this->_currCamId(), float3{0, -CAM_SHIFT, 0});
    try {
        this->facade->execute(camera_move_cmd);
        this->updateScene();
    } catch (BaseException& ex) {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
    this->updateLocation();

}


void MainWindow::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);

    this->scene->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());

    auto r_content = ui->graphicsView->contentsRect();

    std::cout << ui->graphicsView->width() << "; " << ui->graphicsView->height() << std::endl;
    std::cout << r_content.width() << "; " << r_content.height() << std::endl;

    this->scene->setSceneRect(0, 0, r_content.width(), r_content.height());
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setupScene();

    this->facade = std::make_shared<Facade>(Facade());
}

bool MainWindow::checkModel() {
    if (!this->_modSelected()) {
        QMessageBox::critical(nullptr, "Ошибка", "Сначала выберите модель");
        return false;
    }

    return true;
}

bool MainWindow::checkCam() {
    if (!this->_camSelected()) {
        QMessageBox::critical(nullptr, "Ошибка", "Сначала выберите камеру");
        return false;
    }

    return true;
}


void MainWindow::_camReset() {
    ui->cam_curr_lbl->setText(NONE_TXT);
}

void MainWindow::_modReset() {
    ui->mod_curr_lbl->setText(NONE_TXT);
}

bool MainWindow::_camSelected() {
    return ui->cam_curr_lbl->text() != QString(NONE_TXT);
}

bool MainWindow::_modSelected() {
    return ui->mod_curr_lbl->text() != QString(NONE_TXT);
}

bool MainWindow::_lightSelected() {
    return ui->light_curr_lbl->text() != QString(NONE_TXT);
}

size_t MainWindow::_currCamId() {
    auto item = ui->cams_list->findItems(ui->cam_curr_lbl->text(), Qt::MatchExactly)[0];
    return ui->cams_list->row(item);
}

size_t MainWindow::_currModId() {
    auto item = ui->models_list->findItems(ui->mod_curr_lbl->text(), Qt::MatchExactly)[0];
    return ui->models_list->row(item);
}

size_t MainWindow::_currLightId() {
    auto item = ui->lights_list->findItems(ui->light_curr_lbl->text(), Qt::MatchExactly)[0];
    return ui->lights_list->row(item);
}

MainWindow::~MainWindow() { delete ui; }


void MainWindow::on_cam_turn_left_btn_clicked() {

}

void MainWindow::on_cam_turn_right_btn_clicked() {

}

void MainWindow::on_cam_turn_down_btn_clicked() {

}

void MainWindow::on_cam_turn_up_btn_clicked() {

}

void MainWindow::on_cam_apply_btn_clicked() {

}

void MainWindow::on_light_apply_btn_clicked() {
    if (!_lightSelected()) {
        QMessageBox::critical(nullptr, "Ошибка", "Сначала выберите камеру");
        return;
    }
    this->facade->execute(std::make_shared<EditLight>(_currLightId(), _readLightCoords(), _readLightIntensity()));
    this->updateScene();
}

void MainWindow::on_mat_apply_btn_clicked() {
    this->facade->execute(std::make_shared<EditModelMaterial>(_currModId(), _readMaterial()));
    this->updateScene();
}

void MainWindow::on_mat_load_btn_clicked() {

}

void MainWindow::on_mod_switch_btn_clicked() {
    if (ui->models_list->currentRow() < 0) {
        QMessageBox::critical(nullptr, "Ошибка", "Выберите модель, которую хотите сделать текущей");
        return;
    }

    ui->mod_curr_lbl->setText(ui->models_list->currentItem()->text());
    this->_updateMaterialInfo();
}

void MainWindow::on_light_switch_btn_clicked() {
    if (ui->lights_list->currentRow() < 0) {
        QMessageBox::critical(nullptr, "Ошибка", "Выберите источник, который хотите сделать текущим");
        return;
    }

    ui->light_curr_lbl->setText(ui->lights_list->currentItem()->text());
    this->updateLightInfo();
}


void MainWindow::_updateMaterialInfo() {
    auto mat = std::make_shared<Material>();
    this->facade->execute(std::make_shared<GetModelInfo>(_currModId(), mat));

    auto c = mat->getDiffuseColor();
    ui->color0_box->setValue(c.x);
    ui->color1_box->setValue(c.y);
    ui->color2_box->setValue(c.z);

    auto al = mat->getAlbedo();
    ui->alb0_box->setValue(al[0]);
    ui->alb1_box->setValue(al[1]);
    ui->alb2_box->setValue(al[2]);
    ui->alb3_box->setValue(al[3]);

    ui->refr_idx_box->setValue(mat->getRefrIdx());
    ui->spec_exp_box->setValue(mat->getSpecExp());
    ui->ambient_box->setValue(mat->getAmbient());
}


float MainWindow::_readSceneAmbient() {
    return (float)ui->scene_ambient_box->value();
}

float MainWindow::_readLightIntensity() {
    return (float)ui->light_intensity_box->value();
}

int MainWindow::_readRTreeH() {
    return ui->rtree_h_box->value();
}

void MainWindow::on_rtree_h_apply_btn_clicked() {
    this->facade->execute(std::make_shared<EditAmbientLightIntensity>(_readSceneAmbient()));
    this->facade->execute(std::make_shared<EditRTreeHeightMax>(_readRTreeH()));

    this->updateScene();
}

void MainWindow::_updateSceneLightData() {
    auto scene_ambient_ratio = std::make_shared<float>();
    this->facade->execute(std::make_shared<GetAmbientLightIntensity>(scene_ambient_ratio));

    auto rtree_height_max = std::make_shared<int>();
    this->facade->execute(std::make_shared<GetRTreeHeightMax>(rtree_height_max));

    ui->scene_ambient_box->setValue(*scene_ambient_ratio);
    ui->rtree_h_box->setValue(*rtree_height_max);
}
