#pragma once
#include "utils.hpp"

namespace sort1{
    int split_qs(std::vector<int>& A, int i, int j);
    void quickSort(std::vector<int>& A, int i, int j);
    void insertSort(std::vector<int>& arr);
    void merge(std::vector<int>& arr, int left, int mid, int right);
    void mergeSort(std::vector<int>& arr, int left, int right);
    void countingSort(std::vector<int>& arr, int exp);
    void radixSort(std::vector<int>& arr);
    int getDigit(int num, int exp);
}