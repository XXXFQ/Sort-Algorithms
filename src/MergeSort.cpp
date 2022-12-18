#include "Sort.hpp"

namespace SortAlgorithms
{
    void Merge(int *value, int length)
    {
        int i, j, leftLength, rightLength, *temp;

        // 分割されたデータ列の値が1個の場合、それを返す。
        if (length <= 1) { return; }

        // データ列の長さに合わせて、メモリを確保
        temp = new int[length];

        leftLength = length / 2;
        rightLength = length - leftLength;
        Merge(value, leftLength);
        Merge(value + leftLength, rightLength);
        i = j = 0;
        while (i < leftLength && j < rightLength) {
            if (value[i] < value[leftLength + j]) {
                temp[i + j] = value[i];
                i++;
            }
            else {
                temp[i + j] = value[leftLength + j];
                j++;
            }
        }
        while (i < leftLength || j < rightLength) {
            if (i < leftLength) {
                temp[i + j] = value[i];
                i++;
            }
            else {
                temp[i + j] = value[leftLength + j];
                j++;
            }
        }
        // tempの内容をvalue配列にコピー
        memcpy(value, temp, sizeof(int) * length);

        // 確保したメモリを解放
        delete temp;

        // 結果表示
        Process::ShowArray(value, length);
    }

    // マージソート(オーダー = O(NlogN))
    void MergeSort(int *value, int length)
    {
        std::cout << "Run Merge Sort" << std::endl;
        Merge(value, length);
    }
}