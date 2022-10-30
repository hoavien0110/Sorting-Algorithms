#include <iostream>
#include "..\File_header\DataGenerator.h"
#include "..\File_header\solve.h"
#include <string.h>
using namespace std;

void writeFileInputCmd5(const char* fileName, int inputSize, int inputOrder, int* &a){
    FILE* f = fopen(fileName, "w");

    if (f == NULL){
        cout << "FILE NOT FOUND !!!";
        exit(1);
    }

    a = new int[inputSize];
    GenerateData(a, inputSize, inputOrder);
    fprintf(f, "%d\n", inputSize);

    for (int i = 0; i < inputSize; i++)
        fprintf(f, "%d ", a[i]);

    fclose(f);
}

void readFileCmd5(const char* fileName, int* &a, int &n){
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

void solveCmd5(const char* inputFile, const char* algorithm1, const char* algorithm2, const char* inputOrder, const char* inputSize ,int* &a){
    // cout << "hello";
    long long cntCompare1;
    long long time1;
    long long cntCompare2;
    long long time2;
    int order;
    int n = StringToNum(inputSize);

    if (strcmp(inputOrder, "-rand") == 0)
        order = 0;

    else if (strcmp(inputOrder, "-nsorted") == 0)
        order = 3;

    else if (strcmp(inputOrder, "-sorted") == 0)
        order = 1;

    else if (strcmp(inputOrder, "-rev") == 0)
        order = 2;

    else{
        cout << "UNKNOWN ORDER" << endl;
        exit(1);
    }

    writeFileInputCmd5(inputFile, n, order, a);

    readFileCmd5(inputFile, a, n);
    sortArrayComp(algorithm1, a, n, cntCompare1);
    readFileCmd5(inputFile, a, n);
    sortArrayTime(algorithm1, a, n, time1);

    readFileCmd5(inputFile, a, n);
    sortArrayComp(algorithm2, a, n, cntCompare2);
    readFileCmd5(inputFile, a, n);
    sortArrayTime(algorithm2, a, n, time2);   

    cout << "Running time (if required): " << time1 << " | " << time2 << endl;
    cout << "Comparisons (if required): " << cntCompare1 << " | " << cntCompare2 <<endl;
}