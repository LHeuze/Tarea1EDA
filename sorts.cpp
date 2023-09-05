#include <iostream>
#include <string>
#include "sorts.hpp"

namespace sort1{
        // QUICKSORT
        int split_qs(std::vector<int>& A, int i, int j){
		/***
		 * split for quicksort
		 * i,j are the endpoints
		 */
		int p = sort::getRandomInt(i, j);

		while (i  < j) {

			while ( i < p && A[i] <= A[p]){
				i = i + 1;
			}

			while ( j > p && A[j] >= A[p]){
				j = j - 1;
			}

			sort::swap(A, i, j);

			if (i == p){
				p = j;
			}
			else if (j == p){
				p = i;
			}
		}
		return p;
	}

	void quickSort(std::vector<int>& A, int i, int j){
		if (i < j){
			int k = split_qs(A, i, j);
			quickSort(A, i, k-1);
			quickSort(A, k + 1, j);
		}
	}
    
    /*void quickSort(float* A, int n){
		quickSort(A, 0, n - 1);
	}*/
    
   
    // INSERTSORT
    void insertSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
	}
    
	//MERGESORT
	void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }

    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] < rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
	}
    void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

    
	//RADIXSORT
int getDigit(int num, int exp) {
    while (exp > 0) {
        num /= 10;
        exp--;
    }
    return num % 10;
}

void countingSort(std::vector<int>& arr, int exp) {
    const int radix = 10;
    int n = arr.size();
    std::vector<int> output(n), count(radix, 0);

    for (int i = 0; i < n; i++) {
        count[getDigit(arr[i], exp)]++;
    }

    for (int i = 1; i < radix; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = getDigit(arr[i], exp);
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    std::copy(output.begin(), output.end(), arr.begin());
}

void radixSort(std::vector<int>& arr) {
    int maxVal = *std::max(arr.begin(), arr.end());
    int exp = 1;

    while (maxVal / exp > 0) {
        countingSort(arr, exp);
        exp *= 10;
    }
}

}