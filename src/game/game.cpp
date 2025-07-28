#include "game.hpp"

#include "engine/graphics/game_camera.hpp"
#include "engine/graphics/raylib_game_camera.hpp"
#include "engine/graphics/raylib_renderer.hpp"
#include "engine/input/raylib_input.hpp"
#include "engine/utils/raylib_random_generator.hpp"
#include "engine/window/raylib_window.hpp"

Game::Game() : window(std::make_unique<RaylibWindow>(800, 600, "Hello World!")),
               renderer(std::make_unique<RaylibRenderer>()),
               camera(std::make_unique<RaylibGameCamera>(
                   Vec3{10.0f, 10.0f, 10.0f},
                   Vec3{0.0f, 0.0f, 0.0f},
                   Vec3{0.0f, 1.0f, 0.0f},
                   45.0f,
                   GameCameraMode::CAMERA_FREE
               )),
               input(std::make_unique<RaylibInput>()),
               randomGenerator(std::make_unique<RaylibRandomGenerator>(10.0f)) {
}

void Game::start() {
    window->init();

    Vec3 cubePosition{0.0f, 0.0f, 0.0f};
    Vec3 cubeSize{2.0f, 2.0f, 2.0f};
    Colour cubeColour{255, 0, 0, 255};
    Colour cubeWireColour{0, 0, 0, 255};
    Colour rectColour = {
        randomGenerator->getRandomInt(0, 256), randomGenerator->getRandomInt(0, 256),
        randomGenerator->getRandomInt(0, 256), 255
    };

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

        renderer->drawRectangle({10, 10}, {320, 93}, rectColour);
        renderer->drawRectangleLines({10, 10}, {320, 93}, {255, 0, 0, 255});
        renderer->drawText("Free camera default controls:", {20, 20}, 10, {0, 0, 0, 255});

        DrawFPS(10, 10);

        renderer->endRendering();
    }
}
