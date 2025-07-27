#pragma once
#include "input.hpp"


class RaylibInput : public Input {
public:
    RaylibInput() = default;
    ~RaylibInput() override = default;

    RaylibInput(const RaylibInput &) = delete;
    RaylibInput(RaylibInput &&) = delete;
    RaylibInput &operator=(const RaylibInput &) = delete;

    bool isKeyPressed(Key key) override;
    bool isKeyDown(Key key) override;
    bool isKeyReleased(Key key) override;

    bool isMouseButtonPressed(Mouse button) override;
    bool isMouseButtonDown(Mouse button) override;
    bool isMouseButtonReleased(Mouse button) override;

    int getMouseX() override;
    int getMouseY() override;
    Vec2i getMousePosition() override;
    Vec2 getMousePositionF() override;
};
