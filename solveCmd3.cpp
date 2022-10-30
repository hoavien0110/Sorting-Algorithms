#include <iostream>
#include "..\File_header\DataGenerator.h"
#include "..\File_header\solve.h"
#include <string.h>
using namespace std;

void writeFileInputCmd3(const char* fileName, int inputSize, int inputOrder, int* &a){
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

void writeAllInputCmd3(int inputSize, int* &a){
    writeFileInputCmd3("../File_text/input_1.txt", inputSize, 0, a);
    writeFileInputCmd3("../File_text/input_2.txt", inputSize, 3, a);
    writeFileInputCmd3("../File_text/input_3.txt", inputSize, 1, a);
    writeFileInputCmd3("../File_text/input_4.txt", inputSize, 2, a);
}

void readFileCmd3(const char* fileName, int* &a, int &n){
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

void solveCmd3(const char* algorithm, const char* inputSize, const char* outputParam, int* &a, int n){
    n = StringToNum(inputSize);

    writeAllInputCmd3(n, a);
    long long cntCompare;
    long long time;

    cout << "\nInput Order: Randomize" << endl;
    cout << "------------------------------" << endl;
    readFileCmd3("../File_text/input_1.txt", a, n);
    sortArrayComp(algorithm, a, n, cntCompare);
    readFileCmd3("../File_text/input_1.txt", a, n);
    sortArrayTime(algorithm, a, n, time);

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

    cout << "\nInput Order: Nearly Sorted" << endl;
    cout << "------------------------------" << endl;
    readFileCmd3("../File_text/input_2.txt", a, n);
    sortArrayComp(algorithm, a, n, cntCompare);
    readFileCmd3("../File_text/input_2.txt", a, n);
    sortArrayTime(algorithm, a, n, time);

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

    cout << "\nInput Order: Sorted" << endl;
    cout << "------------------------------" << endl;
    readFileCmd3("../File_text/input_3.txt", a, n);
    sortArrayTime(algorithm, a, n, time);
    readFileCmd3("../File_text/input_3.txt", a, n);
    sortArrayComp(algorithm, a, n, cntCompare);

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

    cout << "\nInput Order: Reversed" << endl;
    cout << "------------------------------" << endl;
    readFileCmd3("../File_text/input_4.txt", a, n);
    sortArrayTime(algorithm, a, n, time);
    readFileCmd3("../File_text/input_4.txt", a, n);
    sortArrayComp(algorithm, a, n, cntCompare);

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