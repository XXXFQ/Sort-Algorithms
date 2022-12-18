#include <iostream>
#include "Process.hpp"

namespace Process
{
    // 配列のデータ表示
    void ShowArray(int *array, int length)
    {
        for (int i = 0; i < length; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }

    // 配列のデータ表示(開始値を設定できる)
    void ShowArray(int *array, int Start, int length)
    {
        for (int i = Start; i < length; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }

    // 値の交換
    void Swap(int *x, int *y)
    {
        int swap = *x;
        *x = *y;
        *y = swap;
    }
}