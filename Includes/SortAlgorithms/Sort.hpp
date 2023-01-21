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
        static void selectionSort(int *, int);
        static void bubbleSort(int *, int);
        static void insertionsSort(int *, int);
        static void shellSort(int *, int);
        static void mergeSort(int *, int);
        static void quickSort(int *, int);
        static void heapSort(int *, int);
        static void shakerSort(int *, int);
    };
}

#endif