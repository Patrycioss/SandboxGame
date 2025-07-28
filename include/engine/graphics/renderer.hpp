#pragma once
#include <string>

#include "../data/colour.hpp"
#include "engine/data/vec3.hpp"
#include "engine/data/vec2i.hpp"

class Renderer {
public:
    Renderer() = default;
    virtual ~Renderer() = default;

    Renderer(const Renderer &) = delete;
    Renderer(Renderer &&) = delete;
    Renderer &operator=(const Renderer &) = delete;

    virtual void beginRendering() = 0;
    virtual void endRendering() = 0;
    virtual void setClearColour(const Colour& colour) = 0;

    virtual void drawCube(const Vec3& position, const Vec3& size, const Colour& colour) = 0;
    virtual void drawCubeWires(const Vec3& position, const Vec3& size, const Colour& colour) = 0;
    virtual void drawGrid(int slices, float spacing) = 0;

    virtual void drawRectangle(const Vec2i& position, const Vec2i& size, const Colour& colour) = 0;
    virtual void drawRectangleLines(const Vec2i& position, const Vec2i& size, const Colour& colour) = 0;
    virtual void drawText(const std::string& text, const Vec2i& position, int textSize, const Colour& colour) = 0;
};
