#pragma once
#include "utils.hpp"

namespace sort1{
    int split_qs(std::vector<int>& A, int i, int j);
    void quickSort(std::vector<int>& A, int i, int j);
    void insertSort(std::vector<int>& A);
    void merge(std::vector<int>& A, int ini, int medio, int fin);
    void mergeSort(std::vector<int>& A, int ini, int fin);
    void countingSort(std::vector<int>& A, int n, int exp);
    void radixSort(std::vector<int>& A, int n);
}