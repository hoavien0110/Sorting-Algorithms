#include "..\File_header\sortAlgorithm.h"
#include "..\File_header\solve.h"
#include <cstring>
#include <iostream>
using namespace std;

long long selectionSort(int a[], int n){
    long long countCmp = 0;
    int indexMin;

    for (int i = 0; (++countCmp) && (i < n - 1); i++){
        indexMin = i;

        for (int j = i + 1; (++countCmp) && (j < n); j++){
            if ((++countCmp) && (a[j] < a[indexMin]))
                indexMin = j;
        }

        if ((++countCmp) && (i != indexMin)){
            swap(a[i], a[indexMin]);
        }
    }
    return countCmp;
}

long long insertionSort(int a[], int n){
    int index, value;
    long long countCmp = 0;

    for (int i = 1; (++countCmp) && (i < n); i++){
        index = i;
        value = a[i];
        while ((++countCmp) && (++countCmp) && (index > 0) && (a[index - 1] > value)){
            a[index] = a[index - 1];
            index--;
        }
        a[index] = value;
    }
    return countCmp;
}

long long shakerSort(int a[], int n)
{
	int Left = 0;
	int Right = n - 1;
	int k = 0;
    long long countCmp = 0;

	while ((++countCmp) && (Left < Right))
	{
		for (int i = Left; (++countCmp) && (i < Right); i++)
		{
			if ((++countCmp) && a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				k = i;
			}
		}
		Right = k;
		for (int i = Right; (++countCmp) && (i > Left); i--)
		{
			if ((++countCmp) && a[i] < a[i - 1])
			{
				swap(a[i], a[i - 1]);
				k = i;
			}
		}
		Left = k;
	}
    return countCmp;
}

long long bubbleSort(int a[], int n){
    long long countCmp = 0;

    for (int i = n - 1; (++countCmp) && (i >= 1); i--)
        for (int j = 0; (++countCmp) && (j < i); j++)
            if ((++countCmp) && a[j] > a[j+1])
                swap(a[j], a[j+1]);
    return countCmp;
}

long long shellSort(int a[], int n){
    long long countCmp = 0;
    int interval, i, j, temp;
    
    for (interval = n/2;(++countCmp) && (interval > 0); interval /= 2){
        for (int i = interval; (++countCmp) && (i < n); i++){
			temp = a[i];
			for(j = i; (++countCmp) && (j >= interval && a[j - interval] > temp); j -= interval){
				a[j] = a[j - interval];				
			}
			a[j] = temp;           
        }
    }
    return countCmp;
}

long long merge(int array[], int const left, int const mid,
           int const right)
{
    long long cntComp = 0;
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
 
    for (auto i = 0; (++cntComp) && (i < subArrayOne); i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; (++cntComp) && (j < subArrayTwo); j++)
        rightArray[j] = array[mid + 1 + j];
 
    auto indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array
 
    // Merge the temp arrays back into array[left..right]
    while ((++cntComp) && (++cntComp) && (indexOfSubArrayOne < subArrayOne) &&( indexOfSubArrayTwo < subArrayTwo)) {
        if ((++cntComp) && (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while ((++cntComp) && (indexOfSubArrayOne < subArrayOne)) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while ((++cntComp) && (indexOfSubArrayTwo < subArrayTwo)) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;

    return cntComp;
}
 
long long mergeSort(int array[], int const begin, int const end)
{
    long long cntComp = 0;
    if ((++cntComp) && (begin >= end))
        return -1; 
 
    auto mid = begin + (end - begin) / 2;
    long long cntComp1 = mergeSort(array, begin, mid);
    long long cntComp2 = mergeSort(array, mid + 1, end);
    cntComp += merge(array, begin, mid, end);
    cntComp += cntComp1 + cntComp2;
    return cntComp;
}

long long sift(int a[], int l, int r){
    long long cntCompare = 0;
    int i = l;
    int j = 2 * i + 1;
    int x;

    while ((++cntCompare) && (j <= r)){
        x = a[i];
        if ((++cntCompare) && (j < r)){
            if ((++cntCompare) && (a[j] < a[j + 1]))
                j++;
        }
        if ((++cntCompare) && (x >= a[j])) break;

        swap(a[i], a[j]);
        i = j;
        j = 2 * i + 1;
    }
    return cntCompare;
}

long long heapSort(int a[], int l, int r, int n){
    l = n / 2;
    r = n - 1;
    long long cntCompare = 0;
    while ((++cntCompare) && (l >= 0)){
        cntCompare += sift(a, l, r);
        l--;
    }

    l = 0; r = n - 1;
    while ((++cntCompare) && (r > 0)){
        swap(a[0], a[r]);
        r--;
        cntCompare += sift(a, 0, r);
    }
    return cntCompare;
}

long long countingSort(int a[], int n){
    long long cntCompare = 0;

    int u = getMax(a, n);
    cntCompare += n;

    int* f = new int[u + 1];

    for (int i = 0; (++cntCompare) && (i <= u); i++)
        f[i] = 0;
    
    for (int i = 0; (++cntCompare) && (i < n); i++)
        f[a[i]]++;

    for (int i = 1; (++cntCompare) && (i <= u); i++)
        f[i] += f[i - 1];

    int* b = new int[n];

    for (int i = n - 1; (++cntCompare) && (i >= 0); i--){
        b[f[a[i]] - 1] = a[i];
        f[a[i]]--;    
    }

    for (int i = 0; (++cntCompare) && (i < n); i++){
        a[i] = b[i];
    }

    delete[] f;
    delete[] b;

    return cntCompare;
}

int digit(int x, int exp){
    return (x / exp) % 10;
}

long long countSort(int* a, int n, int exp){
    int countCmp = 0;
    int* b = new int[n];
    int count[10] = { 0 };

    for (int i = 0; (++countCmp) && (i < n); i++)
        count[digit(a[i], exp)]++;
    
    for (int i = 1; (++countCmp) && (i < 10); i++)
        count[i] += count[i - 1];

    for (int i = n - 1; (++countCmp) && (i >= 0); i--){
        int j = digit(a[i], exp);
        b[count[j] - 1] = a[i];
        count[j]--;
    }

    for (int i = 0; (++countCmp) && (i < n); i++)
        a[i] = b[i];
    
    delete[] b;
    return countCmp;
}

long long radixSort(int* a, int n){
    long long cntCompare = 0;
    int max = getMax(a, n);
    cntCompare += n;

    for (int exp = 1; max / exp > 0; exp *= 10){
        cntCompare += countSort(a, n, exp);
    }
    return cntCompare;
}

long long quickSort(int a[], int l, int r){
    int cntCompare = 0;
	int p = a[(l+r)/2];
	int i = l, j = r;
	while (i < j){
		while ((++cntCompare) && (a[i] < p)){
			i++;
		}
		while ((++cntCompare) && (a[j] > p)){
			j--;
		}
		if (i <= j){
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	if (i < r){
		cntCompare += quickSort(a, i, r);
	}
	if (l < j){
		cntCompare += quickSort(a, l, j);
	}
    return cntCompare;
}

int findMin(int* arr, int n, int& count) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        count++;
        (min > arr[i]) ? (min = arr[i]) : (min = min);
    }
    return min;
}

int findMax(int* arr, int n, int& count) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        count++;
        (max < arr[i]) ? (max = arr[i]) : (max = max);
    }
    return max;
}

long long flashSort(int* arr, int n) {
    int m = 0.45 * n;
    int* L = new int[m];
    int k = 0;

    int countcmp = 0;

    int min = findMin(arr, n, countcmp);
    int max = findMax(arr, n, countcmp);
    double c1 = (double)(m - 1) / (max - min);

    L[0] = -1;
    for (int i = 1; (++countcmp) && (i < m); i++) {
        L[i] = 0;
    }

    for (int i = 0; (++countcmp) && (i < n); i++) {
        k = c1 * (arr[i] - min);
        L[k]++;
    }

    for (int i = 1; (++countcmp) && (i < m); i++) {
        L[i] += L[i - 1];
    }

    int count = 0, i = 0;
    k = m - 1;

    while ((++countcmp) && (count < n)) {
        while ((++countcmp) && (i > L[k])) {
            i++;
            k = c1 * (arr[i] - min);
        }

        int x = arr[i];


        while ((++countcmp) && (i <= L[k]))
        {
            k = c1 * (x - min);
            int y = arr[L[k]];
            arr[L[k]] = x;
            x = y;
            L[k]--;
            count++;
        }
    }

    for (int j = 1;(++countcmp) && (j < m); j++) {
        for (int t = L[j] - 1;(++countcmp) && t > L[j - 1]; t--) {
            if ((++countcmp) && (arr[t] > arr[t + 1])) {
                int s = arr[t];
                int z = t;
                while ((++countcmp) && (s > arr[z + 1])) {
                    arr[z++] = arr[z + 1];
                }
                arr[z] = s;
            }
        }
    }
    delete[]L;
    return countcmp;
}