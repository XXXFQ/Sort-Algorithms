#include <chrono>

#include "sort_algorithms.hpp"

int main(void)
{
    using namespace sort_algorithms;
    int data[54], mode;
    size_t data_size = sizeof(data) / sizeof(int);
    std::chrono::system_clock::time_point start, end;

    // 整列用の乱数を生成する
    for (int i = 0; i != data_size; ++i)  {
        data[i] = Utils::random(0, data_size);
    }

    std::cout << "Sort mode? ";
    std::cin >> mode;

    // 計測開始時間
    start = std::chrono::system_clock::now();
    switch (mode) {
        case 0:
            // 選択ソート
            Sort::selection_sort(data, data_size);
            break;
        case 1:
            // バブルソート
            Sort::bubble_sort(data, data_size);
            break;
        case 2:
            // 挿入ソート
            Sort::insertions_sort(data, data_size);
            break;
        case 3:
            // シェルソート
            Sort::shell_sort(data, data_size);
            break;
        case 4:
            // マージソート
            Sort::merge_sort(data, data_size);
            break;
        case 5:
            // クイックソート
            Sort::quick_sort(data, data_size);
            break;
        case 6:
            // ヒープソート
            Sort::heap_sort(data, data_size);
            break;
        case 7:
            // シェーカーソート
            Sort::shaker_sort(data, data_size);
            break;
    }

    // 計測終了時間
    end = std::chrono::system_clock::now();

    // 処理に要した時間をミリ秒に変換
    double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();

    std::cout << elapsed << "ms" << std::endl;
    system("PAUSE");
    return 0;
}