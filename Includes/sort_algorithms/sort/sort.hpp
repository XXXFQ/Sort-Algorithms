#ifndef   SORT_ALGORITHMS_SORT_SORT_HPP
#define   SORT_ALGORITHMS_SORT_SORT_HPP

#include <iostream>
#include <vector>

#include "sort_algorithms/utils.hpp"

namespace sort_algorithms
{
    class Sort
    {
    public:
        static void selection_sort(int *, int);
        static void bubble_sort(int *, int);
        static void insertions_sort(int *, int);
        static void shell_sort(int *, int);
        static void merge_sort(int *, int);
        static void quick_sort(int *, int);
        static void heap_sort(int *, int);
        static void shaker_sort(int *, int);
    };
}

#endif