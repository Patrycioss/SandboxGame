#include <memory>
#include <raylib.h>

#include "window/raylib_window.hpp"
#include "graphics/raylib_renderer.hpp"
#include "graphics/raylib_game_camera.hpp"
#include "input/input.hpp"
#include "input/raylib_input.hpp"
#include "utils/random_generator.hpp"
#include "utils/raylib_random_generator.hpp"

static RandomGenerator* randomGenerator = new RaylibRandomGenerator(10);

int main() {

    const std::unique_ptr<Window> window = std::make_unique<RaylibWindow>(800, 600, "Hello World!");
    window->init();

    const std::unique_ptr<Renderer> renderer = std::make_unique<RaylibRenderer>();

    const std::unique_ptr<GameCamera> camera = std::make_unique<RaylibGameCamera>(
        Vec3{10.0f, 10.0f, 10.0f},
        Vec3{0.0f, 0.0f, 0.0f},
        Vec3{0.0f, 1.0f, 0.0f},
        45.0f,
        GameCameraMode::CAMERA_FREE
    );

    const std::unique_ptr<Input> input = std::make_unique<RaylibInput>();

    Vec3 cubePosition{0.0f, 0.0f, 0.0f};
    Vec3 cubeSize{2.0f, 2.0f, 2.0f};
    Colour cubeColour{255, 0, 0, 255};
    Colour cubeWireColour{0, 0, 0, 255};
    Colour rectColour = {randomGenerator->getRandomInt(0,256), randomGenerator->getRandomInt(0,256), randomGenerator->getRandomInt(0,256), 255};

    SetTargetFPS(250);

    while (!WindowShouldClose()) {
        if (input->isKeyDown(Key::R)) {
            cubeColour.r = randomGenerator->getRandomInt(0, 255);
        }

        if (input->isKeyDown(Key::G)) {
            cubeColour.g = randomGenerator->getRandomInt(0, 255);
        }

        if (input->isKeyPressed(Key::B)) {
            cubeColour.b = randomGenerator->getRandomInt(0, 255);
        }

        camera->Update();


        renderer->beginRendering();
        camera->beginMode3D();

        renderer->drawCube(cubePosition, cubeSize, cubeColour);
        renderer->drawCubeWires(cubePosition, cubeSize, cubeWireColour);
        renderer->drawGrid(10, 1.0f);
        camera->endMode3D();

        renderer->drawRectangle({10,10}, {320, 93}, rectColour);
        renderer->drawRectangleLines({10,10}, {320, 93}, {255,0,0,255});
        renderer->drawText("Free camera default controls:", {20, 20}, 10, {0,0,0,255});

        DrawFPS(10, 10);

        renderer->endRendering();
    }

    delete randomGenerator;
    return 0;
}
