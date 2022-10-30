#pragma once
#include <iostream>
using namespace std;

void printArray(int a[], int n);
void swap(int &a, int &b);
int getMax(int a[], int n);
int getMin(int a[], int n);
int StringToNum(const char* s);
void sortArrayComp(const char* algorithm, int* &a, int n, long long &cntCompare);
void sortArrayTime(const char* algorithm, int* &a, int n, long long &time);
string algorithmNameOption(const char* algorithm);
string inputOrderOption(const char* order);
void solveAllCmd(int argc, char** argv, int* &a, int n);
// void initArray(int* a);