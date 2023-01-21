#include "SortAlgorithms/Sort.hpp"

#define LEFT_CHILD(i)  ((i + 1) * 2 - 1)
#define RIGHT_CHILD(i) ((i + 1) * 2)

namespace SortAlgorithms
{
    // heap配列に新しく追加されたデータがあるものとして、ヒープとなるよう再構成する
    void upHeap(int *heap, int parent, int length)
    {
        const int leftChild = LEFT_CHILD(parent);
        const int rightChild = RIGHT_CHILD(parent);
        if (leftChild >= length) { return; }

        // 親より左の子の方が大きい場合入れ替える。
        if (heap[leftChild] < heap[parent]) {
            Utils::swap(&heap[leftChild], &heap[parent]);
            upHeap(heap, leftChild, length);
        }

        // 親より右の子の方が大きい場合入れ替える。
        if (heap[rightChild] < heap[parent] && rightChild < length) {
            Utils::swap(&heap[rightChild], &heap[parent]);
            upHeap(heap, rightChild, length);
        }
    }

    // heap配列からルートが削除されたとして、ヒープを再構成する
    void downHeap(int *heap, int parent, int length)
    {
        const int leftChild = LEFT_CHILD(parent);
        const int rightChild = RIGHT_CHILD(parent);
        if (leftChild >= length) { return; }

        // ルートを木の末端の要素と入れ替える
        if (parent == 0) {
            Utils::swap(&heap[length], &heap[0]);
        }

        // 親より右の子の方が大きい場合入れ替える。
        if (heap[rightChild] < heap[parent] && rightChild < length) {
            Utils::swap(&heap[rightChild], &heap[parent]);
            downHeap(heap, rightChild, length);
        }

        // 親より左の子の方が大きい場合入れ替える。
        if (heap[leftChild] < heap[parent]) {
            Utils::swap(&heap[leftChild], &heap[parent]);
            downHeap(heap, leftChild, length);
        }
    }

    // ヒープソート(オーダー = O(NlogN))
    void Sort::heapSort(int *value, int length)
    {
        int *heap, parent = length / 2 - 1;
        int heapLength = length;
        int added = parent;

        std::cout << "Run Heap Sort" << std::endl;
        heap = new int[length];

        // ヒープへの追加処理
        for (int i = 0; i < heapLength; i++, parent--) {
            // 親ノードにデータを追加
            heap[parent] = value[i];

            // 左の子にデータを追加
            if (LEFT_CHILD(parent) > added)
                heap[LEFT_CHILD(parent)] = value[++i];
            
            // 右の子にデータを追加
            if (RIGHT_CHILD(parent) > added && RIGHT_CHILD(parent) < heapLength)
                heap[RIGHT_CHILD(parent)] = value[++i];
            
            // heap配列がヒープとなるよう再構成
            upHeap(heap, parent, heapLength);
        }
        value[0] = heap[0];
        Show::array(heap, heapLength);

        // ヒープからルートの削除
        for (int i = 1; i < length; i++) {
            // heap配列からルートを削除して、ヒープを再構成する
            downHeap(heap, 0, --heapLength);

            // value配列にheap配列の先頭を代入
            value[i] = heap[0];

            // 結果表示
            Show::array(heap, heapLength);
        }
        value[length - 1] = heap[1];
        Show::array(value, length);
        delete heap;
    }
}