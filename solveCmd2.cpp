#include <iostream>
// #include "solveCmd1.h"
#include "..\File_header\DataGenerator.h"
#include "..\File_header\solve.h"
#include <string.h>
using namespace std;

void readFileCmd2(const char* fileName, int* &a, int &n){
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

void writeFileInputCmd2(const char* fileName, int inputSize, int inputOrder, int* &a){
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


void writeFileOutputCmd2(const char* fileName,int *a, int n){
    FILE* f = fopen(fileName, "w");

    if (f == NULL){
        cout << "FILE NOT FOUND" << endl;
        exit(1);
    }

    fprintf(f, "%d\n", n);

    for (int i = 0; i < n; i++){
        fprintf(f, "%d ", a[i]);
    }

    fclose(f);
}


void solveSortCmd2(const char* algorithm, const char* inputSize, const char* inputOrder, const char* outParam){
    int* a;
    int n;
    long long cntCompare;
    long long time;

    n = StringToNum(inputSize);

    if (strcmp(inputOrder, "-rand") == 0){
        writeFileInputCmd2("../File_text/input.txt", n, 0, a);
    }

    else if (strcmp(inputOrder, "-nsorted") == 0){
        writeFileInputCmd2("../File_text/input.txt", n, 3, a);
    }

    else if (strcmp(inputOrder, "-sorted") == 0){
        writeFileInputCmd2("../File_text/input.txt", n, 1, a);
    }
    
    else if (strcmp(inputOrder, "-rev") == 0){
        writeFileInputCmd2("../File_text/input.txt", n, 2, a);
    }

    else{
        cout << "UNKNOWN ORDER" << endl;
        exit(1);
    }

    readFileCmd2("../File_text/input.txt", a, n);
    sortArrayTime(algorithm, a, n,time);
    readFileCmd2("../File_text/input.txt", a, n);
    sortArrayComp(algorithm, a, n, cntCompare);  
    writeFileOutputCmd2("../File_text/output.txt", a, n);
    
    if (strcmp(outParam, "-time") == 0){
        cout << "Running time (if required): " << time << endl;
        cout << "Comparisons (if required): " << endl;
    }

    else if (strcmp(outParam, "-comp") == 0){
        cout << "Running time (if required): " << endl;
        cout << "Comparisons (if required): " << cntCompare <<endl;
    }

    else if (strcmp(outParam, "-both") == 0){
        cout << "Running time (if required): " << time << endl;
        cout << "Comparisons (if required): " << cntCompare <<endl;
    }

    else{
        cout << "UNKNOWN OUTPUT PARAMETER\n";
        exit(1);
    }

}