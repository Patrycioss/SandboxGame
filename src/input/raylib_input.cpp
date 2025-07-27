#include "input/raylib_input.hpp"

#include "raylib.h"

bool RaylibInput::isKeyPressed(Key key) {
    return IsKeyPressed(static_cast<KeyboardKey>(key));
}

bool RaylibInput::isKeyDown(Key key) {
    return IsKeyDown(static_cast<KeyboardKey>(key));
}

bool RaylibInput::isKeyReleased(Key key) {
    return IsKeyReleased(static_cast<KeyboardKey>(key));
}

bool RaylibInput::isMouseButtonPressed(Mouse button) {
    return IsMouseButtonPressed(static_cast<MouseButton>(button));
}

bool RaylibInput::isMouseButtonDown(Mouse button) {
    return IsMouseButtonDown(static_cast<MouseButton>(button));
}

bool RaylibInput::isMouseButtonReleased(Mouse button) {
    return IsMouseButtonReleased(static_cast<MouseButton>(button));
}

int RaylibInput::getMouseX() {
    return GetMouseX();
}

int RaylibInput::getMouseY() {
    return GetMouseY();
}

Vec2i RaylibInput::getMousePosition() {
    return {GetMouseX(), GetMouseY()};
}

Vec2 RaylibInput::getMousePositionF() {
    return {static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY())};
}
