/* by stanford */
#pragma once

#include <array>
#include <unordered_map>
#include <string>
#include "config.hpp"

using LeakMap = std::unordered_map<short, float>;


class LeakCounter {
public:
    LeakCounter();
    ~LeakCounter() = default;

    float CountLeak(int ionsCount, float angle);

private:
    bool MakeLeakTable(
        const std::string filename,
        std::array<LeakMap, maxCrossingsCount> &leaks
    );
    std::array<LeakMap, maxCrossingsCount> flatLeaks;
    std::array<LeakMap, maxCrossingsCount> stairLeaks;
};
