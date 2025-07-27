#pragma once
#include "data/vec3.hpp"
#include "game_camera_mode.hpp"

class GameCamera {
public:
    GameCamera() = default;
    virtual ~GameCamera() = default;

    GameCamera(const GameCamera &camera) = delete;
    GameCamera &operator=(const GameCamera &camera) = delete;
    GameCamera(GameCamera &&camera) = delete;

    virtual void setCameraMode(GameCameraMode mode) = 0;
    virtual void Update() = 0;
    virtual void beginMode3D() = 0;
    virtual void endMode3D() = 0;

    virtual void setPosition(const Vec3 &position) = 0;
    virtual void setTarget(const Vec3 &target) = 0;
    virtual void setFov(float fov) = 0;

    [[nodiscard]] virtual Vec3 getPosition() const = 0;
    [[nodiscard]] virtual Vec3 getTarget() const = 0;
    [[nodiscard]] virtual float getFov() const = 0;
};
