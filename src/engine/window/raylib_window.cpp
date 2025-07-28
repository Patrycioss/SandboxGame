#include <engine/window/raylib_window.hpp>

#include <raylib.h>
#include <string>

RaylibWindow::RaylibWindow(const int width, const int height, std::string  title): width(width), height(height), title(std::move(title)) {
}

RaylibWindow::~RaylibWindow() {
    CloseWindow();
}

void RaylibWindow::init() {
    InitWindow(width, height, title.c_str());
}

int RaylibWindow::getWidth() {
    return width;
}

int RaylibWindow::getHeight() {
    return height;
}

Vec2 RaylibWindow::getSize() {
    return Vec2{static_cast<float>(width), static_cast<float>(height)};
}


