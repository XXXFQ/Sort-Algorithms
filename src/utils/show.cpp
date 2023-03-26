#include <iostream>
#include <random>
#include <chrono>

#include "sort_algorithms/utils/show.hpp"

namespace sort_algorithms
{
    // 配列のデータ表示
    void Show::array(int *array, int length)
    {
        for (int i = 0; i < length; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }

    // 配列のデータ表示(開始値を設定できる)
    void Show::array(int *array, int start, int length)
    {
        for (int i = start; i < length; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
}