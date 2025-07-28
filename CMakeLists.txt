cmake_minimum_required(VERSION 3.30)
project(SandboxGame LANGUAGES CXX)
include(FetchContent)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games

FetchContent_Declare(
        raylib
        GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
        GIT_TAG "master"
        GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(raylib)

set(SOURCES
        main.cpp
        src/engine/window/raylib_window.cpp
        src/engine/graphics/raylib_renderer.cpp
        src/engine/graphics/raylib_game_camera.cpp
        src/engine/utils/raylib_random_generator.cpp
        src/engine/input/raylib_input.cpp
        src/game/game.cpp
        src/game/game.hpp
)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

target_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/")
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE include)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE raylib)
