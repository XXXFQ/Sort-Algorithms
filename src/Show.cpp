#include <iostream>
#include <random>
#include <chrono>
#include "SortAlgorithms/Show.hpp"

namespace SortAlgorithms
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
    void Show::array(int *array, int Start, int length)
    {
        for (int i = Start; i < length; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
}