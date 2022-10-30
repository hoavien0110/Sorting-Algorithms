#include <chrono>
#include <iostream>
#include "..\File_header\solve.h"
#include <stdlib.h>
using namespace std::chrono;
using namespace std;

int main(int argc, char** argv){

    int* a;
    int n;
    
    solveAllCmd(argc, argv, a, n);
    if (a != NULL)
        delete[] a;
    return 0;
}