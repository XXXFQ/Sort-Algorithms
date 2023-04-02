#include <memory>

#include "sort_algorithms/sort.hpp"

namespace sort_algorithms
{
    void merge(int *value, int length)
    {
        int i, j, left_length, right_length, *temp;

        // 分割されたデータ列の値が1個の場合、それを返す。
        if (length <= 1) return;

        // データ列の長さに合わせて、メモリを確保
        temp = new int[length];

        left_length = length / 2;
        right_length = length - left_length;
        merge(value, left_length);
        merge(value + left_length, right_length);
        i = j = 0;
        
        while (i < left_length && j < right_length) {
            if (value[i] < value[left_length + j]) {
                temp[i + j] = value[i];
                i++;
            } else {
                temp[i + j] = value[left_length + j];
                j++;
            }
        }

        while (i < left_length || j < right_length) {
            if (i < left_length) {
                temp[i + j] = value[i];
                i++;
            } else {
                temp[i + j] = value[left_length + j];
                j++;
            }
        }

        // tempの内容をvalue配列にコピー
        memcpy(value, temp, sizeof(int) * length);

        // 確保したメモリを解放
        delete temp;

        // 結果表示
        Show::array(value, length);
    }

    // マージソート(オーダー = O(NlogN))
    void Sort::merge_sort(int *value, int length)
    {
        std::cout << "Run Merge Sort" << std::endl;
        merge(value, length);
    }
}