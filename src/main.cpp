#include "SortAlgorithms.hpp"
#include <chrono>

int main(void)
{
    using namespace SortAlgorithms;
    int data[54], mode;
    const int dataSize = sizeof(data) / sizeof(int);
    std::chrono::system_clock::time_point start, end;

    // 整列用の乱数を生成する
    for (int i = 0; i != dataSize; ++i)
        data[i] = Utils::random(0, dataSize);
    
    std::cout << "Sort mode? ";
    std::cin >> mode;

    // 計測開始時間
    start = std::chrono::system_clock::now();
    switch (mode) {
        case 0:
            // 選択ソート
            Sort::selectionSort(data, dataSize);
            break;
        case 1:
            // バブルソート
            Sort::bubbleSort(data, dataSize);
            break;
        case 2:
            // 挿入ソート
            Sort::insertionsSort(data, dataSize);
            break;
        case 3:
            // シェルソート
            Sort::shellSort(data, dataSize);
            break;
        case 4:
            // マージソート
            Sort::mergeSort(data, dataSize);
            break;
        case 5:
            // クイックソート
            Sort::quickSort(data, dataSize);
            break;
        case 6:
            // ヒープソート
            Sort::heapSort(data, dataSize);
            break;
        case 7:
            // シェーカーソート
            Sort::shakerSort(data, dataSize);
    }

    // 計測終了時間
    end = std::chrono::system_clock::now();

    // 処理に要した時間をミリ秒に変換
    double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();

    std::cout << elapsed << "ms" << std::endl;
    system("PAUSE");
    return 0;
}