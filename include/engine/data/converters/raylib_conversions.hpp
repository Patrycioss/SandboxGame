#pragma once
#include <raylib.h>

#include "../colour.hpp"
#include "engine/data/rect.hpp"
#include "engine/data/vec3.hpp"
#include "engine/graphics/game_camera_mode.hpp"

inline Color ColourToRaylibColor(const Colour &colour) {
    return Color(colour.r, colour.g, colour.b, colour.a);
}

inline Colour RaylibColorToColour(const Color &colour) {
    return Colour(colour.r, colour.g, colour.b, colour.a);
}

inline Vector3 Vec3ToRaylibVector3(const Vec3 &vector) {
    return Vector3(vector.x, vector.y, vector.z);
}

inline Vec3 RaylibVector3ToVec3(const Vector3 &vector) {
    return Vec3(vector.x, vector.y, vector.z);
}

inline CameraMode GameCameraModeToRaylibCameraMode(const GameCameraMode mode) {
    switch (mode){
        case GameCameraMode::CAMERA_FREE:
            return CAMERA_FREE;
        case GameCameraMode::CAMERA_FIRST_PERSON:
            return CAMERA_FIRST_PERSON;
        case GameCameraMode::CAMERA_THIRD_PERSON:
            return CAMERA_THIRD_PERSON;
        case GameCameraMode::CAMERA_ORBITAL:
            return CAMERA_ORBITAL;
        case GameCameraMode::CUSTOM:
            return CAMERA_CUSTOM;
    }
    return CAMERA_CUSTOM;
}

inline GameCameraMode RaylibCameraModeToGameCameraMode(const CameraMode mode) {
    switch (mode){
        case CAMERA_CUSTOM:
            return GameCameraMode::CUSTOM;
        case CAMERA_FREE:
            return GameCameraMode::CAMERA_FREE;
        case CAMERA_ORBITAL:
            return GameCameraMode::CAMERA_ORBITAL;
        case CAMERA_FIRST_PERSON:
            return GameCameraMode::CAMERA_FIRST_PERSON;
        case CAMERA_THIRD_PERSON:
            return GameCameraMode::CAMERA_THIRD_PERSON;
    }
    return GameCameraMode::CUSTOM;
}

inline Rectangle RectToRaylibRectangle(const Rect& rect) {
    return Rectangle(rect.x, rect.y, rect.width, rect.height);
}

inline Rect RaylibRectangleToRect(const Rectangle& rectangle) {
    return Rect(rectangle.x, rectangle.y, rectangle.width, rectangle.height);
}
