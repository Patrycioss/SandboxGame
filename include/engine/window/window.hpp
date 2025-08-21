#pragma once
#include "engine/data/vec2i.hpp"

class Window {
public:
    Window() = default;
    virtual ~Window() = default;

    Window(const Window &&window) = delete;
    Window(const Window &window) = delete;
    Window &operator=(const Window &window) = delete;

    virtual void init() = 0;

    virtual int getWidth() = 0;
    virtual int getHeight() = 0;
    virtual Vec2i getSize() = 0;
};
