#pragma once
#include "random_generator.hpp"

class RaylibRandomGenerator final : public RandomGenerator {
public:
    explicit RaylibRandomGenerator(unsigned int seed);
    ~RaylibRandomGenerator() override = default;

    RaylibRandomGenerator(const RaylibRandomGenerator &) = delete;
    RaylibRandomGenerator(RaylibRandomGenerator &&) = delete;
    RaylibRandomGenerator &operator=(const RaylibRandomGenerator &) = delete;

    int getRandomInt(int minInclusive, int maxExclusive) override;
};
