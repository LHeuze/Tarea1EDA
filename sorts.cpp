#include <iostream>
#include <string>
#include "sorts.hpp"

namespace sort1{
        // QUICKSORT (repositorio profe)
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
    
   
    // INSERTSORT apuntes profe
    void insertSort(std::vector<int>& A) {
    int n = A.size();

    for (int i = 1; i < n; i++) {
        int elem = A[i];
        int j = i - 1;

        while (j >= 0 && elem < A[j]) {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = elem;
    }
	}
    
	//MERGESORT sacado del libro guia , apuntes del profe
	void merge(std::vector<int>& A, int ini, int medio, int fin) {
    int n1 = medio - ini + 1;
    int n2 = fin - medio;

    std::vector<int> iniA(n1);
    std::vector<int> finA(n2);

    for (int i = 0; i < n1; i++) {
        iniA[i] = A[ini + i];
    }

    for (int i = 0; i < n2; i++) {
        finA[i] = A[medio + 1 + i];
    }

    int p1 = 0, p2 = 0, q = ini;

    while (p1 < n1 && p2 < n2) {
        if (iniA[p1] < finA[p2]) {
            A[q] = iniA[p1];
            p1++;
        } else {
            A[q] = finA[p2];
            p2++;
        }
        q++;
    }

    while (p1 < n1) {
        A[q] = iniA[p1];
        p1++;
        q++;
    }

    while (p2 < n2) {
        A[q] = finA[p2];
        p2++;
        q++;
    }
	}
    void mergeSort(std::vector<int>& A, int ini, int fin) {
    if (ini < fin) {
        int medio = ini + (fin - ini) / 2;
        mergeSort(A, ini, medio);
        mergeSort(A, medio + 1, fin);
        merge(A, ini, medio, fin);
    }
}

    
	//RADIXSORT
void countingSort(std::vector<int>& A, int n, int exp) {
    int rango = 10;
    std::vector<int> output(n);
    int count[rango] = {0}; // lleva la cuenta del digito en el que se esta

    for (int i = 0; i < n; i++)
        count[(A[i] / exp) % rango]++;

    for (int i = 1; i < rango; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(A[i] / exp) % rango] - 1] = A[i];
        count[(A[i] / exp) % rango]--;
    }

    for (int i = 0; i < n; i++)
        A[i] = output[i];
}

void radixSort(std::vector<int>& A, int n) {
    int maxNum = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > maxNum) {
            maxNum = A[i];
        }
    }

    for (int exp = 1; maxNum / exp > 0; exp *= 10) {
        countingSort(A, n, exp);
    }
}

}
