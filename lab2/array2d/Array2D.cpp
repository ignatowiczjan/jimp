//
// Created by janek on 02.04.17.
//

#include "Array2D.h"
#include <iostream>


void FillArray2D(int n_rows, int n_columns, int **array) {
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_columns; j++) {
            *(*(array + i) + j) = (i * n_columns) + j + 1;
        }
    }
}


int **NewArray2D(int n_rows, int n_columns) {
    if(n_rows<=0 || n_columns<=0)
        return nullptr;

    int **array = new int *[n_rows];
    int tmp=1;

    for (int i = 0; i < n_rows; i++) {
        *(array + i) = new int[n_columns];
        for(int j=0; j< n_columns; j++){
            array[i][j] = tmp;
            ++tmp;
        }
    }

    return array;
}

void DeleteArray2D(int **array, int n_rows, int n_columns) {
    for (int i = 0; i < n_rows; i++) {
        delete[] *(array + i);
    }
    delete[] array;
}



void PrintArray2D(int **array, int n_rows, int n_columns) {
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_columns; j++) {
            std::cout << "element (" << j << ", " << i << ")" << std::endl;
        }
        std::cout << std::endl;
    }
}