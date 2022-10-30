#pragma once
void readFileCmd1(const char* fileName, int* &a, int &n);
int readCmd1Size(const char* fileName);
void writeFileCmd1(const char* fileName,int *a, int n);
// void sortArray(const char* algorithm, int* &a, int n, long long &cntCompare, long long &time);
// void solveSortCmd1(const char* algorithm, const char* inputFile, const char* output, int* &a, int &n);
void solveCmd1(const char* algorithm, const char* inputFile, const char* outputParam, int* &a, int &n);
