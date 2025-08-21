#pragma once
#include "plane.hpp"
#include "engine/graphics/game_camera.hpp"

struct Frustum {
    Plane topFace;
    Plane bottomFace;

    Plane rightFace;
    Plane leftFace;

    Plane farFace;
    Plane nearFace;

    static Frustum createFromGameCamera(GameCamera& camera) {
        Frustum frustum;


        const float near = camera.getNear();
        const float far = camera.getFar();
        const float fov = camera.getFov();
        const Vec3 front = camera.

        const float halfVSide = camera.getFar() * tanf(camera.getFov() * .5f);
        const float halfHSide = halfVSide * aspect;
        const glm::vec3 frontMultFar = zFar * cam.Front;

        frustum.nearFace = { cam.Position + zNear * cam.Front, cam.Front };
        frustum.farFace = { cam.Position + frontMultFar, -cam.Front };
        frustum.rightFace = { cam.Position,
                                glm::cross(frontMultFar - cam.Right * halfHSide, cam.Up) };
        frustum.leftFace = { cam.Position,
                                glm::cross(cam.Up,frontMultFar + cam.Right * halfHSide) };
        frustum.topFace = { cam.Position,
                                glm::cross(cam.Right, frontMultFar - cam.Up * halfVSide) };
        frustum.bottomFace = { cam.Position,
                                glm::cross(frontMultFar + cam.Up * halfVSide, cam.Right) };

        return frustum;
    }
};
