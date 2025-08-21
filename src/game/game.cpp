#include <iostream>
#include <thread>
#include <game/game.hpp>
#include <game/world/world.hpp>

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
                   GameCameraMode::CAMERA_FREE,
                   100.0f,
                   0.1f
               )),
               input(std::make_unique<RaylibInput>()),
               randomGenerator(std::make_unique<RaylibRandomGenerator>(10.0f)) {
}

void Game::start() {
    window->init();

    Vec3 cubePosition{0.0f, 0.0f, 0.0f};
    Vec3 cubeSize{1.0f, 1.0f, 1.0f};
    Colour cubeColour{255, 0, 0, 255};
    Colour cubeWireColour{0, 0, 255, 255};
    Colour rectColour = {
        randomGenerator->getRandomInt(0, 256), randomGenerator->getRandomInt(0, 256),
        randomGenerator->getRandomInt(0, 256), 255
    };

    SetTargetFPS(250);

    World world{};

    RenderTexture2D renderTexture = LoadRenderTexture(window->getSize().x, window->getSize().y);

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

        BeginTextureMode(renderTexture);
        ClearBackground(RAYWHITE);
        camera->beginMode3D();

        const std::vector<Block> &blocks = world.getBlocks();
        size_t blockCount = blocks.size();
        for (int i = 0; i < blockCount; ++i) {
            const Vec3i pos = blocks[i].position;
            renderer->drawCube(pos, cubeSize, cubeColour);
            renderer->drawCubeWires(pos, cubeSize, cubeWireColour);
        }


        renderer->drawGrid(10, 1.0f);

        camera->endMode3D();
        EndTextureMode();


        renderer->beginRendering();

        DrawTextureRec(renderTexture.texture, (Rectangle){
                           0, 0, (float) renderTexture.texture.width, (float) -renderTexture.texture.height
                       }, {0, 0}, WHITE);

        renderer->drawRectangle({10, 10}, {320, 93}, rectColour);
        renderer->drawRectangleLines({10, 10}, {320, 93}, {255, 0, 0, 255});
        renderer->drawText("Free camera default controls:", {20, 20}, 10, {0, 0, 0, 255});

        DrawFPS(10, 10);

        renderer->endRendering();
    }
}
