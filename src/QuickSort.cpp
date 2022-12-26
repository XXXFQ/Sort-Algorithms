#include "Sort.hpp"

namespace SortAlgorithms
{
    int swapCount, arraySize;

    void QuickSort(int *value, int leftIndex, int rightIndex)
    {
        int left = leftIndex + 1;
        int right = rightIndex;
        int pivot = leftIndex;
        int tempIndex[] = {
            leftIndex, (rightIndex + leftIndex) / 2, rightIndex
        };

        // 分割されたデータ列の値が1個の場合、それを返す。
        if (leftIndex >= rightIndex) { return; }
        
        // データ列[value]の先頭/中央/末尾の3つの値の中央値を基準値とする
        for (int i = 1; i < 3; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (value[tempIndex[j]] > value[tempIndex[j + 1]]) {
                    Process::Swap(&tempIndex[j], &tempIndex[j + 1]);
                    swapCount++;
                }
            }
        }

        // 中央値をデータ列の一番左に移動し、その値をpivotとする
        if (value[tempIndex[1]] != value[leftIndex]) {
            Process::Swap(&value[tempIndex[1]], &value[leftIndex]);
            swapCount++;
        }

        // 並び替え処理
        do {
            // 右から探索し、pivotよりも大きい値を見つける
            while (left <= right && left < arraySize) {
        		if (value[left] > value[pivot]) { break; }
        		left++;
        	}

            // 左から探索し、pivot以下の値を見つける
            while (left <= right && right >= 0) {
        		if (value[pivot] >= value[right]) { break; }
        		right--;
        	}

            // 見つけた値同士で交換する。
            if (left < right) {
                Process::Swap(&value[left], &value[right]);
                swapCount++;
            }
        } while (left < right);

        // pivotを列の中央に移動する
        if (value[right] < value[pivot]) {
            Process::Swap(&value[right], &value[pivot]);
            swapCount++;
        }

        // pivotより小さい数字を集めた範囲でソート
        QuickSort(value, leftIndex, right - 1);

        // pivotより大きい数字を集めた範囲でソート
        QuickSort(value, left, rightIndex);

        // 結果表示
        Process::ShowArray(value, leftIndex, rightIndex + 1);
    }

    // クイックソート(オーダー = O(NlogN))
    void QuickSort(int *value, int length)
    {
        swapCount = 0;
        arraySize = length;
        std::cout << "Run Quick Sort" << std::endl;
        QuickSort(value, 0, length - 1);
        Process::ShowSwapCount(swapCount);
    }
}