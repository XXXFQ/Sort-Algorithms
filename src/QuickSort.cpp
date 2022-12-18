#include "Sort.hpp"

namespace SortAlgorithms
{
    void QuickSort(int *value, int leftIndex, int rightIndex)
    {
        int i, j, pivot;
        int tempIndex[] = { leftIndex, rightIndex / 2, rightIndex };

        // 分割されたデータ列の値が1個の場合、それを返す。
        if (leftIndex >= rightIndex) { return; }
        
        // データ列[value]の先頭/中央/末尾の3つの値の中央値を基準値とする
        for (int i = 1; i < 3; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (value[tempIndex[j]] > value[tempIndex[j + 1]]) {
                    Process::Swap(&tempIndex[j], &tempIndex[j + 1]);
                }
            }
        }

        // 中央値をデータ列の一番左に移動し、その値をpivotとする
        if (value[tempIndex[1]] != value[leftIndex]) {
            Process::Swap(&value[tempIndex[1]], &value[leftIndex]);
        }
        pivot = leftIndex;

        // 並び替え処理
        i = leftIndex + 1;
        j = rightIndex;
        while (i < j) {
            // 右から探索し、pivotよりも大きい値を見つけ、ループを抜ける。
            while (value[i] < value[pivot]) {
                i++;
            }

            // 左から探索し、pivotよりも小さい値を見つけ、ループを抜ける。
            while (value[pivot] < value[j]) {
                j--;
            }

            // 見つけた値同士で交換する。
            if (i < j) {
                Process::Swap(&value[i], &value[j]);
            }
        }

        // pivotを列の中央に移動する
        if (value[j] < value[pivot]) {
            Process::Swap(&value[j], &value[pivot]);
        }

        // pivotより小さい数字を集めた範囲でソート
        QuickSort(value, leftIndex, j - 1);

        // pivotより大きい数字を集めた範囲でソート
        QuickSort(value, i, rightIndex);

        // 結果表示
        Process::ShowArray(value, leftIndex, rightIndex + 1);
    }

    // クイックソート(オーダー = O(NlogN))
    void QuickSort(int *value, int length)
    {
        std::cout << "Run Quick Sort" << std::endl;
        QuickSort(value, 0, length - 1);
    }
}