#pragma once
#include <string>

#include <window/window.hpp>


class RaylibWindow final : public Window {
private:
    int width;
    int height;
    std::string title;

public:
    RaylibWindow(int width, int height, std::string title);
    ~RaylibWindow() override;

    RaylibWindow(const RaylibWindow&) = delete;
    RaylibWindow(RaylibWindow&&) = delete;
    RaylibWindow& operator=(const RaylibWindow&) = delete;

    void init() override;

    int getWidth() override;
    int getHeight() override;
    Vec2 getSize() override;
};
