#include <iostream>
#include "..\File_header\DataGenerator.h"
#include "..\File_header\sortAlgorithm.h"
#include <string.h>
#include "..\File_header\solveCmd1.h"
#include "..\File_header\countTime.h"
#include "..\File_header\solve.h"
using namespace std;

int readCmd1Size(const char* fileName){
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

void readFileCmd1(const char* fileName, int* &a, int &n){
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


void writeFileCmd1(const char* fileName,int *a, int n){
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

void solveCmd1(const char* algorithm, const char* inputFile, const char* outputParam, int* &a, int &n){
    long long cntCompare;
    long long time;

    readFileCmd1(inputFile, a, n);
    sortArrayComp(algorithm, a, n, cntCompare);
    readFileCmd1(inputFile, a, n);
    sortArrayTime(algorithm, a, n, time);

    writeFileCmd1("../File_text/output.txt", a, n);

    if (strcmp(outputParam, "-time") == 0){
        cout << "Running time (if required): " << time << endl;
        cout << "Comparisons (if required): " << endl;
    }

    else if (strcmp(outputParam, "-comp") == 0){
        cout << "Running time (if required): " << endl;
        cout << "Comparisons (if required): " << cntCompare <<endl;
    }

    else if (strcmp(outputParam, "-both") == 0){
        cout << "Running time (if required): " << time << endl;
        cout << "Comparisons (if required): " << cntCompare <<endl;
    }

    else{
        cout << "UNKNOWN OUTPUT PARAMETER\n";
        exit(1);
    }
}