#include "Sort.hpp"

namespace SortAlgorithms
{
    // 選択ソート(オーダー = O(N^2))
    void SelectionSort(int *value, int length)
    {
        int swapCount = 0;

        std::cout << "Run Selection Sort" << std::endl;
        for (int i = 0; i < length - 1; i++) {
            for (int j = i + 1; j < length; j++) {
                if (value[i] > value[j]) {
                    Process::Swap(&value[i], &value[j]);
                    swapCount++;
                }
            }
            Process::ShowArray(value, length);
        }
        Process::ShowSwapCount(swapCount);
    }

    // バブルソート(オーダー = O(N^2))
    void BubbleSort(int *value, int length)
    {
        bool swapped;
        int swapCount = 0;

        std::cout << "Run Bubble Sort" << std::endl;
        for (int endIndex = length - 1; endIndex >= 1; endIndex--) {
            swapped = false;
            for (int i = 0; i < endIndex; i++) {
                if (value[i] > value[i + 1]) {
                    Process::Swap(&value[i], &value[i + 1]);
                    swapCount++;
                    swapped = true;
                }
            }
            if (!swapped) { break; }
            Process::ShowArray(value, length);
        }
        Process::ShowSwapCount(swapCount);
    }

    // 挿入ソート(オーダー = O(N^2))
    void InsertionsSort(int *value, int length)
    {
        bool swapped;
        int swapCount = 0;

        std::cout << "Run Insertions Sort" << std::endl;
        for (int i = 1; i < length; i++) {
            for (int j = i - 1; j >= 0; j--) {
                swapped = false;
                if (value[j] > value[j + 1]) {
                    Process::Swap(&value[j], &value[j + 1]);
                    swapCount++;
                    swapped = true;
                }
                if (!swapped) { break; }
            }
            Process::ShowArray(value, length);
        }
        Process::ShowSwapCount(swapCount);
    }

    // シェルソート(オーダー = O(N^2))
    void ShellSort(int *value, int length)
    {
        bool swapped;
        int h, groupNumber, swapCount = 0;

        std::cout << "Run Shell Sort" << std::endl;

        // 間隔hを決める
        for (h = 1; h <= length / 9; h = 3 * h + 1);

        // 間隔hが0になるまでループ
        do {
            // 間隔をあけて取り出したデータ列に挿入ソートを適用
            for (int i = h - 1; i < length - h; i += h) {
                swapped = false;
                for (int j = i, groupNumber = 1; j >= 0; j--, groupNumber++) {
                    if (value[j] > value[j + h]) {
                        Process::Swap(&value[j], &value[j + h]);
                        swapCount++;
                        swapped = true;
                    }
                    // 各グループごとの比較が、それぞれ一回ずつ行われた場合
                    if (groupNumber == h) {
                        // 交換が行われなかった場合、ループを抜ける
                        if (!swapped) { break; }
                        groupNumber = 0;
                        swapped = false;
                    }
                }
                Process::ShowArray(value, length);
            }

            // 間隔hを狭める
            h /= 3;
        } while (h > 0);
        Process::ShowSwapCount(swapCount);
    }

    // シェーカーソート
    void ShakerSort(int *value, int length)
    {
        int topIndex = 0;
        int endIndex = length - 1;
        int swapCount = 0;
        bool swapped;

        std::cout << "Run Shaker Sort" << std::endl;
        do {
            swapped = false;

            // 順方向のスキャン
            for (int i = topIndex; i < endIndex; i++) {
                if (value[i] > value[i + 1]) {
                    Process::Swap(&value[i], &value[i + 1]);
                    swapCount++;
                    swapped = true;
                }
            }

            // 逆方向のスキャン
            for (int i = endIndex - 2; i >= topIndex; i--) {
                if (value[i] > value[i + 1]) {
                    Process::Swap(&value[i], &value[i + 1]);
                    swapCount++;
                    swapped = true;
                }
            }
            if (swapped)
                Process::ShowArray(value, length);

            // スキャン範囲を狭める
            topIndex++;
            endIndex--;
        } while (topIndex < endIndex && swapped);
        Process::ShowSwapCount(swapCount);
    }
}