#include "..\File_header\solve.h"
#include <cstring>
#include <iostream>
using namespace std;

void SelectionSort(int a[], int n){
    int indexMin;

    for (int i = 0; (i < n - 1); i++){
        indexMin = i;

        for (int j = i + 1; (j < n); j++){
            if (a[j] < a[indexMin])
                indexMin = j;
        }

        if (i != indexMin){
            swap(a[i], a[indexMin]);
        }
    }
}

void InsertionSort(int a[], int n){
    int index, value;
    long long countCmp = 0;

    for (int i = 1;i < n; i++){
        index = i;
        value = a[i];
        while ((index > 0) && (a[index - 1] > value)){
            a[index] = a[index - 1];
            index--;
        }
        a[index] = value;
    }
}

void ShakerSort(int a[], int n)
{
	int Left = 0;
	int Right = n - 1;
	int k = 0;

	while (Left < Right)
	{
		for (int i = Left; i < Right; i++)
		{
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				k = i;
			}
		}
		Right = k;
		for (int i = Right; i > Left; i--)
		{
			if (a[i] < a[i - 1])
			{
				swap(a[i], a[i - 1]);
				k = i;
			}
		}
		Left = k;
	}
}

void BubbleSort(int a[], int n){
    for (int i = n - 1; i >= 1; i--)
        for (int j = 0; j < i; j++)
            if (a[j] > a[j+1])
                swap(a[j], a[j+1]);
}

void ShellSort(int a[], int n){
    int interval, i, j, temp;
    
    for (interval = n/2; interval > 0; interval /= 2){
        for (int i = interval; i < n; i++){
			temp = a[i];
			for(j = i; j >= interval && a[j - interval] > temp; j -= interval){
				a[j] = a[j - interval];				
			}
			a[j] = temp;           
        }
    }
}

void Merge(int array[], int const left, int const mid,
           int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
 
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    auto indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array
 
    // Merge the temp arrays back into array[left..right]
    while ((indexOfSubArrayOne < subArrayOne) &&( indexOfSubArrayTwo < subArrayTwo)) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
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
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;

}
 
void MergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return ; 
 
    auto mid = begin + (end - begin) / 2;
    MergeSort(array, begin, mid);
    MergeSort(array, mid + 1, end);
    Merge(array, begin, mid, end);
}

void Sift(int a[], int l, int r){
    int i = l;
    int j = 2 * i + 1;
    int x;

    while (j <= r){
        x = a[i];
        if (j < r){
            if (a[j] < a[j + 1])
                j++;
        }
        if (x >= a[j]) break;

        swap(a[i], a[j]);
        i = j;
        j = 2 * i + 1;
    }
}

void HeapSort(int a[], int l, int r, int n){
    l = n / 2;
    r = n - 1;
    while (l >= 0){
        Sift(a, l, r);
        l--;
    }

    l = 0; r = n - 1;
    while (r > 0){
        swap(a[0], a[r]);
        r--;
        Sift(a, 0, r);
    }
}

void CountingSort(int a[], int n){

    int u = getMax(a, n);

    int* f = new int[u + 1];

    for (int i = 0; i <= u; i++)
        f[i] = 0;
    
    for (int i = 0;  i < n; i++)
        f[a[i]]++;

    for (int i = 1;  i <= u; i++)
        f[i] += f[i - 1];

    int* b = new int[n];

    for (int i = n - 1; i >= 0; i--){
        b[f[a[i]] - 1] = a[i];
        f[a[i]]--;    
    }

    for (int i = 0; i < n; i++){
        a[i] = b[i];
    }

    delete[] f;
    delete[] b;

}

int digit_count(int x, int exp){
    return (x / exp) % 10;
}

void CountSort(int* a, int n, int exp){
    int* b = new int[n];
    int count[10] = { 0 };

    for (int i = 0; i < n; i++)
        count[digit_count(a[i], exp)]++;
    
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--){
        int j = digit_count(a[i], exp);
        b[count[j] - 1] = a[i];
        count[j]--;
    }

    for (int i = 0; i < n; i++)
        a[i] = b[i];
    
    delete[] b;
}

void RadixSort(int* a, int n){
    int max = getMax(a, n);

    for (int exp = 1; max / exp > 0; exp *= 10){
        CountSort(a, n, exp);
    }
}

void QuickSort(int a[], int l, int r){
	int p = a[(l+r)/2];
	int i = l, j = r;
	while (i < j){
		while (a[i] < p){
			i++;
		}
		while (a[j] > p){
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
		QuickSort(a, i, r);
	}
	if (l < j){
		QuickSort(a, l, j);
	}
}

void FlashSort(int* arr, int n) {
    int m = 0.45 * n;
    int* L = new int[m];
    int k = 0;

    int min = getMin(arr, n);
    int max = getMax(arr, n);
    double c1 = (double)(m - 1) / (max - min);

    L[0] = -1;
    for (int i = 1; i < m; i++) {
        L[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        k = c1 * (arr[i] - min);
        L[k]++;
    }

    for (int i = 1; i < m; i++) {
        L[i] += L[i - 1];
    }

    int count = 0, i = 0;
    k = m - 1;

    while (count < n) {
        while (i > L[k]) {
            i++;
            k = c1 * (arr[i] - min);
        }

        int x = arr[i];


        while (i <= L[k])
        {
            k = c1 * (x - min);
            int y = arr[L[k]];
            arr[L[k]] = x;
            x = y;
            L[k]--;
            count++;
        }
    }

    for (int j = 1;j < m; j++) {
        for (int t = L[j] - 1;t > L[j - 1]; t--) {
            if (arr[t] > arr[t + 1]) {
                int s = arr[t];
                int z = t;
                while (s > arr[z + 1]) {
                    arr[z++] = arr[z + 1];
                }
                arr[z] = s;
            }
        }
    }
    delete[]L;
}