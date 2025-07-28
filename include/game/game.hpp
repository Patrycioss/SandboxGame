#pragma once
#include <memory>

#include "engine/graphics/game_camera.hpp"
#include "engine/graphics/renderer.hpp"
#include "engine/input/input.hpp"
#include "engine/utils/random_generator.hpp"
#include "engine/window/window.hpp"


class Game final {
private:
    std::unique_ptr<Window> window;
    std::unique_ptr<Renderer> renderer;
    std::unique_ptr<GameCamera> camera;
    std::unique_ptr<Input> input;
    std::unique_ptr<RandomGenerator> randomGenerator;

public:
    Game();
    ~Game() = default;

    Game(const Game &) = delete;
    Game(Game &&) = delete;
    Game &operator=(const Game &) = delete;

    void start();
};
