#pragma once
#include "key.hpp"
#include "mouse.hpp"
#include "engine/data/vec2.hpp"
#include "engine/data/vec2i.hpp"

class Input {
public:
    Input() = default;
    virtual ~Input() = default;

    Input(const Input &) = delete;
    Input(Input &&) = delete;
    Input &operator=(const Input &) = delete;

    virtual bool isKeyPressed(Key key) = 0;
    virtual bool isKeyDown(Key key) = 0;
    virtual bool isKeyReleased(Key key) = 0;

    virtual bool isMouseButtonPressed(Mouse button) = 0;
    virtual bool isMouseButtonDown(Mouse button) = 0;
    virtual bool isMouseButtonReleased(Mouse button) = 0;

    virtual int getMouseX() = 0;
    virtual int getMouseY() = 0;
    virtual Vec2i getMousePosition() = 0;
    virtual Vec2 getMousePositionF() = 0;
};
