#ifndef   SORT_HPP
#define   SORT_HPP

#include <iostream>
#include <vector>
#include "SortAlgorithms/Utils.hpp"
#include "SortAlgorithms/Show.hpp"

namespace SortAlgorithms
{
    class Sort
    {
    public:
        static void SelectionSort(int *, int);
        static void BubbleSort(int *, int);
        static void InsertionsSort(int *, int);
        static void ShellSort(int *, int);
        static void MergeSort(int *, int);
        static void QuickSort(int *, int);
        static void HeapSort(int *, int);
        static void ShakerSort(int *, int);
    };
}

#endif