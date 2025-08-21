#pragma once
#include <raylib.h>
#include "game_camera.hpp"

class RaylibGameCamera final : public GameCamera {
private:
    Camera3D camera;
    CameraMode mode;
    float far;
    float near;

public:
    RaylibGameCamera(
        const Vec3 &position,
        const Vec3 &target,
        const Vec3 &up,
        float fov,
        GameCameraMode mode,
        float far,
        float near
    );
    ~RaylibGameCamera() override;

    RaylibGameCamera(const RaylibGameCamera &) = delete;
    RaylibGameCamera(RaylibGameCamera &&) = delete;
    RaylibGameCamera &operator=(const RaylibGameCamera &) = delete;

    void setCameraMode(GameCameraMode mode) override;
    void Update() override;
    void beginMode3D() override;
    void endMode3D() override;

    void setPosition(const Vec3 &position) override;
    void setTarget(const Vec3 &target) override;
    void setFov(float fov) override;
    void setFar(float far) override;
    void setNear(float near) override;

    [[nodiscard]] Vec3 getPosition() const override;
    [[nodiscard]] Vec3 getTarget() const override;
    [[nodiscard]] Vec3 getUp() const override;
    [[nodiscard]] Vec3 getFront() const override;
    [[nodiscard]] float getFov() const override;
    [[nodiscard]] float getFar() const override;
    [[nodiscard]] float getNear() const override;
};
