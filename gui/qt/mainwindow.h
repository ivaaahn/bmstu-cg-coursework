#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include <QMessageBox>
#include <memory>
#include "design.h"

#include "commands/command.hpp"
#include "commands/camera/camera_commands.hpp"
#include "commands/model/model_commands.hpp"
#include "commands/scene/scene_commands.hpp"
#include "drawer/drawer.hpp"
#include "facade/facade.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:
    void _rotateCam(const int2 &delta);
    void _shiftCam(const float3 &delta);

    bool _modSelected();

    bool _camSelected();

    bool _lightSelected();

    void setupScene();

    void updateScene();

    void _modReset();

    void _camReset();

    size_t _currCamId();

    size_t _currModId();

    size_t _currLightId();

    bool checkModel();

    bool checkCam();

    void _updateLightInfo();
    void _updateMaterialInfo();
    void _updateSceneLightData();
    void _updateCamInfo();


    void _setCamInfo(const float3 &pos, const int2 &angles, int fov);

    int _readCamFov();
    void _updateCamFov(int value);
    float _readLightIntensity();
    int _readRTreeH();
    float _readSceneAmbient();
    float3 _readModCoords();
    Material _readMaterial();
    float3 _readModColor();
    float4 _readAlbedo();
    float3 _readLightCoords();

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:

    void on_rtree_h_apply_btn_clicked();

    void on_move_btn_clicked();

    void on_scale_btn_clicked();

    void on_rotate_btn_clicked();

    void on_mod_load_btn_clicked();

    void on_mod_rm_btn_clicked();

    void on_mat_apply_btn_clicked();

    void on_mat_load_btn_clicked();

    void on_light_apply_btn_clicked();

    void on_light_add_btn_clicked();

    void on_mod_switch_btn_clicked();

    void on_light_switch_btn_clicked();

    void on_light_load_btn_clicked();

    void on_light_rm_btn_clicked();

    void on_cam_add_btn_clicked();

    void on_cam_switch_btn_clicked();

    void on_cam_rm_btn_clicked();

    void on_cam_apply_btn_clicked();

    void on_cam_turn_left_btn_clicked();

    void on_cam_turn_right_btn_clicked();

    void on_cam_move_left_btn_clicked();

    void on_cam_move_right_btn_clicked();

    void on_cam_move_up_btn_clicked();

    void on_cam_move_down_btn_clicked();

    void on_cam_turn_up_btn_clicked();

    void on_cam_turn_down_btn_clicked();

    void on_cam_zoom_in_btn_clicked();

    void on_cam_zoom_out_btn_clicked();


private:

    Ui::MainWindow *ui;

    std::shared_ptr<Facade> facade;

    std::shared_ptr<QGraphicsScene> scene;
    std::shared_ptr<Drawer> drawer;

    size_t last_cam_id = 0;
    size_t last_mod_id = 0;
    size_t last_light_id = 0;
};
