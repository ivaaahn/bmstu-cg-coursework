#include <QFileDialog>
#include <exceptions/base_exception.hpp>
#include <iostream>
#include "commands/model/model_commands.hpp"
#include "commands/scene/scene_commands.hpp"
#include "commands/camera/camera_commands.hpp"
#include "commands/light/light_commands.hpp"
#include "mainwindow.h"

#include "drawer/factory/qt_drawer_factory.hpp"
#include "../../consts.hpp"

#define CAM_SHIFT 2

#define NONE_TXT "None"


void MainWindow::setupScene() {
    this->scene = std::make_shared<QGraphicsScene>(this);
    ui->graphicsView->setScene(this->scene.get());
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    std::cout << ui->graphicsView->width() << ' ' << ui->graphicsView->height() << std::endl;

    this->scene->setSceneRect(0, 0, WIDTH, HEIGHT);

    auto factory = std::make_shared<QtDrawerFactory>(this->scene);
    this->drawer = factory->createDrawer();

    this->on_add_camera_btn_clicked();
    this->updateScene();
}

void MainWindow::updateScene() {
    auto render_scene_cmd = std::make_shared<RenderScene>(this->drawer);
    try {
        this->facade->execute(render_scene_cmd);
        this->drawer->updateScene();
    } catch (BaseException& ex) {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
}

//size_t MainWindow::getCamerasCount() const {
////    auto cameras_count = std::make_shared<size_t>(0);
////    auto cameras_count_cmd = std::make_shared<CountCameras>(cameras_count);
////    this->facade->execute(cameras_count_cmd);
////
////    return *cameras_count;
//}

//size_t MainWindow::getModelsCount() const {
//    auto models_count = std::make_shared<size_t>(0);
//    auto models_count_cmd = std::make_shared<CountModels>(models_count);
//    this->facade->execute(models_count_cmd);
//
//    return *models_count;
//}

void MainWindow::on_move_btn_clicked() {
    if (!this->checkCamAndModel()) return;

    auto move_model_cmd = std::make_shared<MoveModel>(
            getCurrModelId(),
            ui->x_box->value(), ui->y_box->value(), ui->z_box->value()
    );

    try {
        this->facade->execute(move_model_cmd);
        this->updateScene();
    } catch (const BaseException& ex) {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
}

void MainWindow::on_scale_btn_clicked() {
    if (!this->checkCamAndModel()) return;

    auto scale_model_cmd = std::make_shared<ScaleModel>(
            getCurrModelId(),
            ui->x_box->value(), ui->y_box->value(), ui->z_box->value()
    );

    try {
        this->facade->execute(scale_model_cmd);
        this->updateScene();
    } catch (const BaseException& ex) {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
}

void MainWindow::on_rotate_btn_clicked() {
    if (!this->checkCamAndModel()) return;

    auto rotate_model_cmd = std::make_shared<RotateModel>(
            getCurrModelId(),
            ui->x_box->value(), ui->y_box->value(), ui->z_box->value()
    );

    try {
        this->facade->execute(rotate_model_cmd);
        this->updateScene();
    } catch (BaseException& ex) {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
}

void MainWindow::on_load_model_btn_clicked() {
    if (!this->cameraSelected()) {
        QMessageBox::critical(nullptr, "Ошибка", "Сначала выберите камеру");
        return;
    }
    auto filename = QFileDialog::getOpenFileName();
    if (filename.isNull()) return;

//    auto load_model_cmd = std::make_shared<LoadSphere>(filename.toUtf8().data());
    auto load_model_cmd = std::make_shared<LoadTriangularModel>(filename.toUtf8().data());

    try {
        this->facade->execute(load_model_cmd);
        this->updateScene();
        ui->models_list->addItem(QString("Model#") + QString::number(++this->last_mod_id));
    }
    catch (const BaseException& ex) {
        QMessageBox::warning(this, "Error", QString(ex.what()));
        return;
    }

    auto mod_list = ui->models_list;
    ui->curr_model_lbl->setText(mod_list->item(mod_list->count() - 1)->text());
}

void MainWindow::on_load_light_btn_clicked() {
    if (!this->cameraSelected()) {
        QMessageBox::critical(nullptr, "Ошибка", "Сначала выберите камеру");
        return;
    }

    auto filename = QFileDialog::getOpenFileName();
    if (filename.isNull()) return;
    auto load_light_cmd = std::make_shared<LoadLight>(filename.toUtf8().data());

    try {
        this->facade->execute(load_light_cmd);
        this->updateScene();
        ui->lights_list->addItem(QString("Light#") + QString::number(++this->last_light_id));
    }
    catch (const BaseException& ex) {
        QMessageBox::warning(this, "Error", QString(ex.what()));
        return;
    }
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
//    this->resetModel();
//    for (int i = mod_list->count() - 1; i >= 0; --i)
//        if (mod_list->item(i)->text().contains("Model")) {
//            remove_cmd = std::make_shared<RemoveModel>(i);
//            this->facade->execute(remove_cmd);
//            mod_list->takeItem(i);
//        }
//
//    if (this->cameraSelected()) this->updateScene();
//
//    auto cam_list = ui->cams_list;
//
//    this->resetCamera();
//    for (int i = cam_list->count() - 1; i >= 0; --i)
//        if (cam_list->item(i)->text().contains("Camera")) {
//            remove_cmd = std::make_shared<RemoveCamera>(i);
//            this->facade->execute(remove_cmd);
//            cam_list->takeItem(i);
//        }
//}

void MainWindow::on_add_light_btn_clicked() {
    auto add_light_cmd = std::make_shared<AddLight>(
            ui->x_box->value(), ui->y_box->value(), ui->z_box->value(), ui->intensity_box->value()
    );

    auto lights_list = ui->lights_list;

    try {
        this->facade->execute(add_light_cmd);
        this->updateScene();
        lights_list->addItem(QString("Light#") + QString::number(++this->last_light_id));
    }
    catch (BaseException& ex) {
        QMessageBox::warning(this, "Error", QString(ex.what()));
        return;
    }
}

void MainWindow::on_add_camera_btn_clicked() {
    auto add_camera_cmd = std::make_shared<AddCamera>(
            0., 0., -1.
    );

    try {
        this->facade->execute(add_camera_cmd);
        ui->cams_list->addItem(QString("Camera#") + QString::number(++this->last_cam_id));
    }
    catch (BaseException& ex) {
        QMessageBox::warning(this, "Error", QString(ex.what()));
        return;
    }

    auto cams_list = ui->cams_list;
    ui->curr_camera_lbl->setText(cams_list->item(cams_list->count() - 1)->text());

    this->updateLocation();
}


void MainWindow::updateLocation() {
    std::cout << "updating location ..." << std::endl;
    auto x = std::make_shared<float>();
    auto y = std::make_shared<float>();
    auto z = std::make_shared<float>();

    std::cout<< "Current camId: " << getCurrCameraID() << std::endl;

    auto get_loc_cmd = std::make_shared<GetLocation>(getCurrCameraID(), x, y, z);
    this->facade->execute(get_loc_cmd);

    std::cout<< "x, y, z: " << *x << ' ' << *y << ' ' << *z << std::endl;


    ui->curr_loc_lbl->setText("("+QString::number(*x)+", "+QString::number(*y)+", "+QString::number(*z)+")");

    std::cout << "end updating location ..." << std::endl;
}
//bool MainWindow::canRemoveModel(const size_t id) {
////    if (!this->getModelsCount())
////    {
////        QMessageBox::critical(nullptr, "Ошибка", "Прежде чем удалять модель, добавьте хотя бы одну.");
////        return false;
////    }
//
//    return true;
//}
//
//bool MainWindow::canRemoveCamera(const size_t id) {
//    return true;
////    if (!this->getCamerasCount())
////    {
////        QMessageBox::critical(nullptr, "Ошибка", "Прежде чем удалять камеру, добавьте хотя бы одну.");
////        return false;
////    }
////
////    if (this->getCamerasCount() == 1 && this->getModelsCount())
////    {
////        QMessageBox::critical(nullptr, "Ошибка",
////                              "Прежде чем удалять последнюю камеру, необходимо удалить оставшиеся модели.");
////        return false;
////    }
////
////    if (this->getCamerasCount() > 1 &&
////        ui->objects_list->currentItem()->text() == ui->curr_camera_lbl->text())
////    {
////        QMessageBox::critical(nullptr, "Ошибка",
////                              "Прежде чем удалить данную камеру, выберите другую в качестве текущей");
////        return false;
////    }
////
////    return true;
//}

void MainWindow::on_change_model_btn_clicked() {
    if (ui->models_list->currentRow() < 0) {
        QMessageBox::critical(nullptr, "Ошибка", "Выберите модель, которую хотите сделать текущей");
        return;
    }

    auto curr_item = ui->models_list->currentItem();

    if (curr_item->text().contains("Model"))
        ui->curr_model_lbl->setText(curr_item->text());
    else
        QMessageBox::critical(nullptr, "Ошибка", "Выберите корректную модель");
}


void MainWindow::on_change_camera_btn_clicked() {
    if (ui->cams_list->currentRow() < 0) {
        QMessageBox::critical(nullptr, "Ошибка", "Выберите камеру, которую хотите сделать текущей");
        return;
    }

    auto curr_item = ui->cams_list->currentItem();
    if (!curr_item->text().contains("camera")) {
        QMessageBox::critical(nullptr, "Ошибка", "Выберите корректную камеру");
        return;
    }

    auto camera_set_cmd = std::make_shared<SetCamera>(ui->cams_list->currentRow());

    try {
        this->facade->execute(camera_set_cmd);
        this->updateScene();
        ui->curr_camera_lbl->setText(curr_item->text());
    } catch (BaseException& ex) {
        QMessageBox::warning(this, "Error", QString(ex.what()));
        return;
    }
}


void MainWindow::on_rm_mod_btn_clicked() {
    auto curr_row = ui->models_list->currentRow();
    if (curr_row < 0) {
        QMessageBox::critical(nullptr, "Ошибка", "Выберите модель, которую хотите удалить");
        return;
    }

    auto text_item = ui->models_list->currentItem()->text();
    if (text_item == ui->curr_model_lbl->text()) {
        this->resetModel();
    }

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

void MainWindow::on_rm_cam_btn_clicked() {
    auto curr_row = ui->cams_list->currentRow();
    if (curr_row < 0) {
        QMessageBox::critical(nullptr, "Ошибка", "Выберите камеру, которую хотите удалить");
        return;
    }

    auto text_item = ui->cams_list->currentItem()->text();
    if (text_item == ui->curr_camera_lbl->text()) {
        QMessageBox::critical(nullptr, "Ошибка", "Нельзя удалить текущую камеру!");
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

void MainWindow::on_rm_light_btn_clicked() {
    auto curr_row = ui->lights_list->currentRow();
    if (curr_row < 0) {
        QMessageBox::critical(nullptr, "Ошибка", "Выберите источник света, который хотите удалить");
        return;
    }

    auto rm_light_cmd = std::make_shared<RemoveLight>(curr_row);

    try {
        this->facade->execute(rm_light_cmd);
        ui->lights_list->takeItem(curr_row);
        this->updateScene();
    } catch (BaseException& ex) {
        QMessageBox::warning(this, "Error", QString(ex.what()));
        return;
    }
}


void MainWindow::on_zoom_in_btn_clicked() {
    if (!this->checkCam()) return;

    auto camera_move_cmd = std::make_shared<MoveCamera>(this->getCurrCameraID(), 0, 0, -CAM_SHIFT);
    try {
        this->facade->execute(camera_move_cmd);
        this->updateScene();
    } catch (BaseException& ex) {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }

    this->updateLocation();
}

void MainWindow::on_zoom_out_btn_clicked() {
    if (!this->checkCam()) return;

    auto camera_move_cmd = std::make_shared<MoveCamera>(this->getCurrCameraID(), 0, 0, CAM_SHIFT);
    try {
        this->facade->execute(camera_move_cmd);
        this->updateScene();
    } catch (BaseException& ex) {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
    this->updateLocation();

}

void MainWindow::on_right_btn_clicked() {
    if (!this->checkCam()) return;

    auto camera_move_cmd = std::make_shared<MoveCamera>(this->getCurrCameraID(), CAM_SHIFT, 0, 0);
    try {
        this->facade->execute(camera_move_cmd);
        this->updateScene();
    } catch (BaseException& ex) {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
    this->updateLocation();

}

void MainWindow::on_left_btn_clicked() {
    if (!this->checkCam()) return;

    auto camera_move_cmd = std::make_shared<MoveCamera>(this->getCurrCameraID(), -CAM_SHIFT, 0, 0);
    try {
        this->facade->execute(camera_move_cmd);
        this->updateScene();
    } catch (BaseException& ex) {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
    this->updateLocation();
}

void MainWindow::on_up_btn_clicked() {
    if (!this->checkCam()) return;

    auto camera_move_cmd = std::make_shared<MoveCamera>(this->getCurrCameraID(), 0, CAM_SHIFT, 0);
    try {
        this->facade->execute(camera_move_cmd);
        this->updateScene();
    } catch (BaseException& ex) {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
    this->updateLocation();

}

void MainWindow::on_down_btn_clicked() {
    if (!this->checkCam()) return;

    auto camera_move_cmd = std::make_shared<MoveCamera>(this->getCurrCameraID(), 0, -CAM_SHIFT, 0);
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
//    this->updateWithImag
//    this->drawer->updateWithImage();
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setupScene();

    this->facade = std::make_shared<Facade>(Facade());
}

bool MainWindow::checkCamAndModel() {
    if (!this->cameraSelected() || !this->modelSelected()) {
        QMessageBox::critical(nullptr, "Ошибка", "Сначала выберите камеру и модель");
        return false;
    }

    return true;
}

bool MainWindow::checkCam() {
    if (!this->cameraSelected()) {
        QMessageBox::critical(nullptr, "Ошибка", "Сначала выберите камеру");
        return false;
    }

    return true;
}


void MainWindow::resetCamera() {
    ui->curr_camera_lbl->setText(NONE_TXT);
    ui->curr_loc_lbl->setText(NONE_TXT);
}

void MainWindow::resetModel() { ui->curr_model_lbl->setText(NONE_TXT); }

bool MainWindow::cameraSelected() { return ui->curr_camera_lbl->text() != QString(NONE_TXT); }

bool MainWindow::modelSelected() { return ui->curr_model_lbl->text() != QString(NONE_TXT); }

size_t MainWindow::getCurrCameraID() {
    auto item = ui->cams_list->findItems(ui->curr_camera_lbl->text(), Qt::MatchExactly)[0];
    return ui->cams_list->row(item);
}

size_t MainWindow::getCurrModelId() {
    auto item = ui->models_list->findItems(ui->curr_model_lbl->text(), Qt::MatchExactly)[0];
    return ui->models_list->row(item);
}

MainWindow::~MainWindow() { delete ui; }

