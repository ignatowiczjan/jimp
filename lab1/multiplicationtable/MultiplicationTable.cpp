//
// Created by janek on 01.04.17.
//

#include "MultiplicationTable.h"
#include <iostream>
using ::std::cout;
using ::std::endl;

void PrintMultiplicationTable(int tab[][10]){
    cout << endl;
    for(int i=0; i<10; i++) {
        for (int j = 0; j < 10; j++)
            printf("%4d|", tab[i][j]);
        cout << endl;
    }
}

void MultiplicationTable(int tab[][10]){
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            tab[i][j] = (i+1)*(j+1);
    PrintMultiplicationTable(tab);
}