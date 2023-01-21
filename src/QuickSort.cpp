#include "SortAlgorithms/Sort.hpp"

namespace SortAlgorithms
{
    int arraySize;

    // データ列の先頭/中央/末尾の3つの値の中央値を求める
    int med3(int *value, int low, int high)
    {
        bool swapped;
        int temp[] = {
            low, (low + high) / 2, high
        };

        for (int i = 1; i < 3; i++) {
            for (int j = i - 1; j >= 0; j--) {
                swapped = false;
                if (value[temp[j]] > value[temp[j + 1]]) {
                    Utils::swap(&temp[j], &temp[j + 1]);
                    swapped = true;
                }
                if (!swapped) { break; }
            }
        }
        return temp[1];
    }

    void quick(int *value, int low, int high)
    {
        // 分割されたデータ列の値が1個の場合、それを返す。
        if (low >= high) { return; }

        int left = low + 1;
        int right = high;
        int pivot = med3(value, low, high);

        // 中央値をデータ列の一番左に移動し、その値をpivotとする
        if (pivot != low) {
            Utils::swap(&value[pivot], &value[low]);
            pivot = low;
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
                Utils::swap(&value[left], &value[right]);
            }
        } while (left < right);

        // pivotを列の中央に移動する
        if (value[right] < value[pivot]) {
            Utils::swap(&value[right], &value[pivot]);
        }

        // pivotより小さい数字を集めた範囲でソート
        quick(value, low, right - 1);

        // pivotより大きい数字を集めた範囲でソート
        quick(value, left, high);

        // 結果表示
        Show::array(value, low, high + 1);
    }

    // クイックソート(オーダー = O(NlogN))
    void Sort::quickSort(int *value, int length)
    {
        arraySize = length;
        std::cout << "Run Quick Sort" << std::endl;
        quick(value, 0, length - 1);
    }
}