#include <iostream>
#include <random>
#include <chrono>
#include "SortAlgorithms/Utils.hpp"

namespace SortAlgorithms
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine gen(seed);

    // 指定された範囲のランダムな数値を生成
    int Utils::Random(int low, int high)
    {
        std::uniform_int_distribution<> dist(low, high);
        return dist(gen);
    }

    // 値の交換
    void Utils::Swap(int *x, int *y)
    {
        int swap = *x;
        *x = *y;
        *y = swap;
    }
}