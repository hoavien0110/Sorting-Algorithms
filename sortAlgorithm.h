#pragma once

long long selectionSort(int a[], int n);
long long insertionSort(int a[], int n);
long long shakerSort(int a[], int n);
long long bubbleSort(int a[], int n);
long long shellSort(int a[], int n);
// long long merge(int* a1, int n1, int* a2, int n2, int* a, int start);
// long long mergeSort(int* a, int l, int r);
long long merge(int array[], int const left, int const mid, int const right);
long long mergeSort(int array[], int const begin, int const end);
long long sift(int a[], int l, int r);
long long heapSort(int a[], int l, int r, int n);
int getMax(int a[], int n);
long long countingSort(int a[], int n);
int digit(int x, int exp);
long long countSort(int* a, int n, int exp);
long long radixSort(int* a, int n);
// long long flashSort(int* a, int n);
long long quickSort(int a[], int l, int r);
long long flashSort(int* arr, int n);
int findMax(int* arr, int n, int& count);
int findMin(int* arr, int n, int& count);