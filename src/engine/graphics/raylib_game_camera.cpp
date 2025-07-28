#include <engine/graphics/raylib_game_camera.hpp>

#include "raylib.h"
#include "engine/data/converters/raylib_conversions.hpp"

RaylibGameCamera::RaylibGameCamera(
    const Vec3 &position,
    const Vec3 &target,
    const Vec3 &up,
    const float fov,
    const GameCameraMode mode
) : camera(Vec3ToRaylibVector3(position),
           Vec3ToRaylibVector3(target),
           Vec3ToRaylibVector3(up)
    ),
    mode(GameCameraModeToRaylibCameraMode(mode)) {
    camera.fovy = fov;
    camera.projection = CAMERA_PERSPECTIVE;
}

RaylibGameCamera::~RaylibGameCamera() = default;

void RaylibGameCamera::setCameraMode(const GameCameraMode mode) {
    this->mode = GameCameraModeToRaylibCameraMode(mode);
}

void RaylibGameCamera::Update() {
    UpdateCamera(&camera, mode);
}

void RaylibGameCamera::beginMode3D() {
    BeginMode3D(camera);
}

void RaylibGameCamera::endMode3D() {
    EndMode3D();
}

void RaylibGameCamera::setPosition(const Vec3 &position) {
    camera.position = Vec3ToRaylibVector3(position);
}

void RaylibGameCamera::setTarget(const Vec3 &target) {
    camera.target = Vec3ToRaylibVector3(target);
}

void RaylibGameCamera::setFov(const float fov) {
    camera.fovy = fov;
}

Vec3 RaylibGameCamera::getPosition() const {
    return RaylibVector3ToVec3(camera.position);
}

Vec3 RaylibGameCamera::getTarget() const {
    return RaylibVector3ToVec3(camera.target);
}

float RaylibGameCamera::getFov() const {
    return camera.fovy;
}
