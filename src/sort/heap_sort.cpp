#include "sort_algorithms/sort.hpp"

#define LEFT_CHILD(i)  ((i + 1) * 2 - 1)
#define RIGHT_CHILD(i) ((i + 1) * 2)

namespace sort_algorithms
{
    // heap配列に新しく追加されたデータがあるものとして、ヒープとなるよう再構成する
    void up_heap(int *heap, int parent, int length)
    {
        const int left_child = LEFT_CHILD(parent);
        const int right_child = RIGHT_CHILD(parent);
        if (left_child >= length) return;

        // 親より左の子の方が大きい場合入れ替える。
        if (heap[left_child] < heap[parent]) {
            Utils::swap(&heap[left_child], &heap[parent]);
            up_heap(heap, left_child, length);
        }

        // 親より右の子の方が大きい場合入れ替える。
        if (heap[right_child] < heap[parent] && right_child < length) {
            Utils::swap(&heap[right_child], &heap[parent]);
            up_heap(heap, right_child, length);
        }
    }

    // heap配列からルートが削除されたとして、ヒープを再構成する
    void down_heap(int *heap, int parent, int length)
    {
        const int left_child = LEFT_CHILD(parent);
        const int right_child = RIGHT_CHILD(parent);
        if (left_child >= length) return;

        // ルートを木の末端の要素と入れ替える
        if (parent == 0) {
            Utils::swap(&heap[length], &heap[0]);
        }

        // 親より右の子の方が大きい場合入れ替える。
        if (heap[right_child] < heap[parent] && right_child < length) {
            Utils::swap(&heap[right_child], &heap[parent]);
            down_heap(heap, right_child, length);
        }

        // 親より左の子の方が大きい場合入れ替える。
        if (heap[left_child] < heap[parent]) {
            Utils::swap(&heap[left_child], &heap[parent]);
            down_heap(heap, left_child, length);
        }
    }

    // ヒープソート(オーダー = O(NlogN))
    void Sort::heap_sort(int *value, int length)
    {
        int *heap, parent = length / 2 - 1;
        int heap_length = length;
        int added = parent;

        std::cout << "Run Heap Sort" << std::endl;
        heap = new int[length];

        // ヒープへの追加処理
        for (int i = 0; i < heap_length; i++, parent--) {
            // 親ノードにデータを追加
            heap[parent] = value[i];

            // 左の子にデータを追加
            if (LEFT_CHILD(parent) > added) {
                heap[LEFT_CHILD(parent)] = value[++i];
            }

            // 右の子にデータを追加
            if (RIGHT_CHILD(parent) > added && RIGHT_CHILD(parent) < heap_length) {
                heap[RIGHT_CHILD(parent)] = value[++i];
            }

            // heap配列がヒープとなるよう再構成
            up_heap(heap, parent, heap_length);
        }
        value[0] = heap[0];
        Show::array(heap, heap_length);

        // ヒープからルートの削除
        for (int i = 1; i < length; i++) {
            // heap配列からルートを削除して、ヒープを再構成する
            down_heap(heap, 0, --heap_length);

            // value配列にheap配列の先頭を代入
            value[i] = heap[0];

            // 結果表示
            Show::array(heap, heap_length);
        }
        value[length - 1] = heap[1];
        Show::array(value, length);
        delete heap;
    }
}