#pragma once

class RandomGenerator {
public:
    RandomGenerator() = default;
    virtual ~RandomGenerator() = default;

    RandomGenerator(const RandomGenerator&) = delete;
    RandomGenerator(RandomGenerator&&) = default;
    RandomGenerator& operator=(const RandomGenerator&) = delete;

    virtual int getRandomInt(int minInclusive, int maxExclusive) = 0;
};