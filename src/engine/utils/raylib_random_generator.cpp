#include <raylib.h>

#include "engine/utils/raylib_random_generator.hpp"

RaylibRandomGenerator::RaylibRandomGenerator(const unsigned int seed) {
    SetRandomSeed(seed);
}

int RaylibRandomGenerator::getRandomInt(const int minInclusive, const int maxExclusive) {
    return GetRandomValue(minInclusive, maxExclusive);
}
