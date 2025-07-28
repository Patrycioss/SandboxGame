#include <game/world/world.hpp>


World::World() {
    constexpr int width = 100;
    constexpr int hWidth = width/2;
    blocks.reserve(width * width);

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < width; ++j) {
            blocks.push_back({Vec3i{i-hWidth, 0, j-hWidth}});
        }
    }
}

std::vector<Block> & World::getBlocks() {
    return blocks;
}
