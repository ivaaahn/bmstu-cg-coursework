//
// Created by ivaaahn on 07.09.2021.
//

#ifndef __CG_COURSEWORK_CAMERA_COMMANDS_HPP__
#define __CG_COURSEWORK_CAMERA_COMMANDS_HPP__

#include <string>
#include <memory>

#include "commands/command.hpp"

#include "math/linalg.hpp"

using namespace linalg::aliases;

class CameraCommand : public Command {};


class AddCamera : public CameraCommand {
public:
    AddCamera() = delete;

    AddCamera(const float3& cords);

    ~AddCamera() override = default;

    void execute() override;

private:
    float3 cords;
};


class MoveCamera : public CameraCommand {
public:
    MoveCamera() = delete;

    MoveCamera(size_t cameraId, const float3& cords);

    ~MoveCamera() override = default;

    void execute() override;

private:
    size_t cameraId;
    float3 cords;
};

class RotateCamera : public CameraCommand {
public:
    RotateCamera() = delete;

    RotateCamera(size_t camId, const int2& angles) : camId(camId), angles(angles) {}

    ~RotateCamera() override = default;

    void execute() override;

private:
    size_t camId;
    int2 angles;
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


class GetCameraInfo : public CameraCommand {
public:
    GetCameraInfo() = delete;

    GetCameraInfo(size_t camId, std::shared_ptr<float3>& pos, std::shared_ptr<int2>& angles,
                  std::shared_ptr<int>& fov) :
            camId(camId), pos(pos), angles(angles), fov(fov) {}

    ~GetCameraInfo() override = default;

    void execute() override;

private:
    size_t camId;
    std::shared_ptr<float3> pos;
    std::shared_ptr<int2> angles;
    std::shared_ptr<int> fov;
};

class SetCameraFov : public CameraCommand {
public:
    SetCameraFov() = delete;

    SetCameraFov(size_t camId, int fov) :
            camId(camId), fov(fov) {}

    ~SetCameraFov() override = default;

    void execute() override;

private:
    size_t camId;
    int fov;
};


#endif //__CG_COURSEWORK_CAMERA_COMMANDS_HPP__
