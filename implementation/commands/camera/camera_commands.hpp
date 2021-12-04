//
// Created by ivaaahn on 07.09.2021.
//

#ifndef __CG_COURSEWORK_CAMERA_COMMANDS_HPP__
#define __CG_COURSEWORK_CAMERA_COMMANDS_HPP__

#include <string>
#include <memory>
#include "commands/command.hpp"

class CameraCommand : public Command {};


class AddCamera : public CameraCommand {
public:
    AddCamera() = delete;

    AddCamera(float xPos, float yPos, float zPos);

    ~AddCamera() override = default;

    void execute() override;

private:
    float xPos, yPos, zPos;
};


//class LoadCamera : public CameraCommand {
//public:
//    explicit LoadCamera(std::string filename);
//
//    void execute() override;
//
//private:
//    std::string filename;
//};

class MoveCamera : public CameraCommand {
public:
    MoveCamera() = delete;

    MoveCamera(size_t cameraId, float shiftX, float shiftY, float shiftZ);

    ~MoveCamera() override = default;

    void execute() override;

private:
    size_t cameraId;
    float shiftX, shiftY, shiftZ;
};


class RemoveCamera : public CameraCommand {
public:
    RemoveCamera() = delete;

    explicit RemoveCamera(size_t cameraId);

    ~RemoveCamera() override = default;

    void execute() override;

private:
    size_t cameraId;
};

class SetCamera : public CameraCommand {
public:
    SetCamera() = delete;

    explicit SetCamera(size_t newCameraId);

    ~SetCamera() override = default;

    void execute() override;


private:
    size_t cameraId;
};


class GetLocation : public CameraCommand {
public:
    GetLocation() = delete;

    GetLocation(std::size_t camId, std::shared_ptr<float>& x, std::shared_ptr<float>& y, std::shared_ptr<float>& z) :
            x(x), y(y), z(z), camId(camId) {}

    ~GetLocation() override = default;

    void execute() override;

private:
    std::size_t camId;
    std::shared_ptr<float> &x;
    std::shared_ptr<float> &y;
    std::shared_ptr<float> &z;
};

//class CountCameras : public CameraCommand {
//public:
//    CountCameras() = delete;
//
//    explicit CountCameras(std::shared_ptr<std::size_t> &count);
//
//    ~CountCameras() override = default;
//
//    void execute() override;
//
//private:
//    std::shared_ptr<std::size_t> &count;
//};



#endif //__CG_COURSEWORK_CAMERA_COMMANDS_HPP__
