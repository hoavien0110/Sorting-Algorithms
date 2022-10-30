#include <iostream>
#include "..\File_header\DataGenerator.h"
#include "..\File_header\solve.h"
#include <string.h>
using namespace std;

int readCmd4Size(const char* fileName){
    FILE* f = fopen(fileName, "r");

    if (f == NULL){
        cout << "FILE NOT FOUND" << endl;
        exit(1);
    }

    int size;
    fscanf(f, "%d", &size);

    fclose(f);
    return size;
}

void readFileCmd4(const char* fileName, int* &a, int &n){
    FILE* f = fopen(fileName, "r");

    if (f == NULL){
        cout << "FILE NOT FOUND" << endl;
        exit(1);
    }

    fscanf(f, "%d", &n);
    
    if (a != NULL)
        delete[] a;

    a = new int[n];

    for (int i = 0; i < n; i++){
        fscanf(f, "%d", &a[i]);
    }

    fclose(f);
}

void writeFileCmd4(const char* fileName,int *a, int n){
    FILE* f = fopen(fileName, "w");

    fprintf(f, "%d\n", n);

    for (int i = 0; i < n; i++){
        fprintf(f, "%d ", a[i]);
    }

    fclose(f);
}

void solveCmd4(const char* algorithm1, const char* algorithm2, const char* inputFile, int* &a, int &n){
    long long cntCompare1;
    long long time1;
    long long cntCompare2;
    long long time2;

    readFileCmd4(inputFile, a, n);
    sortArrayComp(algorithm1, a, n, cntCompare1);
    readFileCmd4(inputFile, a, n);
    sortArrayTime(algorithm1, a, n, time1);

    readFileCmd4(inputFile, a, n);
    sortArrayComp(algorithm2, a, n, cntCompare2);
    readFileCmd4(inputFile, a, n);
    sortArrayTime(algorithm2, a, n, time2);

    cout << "Running time (if required): " << time1 << " | " << time2 << endl;
    cout << "Comparisons (if required): " << cntCompare1 << " | " << cntCompare2 << endl;
}