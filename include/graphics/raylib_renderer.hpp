#pragma once
#include <raylib.h>

#include "data/vec2i.hpp"
#include "graphics/renderer.hpp"

class RaylibRenderer final : public Renderer {
private:
    Color clearColor;

public:
    explicit RaylibRenderer(const Colour &clearColour = {255, 255, 255, 255});
    ~RaylibRenderer() override;

    RaylibRenderer(const RaylibRenderer &other) = delete;
    RaylibRenderer(RaylibRenderer &&other) = delete;
    RaylibRenderer &operator=(const RaylibRenderer &other) = delete;

    void beginRendering() override;
    void endRendering() override;

    void setClearColour(const Colour &colour) override;
    void drawCube(const Vec3 &position, const Vec3 &size, const Colour &colour) override;
    void drawCubeWires(const Vec3 &position, const Vec3 &size, const Colour &colour) override;
    void drawGrid(int slices, float spacing) override;
    void drawRectangle(const Vec2i &position, const Vec2i &size, const Colour &colour) override;
    void drawRectangleLines(const Vec2i &position, const Vec2i &size, const Colour &colour) override;
    void drawText(const std::string &text, const Vec2i &position, int textSize, const Colour &colour) override;
};
