#include <graphics/raylib_renderer.hpp>

#include <raylib.h>

#include "raylib_utility/raylib_conversions.hpp"


RaylibRenderer::RaylibRenderer(const Colour &clearColour) : clearColor(ColourToRaylibColor(clearColour)) {
}

RaylibRenderer::~RaylibRenderer() = default;

void RaylibRenderer::beginRendering() {
    BeginDrawing();
    ClearBackground(clearColor);
}

void RaylibRenderer::endRendering() {
    EndDrawing();
}

void RaylibRenderer::setClearColour(const Colour &colour) {
    clearColor = ColourToRaylibColor(colour);
}

void RaylibRenderer::drawCube(const Vec3 &position, const Vec3 &size, const Colour &colour) {
    DrawCube(Vec3ToRaylibVector3(position), size.x, size.y, size.z, ColourToRaylibColor(colour));
}

void RaylibRenderer::drawCubeWires(const Vec3 &position, const Vec3 &size, const Colour &colour) {
    DrawCubeWires(Vec3ToRaylibVector3(position), size.x, size.y, size.z, ColourToRaylibColor(colour));
}

void RaylibRenderer::drawGrid(const int slices, const float spacing) {
    DrawGrid(slices, spacing);
}

void RaylibRenderer::drawRectangle(const Vec2i& position, const Vec2i& size, const Colour &colour) {
    DrawRectangle(position.x, position.y, size.x, size.y, ColourToRaylibColor(colour));
}

void RaylibRenderer::drawRectangleLines(const Vec2i& position, const Vec2i& size, const Colour &colour) {
    DrawRectangleLines(position.x, position.y, size.x, size.y, ColourToRaylibColor(colour));
}

void RaylibRenderer::drawText(const std::string &text, const Vec2i &position, const int textSize, const Colour &colour) {
    DrawText(text.c_str(), position.x, position.y, textSize, ColourToRaylibColor(colour));
}
