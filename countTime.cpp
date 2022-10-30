#include "..\File_header\sortAlgorithm.h"
#include "..\File_header\sort_void.h"
#include <chrono>
using namespace std::chrono;

long long countTimeSelectionSort(int* a, int n){
    auto start = high_resolution_clock::now();
    SelectionSort(a, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    return duration.count();
}

long long countTimeInsertionSort(int* a, int n){
    auto start = high_resolution_clock::now();
    InsertionSort(a, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    return duration.count();
}

long long countTimeBubbleSort(int* a, int n){
    auto start = high_resolution_clock::now();
    BubbleSort(a, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    return duration.count();    
}

long long countTimeShakerSort(int* a, int n){
    auto start = high_resolution_clock::now();
    ShakerSort(a, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    return duration.count();    
}

long long countTimeShellSort(int* a, int n){
    auto start = high_resolution_clock::now();
    ShellSort(a, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    return duration.count();    
}

long long countTimeHeapSort(int* a, int n){
    auto start = high_resolution_clock::now();
    HeapSort(a, 0, n - 1, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    return duration.count();    
}

long long countTimeMergeSort(int* a, int n){
    auto start = high_resolution_clock::now();
    MergeSort(a, 0, n - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    return duration.count();    
}

long long countTimeQuickSort(int* a, int n){
    auto start = high_resolution_clock::now();
    QuickSort(a, 0, n - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    return duration.count();    
}

long long countTimeCountingSort(int* a, int n){
    auto start = high_resolution_clock::now();
    CountingSort(a, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    return duration.count();    
}

long long countTimeRadixSort(int* a, int n){
    auto start = high_resolution_clock::now();
    RadixSort(a, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    return duration.count();    
}

long long countTimeFlashSort(int* a, int n){
    auto start = high_resolution_clock::now();
    FlashSort(a, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    return duration.count();    
}