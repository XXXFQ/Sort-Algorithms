#include "SortAlgorithms.hpp"

int main(void)
{
    using namespace SortAlgorithms;
    int data[54], mode;
    const int dataSize = sizeof(data) / sizeof(int);

    //  整列用の乱数を生成する
    for (int i = 0; i != dataSize; ++i)
        data[i] = Utils::Random(0, dataSize);
    
    std::cout << "Sort mode? ";
    std::cin >> mode;

    switch (mode) {
        case 0:
            // 選択ソート
            Sort::SelectionSort(data, dataSize);
            break;
        case 1:
            // バブルソート
            Sort::BubbleSort(data, dataSize);
            break;
        case 2:
            // 挿入ソート
            Sort::InsertionsSort(data, dataSize);
            break;
        case 3:
            // シェルソート
            Sort::ShellSort(data, dataSize);
            break;
        case 4:
            // マージソート
            Sort::MergeSort(data, dataSize);
            break;
        case 5:
            // クイックソート
            Sort::QuickSort(data, dataSize);
            break;
        case 6:
            // ヒープソート
            Sort::HeapSort(data, dataSize);
            break;
        case 7:
            // シェーカーソート
            Sort::ShakerSort(data, dataSize);
    }
    system("PAUSE");
    return 0;
}