#include "sort_algorithms/sort.hpp"

namespace sort_algorithms
{
    // 選択ソート(オーダー = O(N^2))
    void Sort::selection_sort(int *value, int length)
    {
        std::cout << "Run Selection Sort" << std::endl;
        for (int i = 0; i < length - 1; i++) {
            for (int j = i + 1; j < length; j++) {
                if (value[i] > value[j]) {
                    Utils::swap(&value[i], &value[j]);
                }
            }
            Show::array(value, length);
        }
    }

    // バブルソート(オーダー = O(N^2))
    void Sort::bubble_sort(int *value, int length)
    {
        bool swapped;

        std::cout << "Run Bubble Sort" << std::endl;
        for (int endIndex = length - 1; endIndex >= 1; endIndex--) {
            swapped = false;
            for (int i = 0; i < endIndex; i++) {
                if (value[i] > value[i + 1]) {
                    Utils::swap(&value[i], &value[i + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break;
            Show::array(value, length);
        }
    }

    // 挿入ソート(オーダー = O(N^2))
    void Sort::insertions_sort(int *value, int length)
    {
        bool swapped;

        std::cout << "Run Insertions Sort" << std::endl;
        for (int i = 1; i < length; i++) {
            for (int j = i - 1; j >= 0; j--) {
                swapped = false;
                if (value[j] > value[j + 1]) {
                    Utils::swap(&value[j], &value[j + 1]);
                    swapped = true;
                }
                if (!swapped) break;
            }
            Show::array(value, length);
        }
    }

    // シェルソート(オーダー = O(N^2))
    void Sort::shell_sort(int *value, int length)
    {
        bool swapped;
        int h, group_number;

        std::cout << "Run Shell Sort" << std::endl;

        // 間隔hを決める
        for (h = 1; h <= length / 9; h = 3 * h + 1);

        // 間隔hが0になるまでループ
        do {
            // 間隔をあけて取り出したデータ列に挿入ソートを適用
            for (int i = h - 1; i < length - h; i += h) {
                swapped = false;
                for (int j = i, group_number = 1; j >= 0; j--, group_number++) {
                    if (value[j] > value[j + h]) {
                        Utils::swap(&value[j], &value[j + h]);
                        swapped = true;
                    }
                    // 各グループごとの比較が、それぞれ一回ずつ行われた場合
                    if (group_number == h) {
                        // 交換が行われなかった場合、ループを抜ける
                        if (!swapped) break;
                        group_number = 0;
                        swapped = false;
                    }
                }
                Show::array(value, length);
            }

            // 間隔hを狭める
            h /= 3;
        } while (h > 0);
    }

    // シェーカーソート
    void Sort::shaker_sort(int *value, int length)
    {
        int top_index = 0;
        int end_index = length - 1;
        bool swapped;

        std::cout << "Run Shaker Sort" << std::endl;
        do {
            swapped = false;

            // 順方向のスキャン
            for (int i = top_index; i < end_index; i++) {
                if (value[i] > value[i + 1]) {
                    Utils::swap(&value[i], &value[i + 1]);
                    swapped = true;
                }
            }

            // 逆方向のスキャン
            for (int i = end_index - 2; i >= top_index; i--) {
                if (value[i] > value[i + 1]) {
                    Utils::swap(&value[i], &value[i + 1]);
                    swapped = true;
                }
            }
            if (swapped) {
                Show::array(value, length);
            }
            
            // スキャン範囲を狭める
            top_index++;
            end_index--;
        } while (top_index < end_index && swapped);
    }
}