// Name : Shehryar Malik
// Date : Nov. 4. 2016
// sortAlgs.h

// Purpose: This file serves as the definition for the SortAlgs. The file
//          serves as an interface for the user for using the algorithms.
//          There are helper functions for each algorithm. There are
//          three main algorithms implemented: Insertion sort,
//          quick sort, and radix sort.

#ifndef SORTALGS_H_INCLUDED
#define SORTALGS_H_INCLUDED

#include <vector>
    void insert_sort(std::vector<int>&);
    void quick_sort(std::vector<int>&);
    void radix_sort(std::vector<int>&);
#endif