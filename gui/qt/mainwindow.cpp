#include <QFileDialog>
#include <exceptions/base_exception.hpp>
#include <iostream>
#include "commands/model/model_commands.hpp"
#include "commands/scene/scene_commands.hpp"
#include "commands/camera/camera_commands.hpp"
#include "commands/light/light_commands.hpp"
#include "mainwindow.h"

#include "drawer/factory/qt_drawer_factory.hpp"

#define CAM_SHIFT 2


void MainWindow::setupScene() {
    this->scene = std::make_shared<QGraphicsScene>(this);
    ui->graphicsView->setScene(this->scene.get());
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    this->scene->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());

    auto factory = std::make_shared<QtDrawerFactory>(this->scene);
    this->drawer = factory->createDrawer();
}

void MainWindow::updateScene() {
    auto render_scene_cmd = std::make_shared<RenderScene>(this->drawer);

    try
    {
        this->facade->execute(render_scene_cmd);
        this->drawer->updateScene();
    }
    catch (BaseException &ex)
    {
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

    auto move_model_cmd = std::make_shared<MoveModel>(this->getCurrModelID(),
                                                      this->ui->dx_box->value(),
                                                      this->ui->dy_box->value(),
                                                      this->ui->dz_box->value());
    try
    {
        this->facade->execute(move_model_cmd);
        this->updateScene();
    } catch (const BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
}

void MainWindow::on_scale_btn_clicked() {
    if (!this->checkCamAndModel()) return;

    auto scale_model_cmd = std::make_shared<ScaleModel>(this->getCurrModelID(),
                                                        this->ui->kx_box->value(),
                                                        this->ui->ky_box->value(),
                                                        this->ui->kz_box->value());
    try
    {
        this->facade->execute(scale_model_cmd);
        this->updateScene();
    } catch (const BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
}

void MainWindow::on_rotate_btn_clicked() {
    if (!this->checkCamAndModel()) return;

    auto rotate_model_cmd = std::make_shared<RotateModel>(this->getCurrModelID(),
                                                          this->ui->ax_box->value(),
                                                          this->ui->ay_box->value(),
                                                          this->ui->az_box->value());
    try
    {
        this->facade->execute(rotate_model_cmd);
        this->updateScene();
    } catch (BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
}

void MainWindow::on_load_model_btn_clicked() {
    if (!this->cameraSelected())
    {
        QMessageBox::critical(nullptr, "Ошибка", "Сначала выберите камеру");
        return;
    }

    auto filename = QFileDialog::getOpenFileName();
    if (filename.isNull()) return;
    auto load_model_cmd = std::make_shared<LoadSphere>(filename.toUtf8().data());
//    auto load_model_cmd = std::make_shared<LoadModel>(filename.toUtf8().data());

    try
    {
        this->facade->execute(load_model_cmd);
        this->updateScene();
        this->ui->figures_list->addItem(QString("figure_") + QString::number(++this->last_mod_id));
    }
    catch (const BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
        return;
    }

    auto fig_list = this->ui->figures_list;
    this->ui->curr_model_lbl->setText(fig_list->item(fig_list->count() - 1)->text());
}

void MainWindow::on_load_light_btn_clicked() {
//    if (!this->cameraSelected())
//    {
//        QMessageBox::critical(nullptr, "Ошибка", "Сначала выберите камеру");
//        return;
//    }

    auto filename = QFileDialog::getOpenFileName();
    if (filename.isNull()) return;
    auto load_light_cmd = std::make_shared<LoadLight>(filename.toUtf8().data());
//    auto load_model_cmd = std::make_shared<LoadModel>(filename.toUtf8().data());

    try
    {
        this->facade->execute(load_light_cmd);
        this->updateScene();
//        this->ui->figures_list->addItem(QString("figure_") + QString::number(++this->last_mod_id));
    }
    catch (const BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
        return;
    }

//    auto fig_list = this->ui->figures_list;
//    this->ui->curr_model_lbl->setText(fig_list->item(fig_list->count() - 1)->text());
}

void MainWindow::on_clear_scene_btn_clicked() {
    auto fig_list = this->ui->figures_list;
    if (!fig_list->count())
    {
        QMessageBox::information(nullptr, "OK!", "Сцена уже очищена");
        return;
    }

    std::shared_ptr<Command> remove_cmd;

    this->resetModel();
    for (int i = fig_list->count() - 1; i >= 0; --i)
        if (fig_list->item(i)->text().contains("model"))
        {
            remove_cmd = std::make_shared<RemoveModel>(i);
            this->facade->execute(remove_cmd);
            fig_list->takeItem(i);
        }

    if (this->cameraSelected()) this->updateScene();

    auto cam_list= this->ui->cams_list;

    this->resetCamera();
    for (int i = cam_list->count() - 1; i >= 0; --i)
        if (cam_list->item(i)->text().contains("camera"))
        {
            remove_cmd = std::make_shared<RemoveCamera>(i);
            this->facade->execute(remove_cmd);
            cam_list->takeItem(i);
        }
}

void MainWindow::on_load_camera_btn_clicked() {
    auto filename = QFileDialog::getOpenFileName();
    if (filename.isNull()) return;
    auto load_camera_cmd = std::make_shared<LoadCamera>(filename.toUtf8().data());

    try
    {
        this->facade->execute(load_camera_cmd);
        this->ui->cams_list->addItem(QString("camera_") + QString::number(++this->last_cam_id));
    }
    catch (BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
        return;
    }

    auto cam_list = this->ui->cams_list;
    this->ui->curr_camera_lbl->setText(cam_list->item(cam_list->count() - 1)->text());
    this->updateScene();
}

void MainWindow::on_add_camera_btn_clicked() {
    auto r_content = ui->graphicsView->contentsRect();
    auto add_camera_cmd = std::make_shared<AddCamera>(0., 0., 0.);
//    auto add_camera_cmd = std::make_shared<AddCamera>(-r_content.width() / 2.0, -r_content.height() / 2.0, 0.0);

    try
    {
        this->facade->execute(add_camera_cmd);
        this->ui->cams_list->addItem(QString("camera_") + QString::number(++this->last_cam_id));
    }
    catch (BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
        return;
    }

    auto obj_list = this->ui->cams_list;
    this->ui->curr_camera_lbl->setText(obj_list->item(obj_list->count() - 1)->text());
//    this->updateScene();
}

void MainWindow::on_change_model_btn_clicked() {
    if (this->ui->figures_list->currentRow() < 0)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Выберите модель, которую хотите сделать текущей");
        return;
    }

    auto curr_item = this->ui->figures_list->currentItem();

    if (curr_item->text().contains("model"))
        this->ui->curr_model_lbl->setText(curr_item->text());
    else
        QMessageBox::critical(nullptr, "Ошибка", "Выберите корректную модель");
}


void MainWindow::on_change_camera_btn_clicked() {
    if (this->ui->cams_list->currentRow() < 0)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Выберите камеру, которую хотите сделать текущей");
        return;
    }

    auto curr_item = this->ui->cams_list->currentItem();
    if (!curr_item->text().contains("camera"))
    {
        QMessageBox::critical(nullptr, "Ошибка", "Выберите корректную камеру");
        return;
    }

    auto camera_set_cmd = std::make_shared<SetCamera>(this->ui->cams_list->currentRow());

    try
    {
        this->facade->execute(camera_set_cmd);
        this->updateScene();
        this->ui->curr_camera_lbl->setText(curr_item->text());
    } catch (BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
        return;
    }
}

bool MainWindow::canRemoveModel(const size_t id) {
//    if (!this->getModelsCount())
//    {
//        QMessageBox::critical(nullptr, "Ошибка", "Прежде чем удалять модель, добавьте хотя бы одну.");
//        return false;
//    }

    return true;
}

bool MainWindow::canRemoveCamera(const size_t id) {
    return true;
//    if (!this->getCamerasCount())
//    {
//        QMessageBox::critical(nullptr, "Ошибка", "Прежде чем удалять камеру, добавьте хотя бы одну.");
//        return false;
//    }
//
//    if (this->getCamerasCount() == 1 && this->getModelsCount())
//    {
//        QMessageBox::critical(nullptr, "Ошибка",
//                              "Прежде чем удалять последнюю камеру, необходимо удалить оставшиеся модели.");
//        return false;
//    }
//
//    if (this->getCamerasCount() > 1 &&
//        this->ui->objects_list->currentItem()->text() == this->ui->curr_camera_lbl->text())
//    {
//        QMessageBox::critical(nullptr, "Ошибка",
//                              "Прежде чем удалить данную камеру, выберите другую в качестве текущей");
//        return false;
//    }
//
//    return true;
}

void MainWindow::resetCamera() { this->ui->curr_camera_lbl->setText("None"); }

void MainWindow::resetModel() { this->ui->curr_model_lbl->setText("None"); }

bool MainWindow::cameraSelected() { return this->ui->curr_camera_lbl->text() != QString("None"); }

bool MainWindow::modelSelected() { return this->ui->curr_model_lbl->text() != QString("None"); }

void MainWindow::on_remove_object_btn_clicked() {
//    auto curr_row = this->ui->objects_list->currentRow();
//    if (curr_row < 0)
//    {
//        QMessageBox::critical(nullptr, "Ошибка", "Выберите объект, который хотите удалить");
//        return;
//    }
//
//    std::shared_ptr<Command> remove_cmd;
//
//    auto text_item = this->ui->objects_list->currentItem()->text();
//    if (text_item.contains("camera"))
//    {
//        if (!this->canRemoveCamera(curr_row)) return;
//
//        auto cam_lbl = this->ui->curr_camera_lbl;
//        if (text_item == cam_lbl->text()) this->resetCamera();
//
//        remove_cmd = std::make_shared<RemoveCamera>(curr_row);
//    }
//    else
//    {
//        if (!this->canRemoveModel(curr_row)) return;
//
//        auto mod_lbl = this->ui->curr_model_lbl;
//        if (text_item == mod_lbl->text()) this->resetModel();
//
//        remove_cmd = std::make_shared<RemoveModel>(curr_row);
//    }
//
//    try
//    {
//        this->facade->execute(remove_cmd);
//        this->ui->objects_list->takeItem(curr_row);
//        this->updateScene();
//    } catch (BaseException &ex)
//    {
//        QMessageBox::warning(this, "Error", QString(ex.what()));
//        return;
//    }
}

size_t MainWindow::getCurrCameraID() {
    auto item = this->ui->cams_list->findItems(this->ui->curr_camera_lbl->text(), Qt::MatchExactly)[0];
    return this->ui->cams_list->row(item);
}

size_t MainWindow::getCurrModelID() {
    auto item = this->ui->figures_list->findItems(this->ui->curr_model_lbl->text(), Qt::MatchExactly)[0];
    return this->ui->figures_list->row(item);
}

void MainWindow::on_right_btn_clicked() {
    if (!this->checkCamAndModel()) return;

    auto camera_move_cmd = std::make_shared<MoveCamera>(this->getCurrCameraID(), CAM_SHIFT, 0, 0);
    try
    {
        this->facade->execute(camera_move_cmd);
        this->updateScene();
    } catch (BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
}

void MainWindow::on_up_btn_clicked() {
    if (!this->checkCamAndModel()) return;

    auto camera_move_cmd = std::make_shared<MoveCamera>(this->getCurrCameraID(), 0, -CAM_SHIFT, 0);
    try
    {
        this->facade->execute(camera_move_cmd);
        this->updateScene();
    } catch (BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
}

void MainWindow::on_down_btn_clicked() {
    if (!this->checkCamAndModel()) return;

    auto camera_move_cmd = std::make_shared<MoveCamera>(this->getCurrCameraID(), 0, CAM_SHIFT, 0);
    try
    {
        this->facade->execute(camera_move_cmd);
        this->updateScene();
    } catch (BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
}

void MainWindow::on_left_btn_clicked() {
    if (!this->checkCamAndModel()) return;

    auto camera_move_cmd = std::make_shared<MoveCamera>(this->getCurrCameraID(), -CAM_SHIFT, 0, 0);
    try
    {
        this->facade->execute(camera_move_cmd);
        this->updateScene();
    } catch (BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);

    this->scene->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());

    auto r_content = ui->graphicsView->contentsRect();

    std::cout << ui->graphicsView->width() << "; " <<  ui->graphicsView->height() << std::endl;
    std::cout << r_content.width() << "; " << r_content.height() << std::endl;

    this->scene->setSceneRect(0, 0, r_content.width(), r_content.height());
//    this->updateWithImag
//    this->drawer->updateWithImage();
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    this->ui->setupUi(this);
    this->setupScene();

    this->facade = std::make_shared<Facade>(Facade());
}

bool MainWindow::checkCamAndModel() {
    if (!this->cameraSelected() || !this->modelSelected())
    {
        QMessageBox::critical(nullptr, "Ошибка", "Сначала выберите камеру и модель");
        return false;
    }

    return true;
}

MainWindow::~MainWindow() { delete ui; }

