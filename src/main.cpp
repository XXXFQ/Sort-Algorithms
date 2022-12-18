#include "Sort.hpp"

int main(void)
{
    using namespace SortAlgorithms;
    /*
    std::vector<int> data = {
        44, 100, 5, 31, 200, 4, 2, 10, 6, 7, 66, 74, 20,
        56, 89, 1, 77, 204, 53, 102, 54, 3, 76, 8
    };
    int dataSize = data.size();
    */

   int data[54];
   const int dataSize = sizeof(data) / sizeof(int);
   for (int i = 0; i < dataSize; i++)
        data[i] = 54 - i;

    int mode;

    std::cout << "Sort mode? ";
    std::cin >> mode;

    switch (mode) {
        case 0:
            // 選択ソート
            SelectionSort(data, dataSize);
            break;
        case 1:
            // バブルソート
            BubbleSort(data, dataSize);
            break;
        case 2:
            // 挿入ソート
            InsertionsSort(data, dataSize);
            break;
        case 3:
            // シェルソート
            ShellSort(data, dataSize);
            break;
        case 4:
            // マージソート
            MergeSort(data, dataSize);
            break;
        case 5:
            // クイックソート
            QuickSort(data, dataSize);
            break;
        case 6:
            // ヒープソート
            HeapSort(data, dataSize);
            break;
        case 7:
            // シェーカーソート
            ShakerSort(data, dataSize);
    }
    system("PAUSE");
    return 0;
}