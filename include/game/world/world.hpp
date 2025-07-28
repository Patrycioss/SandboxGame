#pragma once
#include <vector>

#include "game/block.hpp"


class World final {
private:
std::vector<Block> blocks;

public:
    World();
    virtual ~World() = default;

    World(const World &) = delete;
    World(World &&) = delete;
    World &operator=(const World &) = delete;

    std::vector<Block> &getBlocks();
};
