#include <game/world/world.hpp>


World::World() {
    constexpr int width = 100;
    constexpr int hWidth = width/2;
    blocks.reserve(width * width);

    // blocks.push_back({{0,0,0}});
    // blocks.push_back({{0,0,1}});
    // blocks.push_back({{1,0,0}});
    // blocks.push_back({{0,5,3}});
    // blocks.push_back({{22,0,0}});

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < width; ++j) {
            blocks.push_back({Vec3i{i-hWidth, 0, j-hWidth}});
        }
    }
}

std::vector<Block> & World::getBlocks() {
    return blocks;
}
