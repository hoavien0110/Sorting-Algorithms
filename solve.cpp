#include <iostream>
#include <cstdlib>
#include <ctime>
#include "..\File_header\sortAlgorithm.h"
#include "..\File_header\countTime.h"
#include <string.h>
#include "..\File_header\solveCmd1.h"
#include "..\File_header\solveCmd2.h"
#include "..\File_header\solveCmd3.h"
#include "..\File_header\solveCmd4.h"
#include "..\File_header\solveCmd5.h"
#define MAX 10000
using namespace std;

void printArray(int a[], int n){
    for (int i = 0; i <n; i++)
        cout << a[i] << " ";
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int getMax(int a[], int n){
    int max = a[0]; 
    for (int i = 1; i < n; ++i)
        if (a[i] > max)
            max = a[i];
    return max;
}

int getMin(int a[], int n){
    int min = a[0]; 
    for (int i = 1; i < n; ++i)
        if (a[i] < min)
            min = a[i];
    return min;
}

int StringToNum(const char* s){
    int num = 0;

    for (int i = 0; i < strlen(s); i++){
        num *= 10;
        num += s[i] - '0';
    }
    
    return num;
}
void sortArrayTime(const char* algorithm, int* &a, int n, long long &time){
    if (strcmp(algorithm, "selection-sort") == 0){
        time = countTimeSelectionSort(a, n);
    }
    
    else if (strcmp(algorithm, "insertion-sort") == 0){
        time = countTimeInsertionSort(a, n);
    }
    
    else if (strcmp(algorithm, "bubble-sort") == 0){
        time = countTimeBubbleSort(a, n);
    }
    
    else if (strcmp(algorithm, "shaker-sort") == 0){
        time = countTimeShakerSort(a, n);
    }
    
    else if (strcmp(algorithm, "shell-sort") == 0){
        time = countTimeShellSort(a, n);
    }
    
    else if (strcmp(algorithm, "heap-sort") == 0){
        time = countTimeHeapSort(a, n);
    }
    
    else if (strcmp(algorithm, "merge-sort") == 0){
        time = countTimeMergeSort(a, n);
    }
    
    else if (strcmp(algorithm, "quick-sort") == 0){
        time = countTimeQuickSort(a, n);
    }
    
    else if (strcmp(algorithm, "radix-sort") == 0){
        time = countTimeRadixSort(a, n);
    }
    
    else if (strcmp(algorithm, "counting-sort") == 0){
        time = countTimeCountingSort(a, n);
    }
    
    else if (strcmp(algorithm, "flash-sort") == 0){
        time = countTimeFlashSort(a, n);
    }
    
    else{
        cout << "NO SORTING" << endl;
        exit(1);
    }
}
void sortArrayComp(const char* algorithm, int* &a, int n, long long &cntCompare){
    if (strcmp(algorithm, "selection-sort") == 0){
        cntCompare = selectionSort(a, n);
    }
    
    else if (strcmp(algorithm, "insertion-sort") == 0){
        cntCompare = insertionSort(a, n);
    }
    
    else if (strcmp(algorithm, "bubble-sort") == 0){
        cntCompare = bubbleSort(a, n);
    }
    
    else if (strcmp(algorithm, "shaker-sort") == 0){
        cntCompare = shakerSort(a, n);
    }
    
    else if (strcmp(algorithm, "shell-sort") == 0){
        cntCompare = shellSort(a, n);
    }
    
    else if (strcmp(algorithm, "heap-sort") == 0){
        cntCompare = heapSort(a, 0, n - 1, n);
    }
    
    else if (strcmp(algorithm, "merge-sort") == 0){
        cntCompare = mergeSort(a, 0, n - 1);
    }
    
    else if (strcmp(algorithm, "quick-sort") == 0){
        cntCompare = quickSort(a, 0, n - 1);
    }
    
    else if (strcmp(algorithm, "radix-sort") == 0){
        cntCompare = radixSort(a, n);
    }
    
    else if (strcmp(algorithm, "counting-sort") == 0){
        cntCompare = countingSort(a, n);
    }
    
    else if (strcmp(algorithm, "flash-sort") == 0){
        cntCompare = flashSort(a, n);   
    }
    
    else{
        cout << "NO SORTING" << endl;
        exit(1);
    }
}

string algorithmNameOption(const char* algorithm){
    if(strcmp(algorithm, "selection-sort") == 0){
        return "Selection Sort";
    }
    if(strcmp(algorithm, "insertion-sort") == 0){
        return "Insertion Sort";
    }
    if(strcmp(algorithm, "bubble-sort") == 0){
        return "Bubble Sort";
    }
    if(strcmp(algorithm, "shaker-sort") == 0){
        return "Shaker Sort";
    }
    if(strcmp(algorithm, "shell-sort") == 0){
        return "Shell Sort";
    }
    if(strcmp(algorithm, "heap-sort") == 0){
        return "Heap Sort";
    }
    if(strcmp(algorithm, "merge-sort") == 0){
        return "Merge Sort";
    }
    if(strcmp(algorithm, "quick-sort") == 0){
        return "Quick Sort";
    }
    if(strcmp(algorithm, "counting-sort") == 0){
        return "Counting Sort";
    }
    if(strcmp(algorithm, "radix-sort") == 0){
        return "Radix Sort";
    }
    if(strcmp(algorithm, "flash-sort") == 0){
        return "Flash Sort";
    }
    else{
        return "No Sorting";
    }
}

string inputOrderOption(const char* order){
    if(strcmp(order, "-rand") == 0){
        return "Randomized data";
    }
    if(strcmp(order, "-nsorted") == 0){
        return "Nearly Sorted data";
    }
    if(strcmp(order, "-sorted") == 0){
        return "Sorted data";
    }
    if(strcmp(order, "-rev") == 0){
        return "Reverse Sorted data";
    }
    else{
        return "No order";
    }
}

void solveAllCmd(int argc, char** argv, int* &a, int n){
    if (strcmp(argv[1], "-a") == 0){
        //  ALGORITHM MODE
        if (argc == 6){
        // CMD2 -----------------------------

        cout << "ALGORITHM MODE" << endl;
        cout << "Algorithm: " << algorithmNameOption(argv[2]) << endl;
        cout << "Input size: " << argv[3] << endl;
        cout << "Input order: " << inputOrderOption(argv[4]) << endl;
        cout << "------------------------------------" << endl;
        solveSortCmd2(argv[2], argv[3], argv[4], argv[5]);
        }
        else if (argc == 5){
            if (atoi(argv[3]) > 0){
                //CMD3 --------------------------

                cout << "ALGORITHM MODE" << endl;
                cout << "Algorithm: " << algorithmNameOption(argv[2]) << endl;
                cout << "Input size: " << argv[3] << endl;
                solveCmd3(argv[2], argv[3], argv[4], a, n);
            }
            else{
                // CMD1 ------------------------------

                cout << "ALGORITHM MODE" << endl;
                cout << "Algorithm: " << algorithmNameOption(argv[2]) << endl;
                cout << "Input file: " << argv[3] << endl;
                cout << "Input size: " << readCmd1Size(argv[3]) << endl;
                cout << "----------------------------------" << endl;
                solveCmd1(argv[2], argv[3], argv[4], a, n);
            }
        }
        else{
            cout << "INVALID COMMAND";
        }
    }
    else if (strcmp(argv[1], "-c") == 0){
    // COMPARE MODE
        if (argc == 5){
            //CMD4
            cout << "COMPARE MODE" << endl;
            cout << "Algorithm: " << algorithmNameOption(argv[2]) << " | " << algorithmNameOption(argv[3]) << endl;
            cout << "Input file: " << argv[4] << endl;
            cout << "Input size: " << readCmd4Size(argv[4]) << endl;
            cout << "------------------------------------" << endl;
            solveCmd4(argv[2], argv[3], argv[4], a, n);
        }
        else if (argc == 6){
            //CMD5
            cout << "COMPARE MODE" << endl;
            cout << "Algorithm: " << algorithmNameOption(argv[2]) << " | " << algorithmNameOption(argv[3]) << endl;
            cout << "Input size: " << argv[4] << endl;
            cout << "Input order: " << inputOrderOption(argv[5]) << endl;
            cout << "------------------------------------" << endl;
            solveCmd5("../File_text/input.txt", argv[2], argv[3], argv[5], argv[4], a);
        }
        else{
            cout << "INVALID COMMAND" << endl;
        }
    }
    else{
        cout << "NO MODE";
    }
}