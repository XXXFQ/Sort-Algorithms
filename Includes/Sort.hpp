#ifndef   SORT_H
#define   SORT_H

#include <iostream>
#include <memory>
#include <vector>
#include "Process.hpp"

namespace SortAlgorithms
{
    void SelectionSort(int *, int);
    void BubbleSort(int *, int);
    void InsertionsSort(int *, int);
    void ShellSort(int *, int);
    void MergeSort(int *, int);
    void QuickSort(int *, int);
    void HeapSort(int *, int);
    void ShakerSort(int *, int);
}

#endif