#include <memory>
#include <raylib.h>

#include "window/raylib_window.hpp"
#include "graphics/raylib_renderer.hpp"
#include "graphics/raylib_game_camera.hpp"
#include "raylib_utility/raylib_conversions.hpp"

int main() {

    const std::unique_ptr<Window> window = std::make_unique<RaylibWindow>(800, 600, "Hello World!");
    window->init();

    const std::unique_ptr<Renderer> renderer = std::make_unique<RaylibRenderer>();

    const std::unique_ptr<GameCamera> camera = std::make_unique<RaylibGameCamera>(
        Vec3{10.0f, 10.0f, 10.0f},
        Vec3{0.0f, 0.0f, 0.0f},
        Vec3{0.0f, 1.0f, 0.0f},
        45.0f
    );

    Vec3 cubePosition{0.0f, 0.0f, 0.0f};
    Vec3 cubeSize{2.0f, 2.0f, 2.0f};
    Colour cubeColour{255, 0, 0, 255};
    Colour cubeWireColour{0, 0, 0, 255};

    SetTargetFPS(180);

    while (!WindowShouldClose()) {
        camera->Update();

        renderer->beginRendering();
        camera->beginMode3D();

        renderer->drawCube(cubePosition, cubeSize, cubeColour);
        renderer->drawCubeWires(cubePosition, cubeSize, cubeWireColour);
        renderer->drawGrid(10, 1.0f);
        camera->endMode3D();

        renderer->drawRectangle({10,10}, {320, 93}, {0,0,255,255});
        renderer->drawRectangleLines({10,10}, {320, 93}, {255,0,0,255});
        renderer->drawText("Free camera default controls:", {20, 20}, 10, {0,0,0,255});

        renderer->endRendering();
    }

    return 0;
}
