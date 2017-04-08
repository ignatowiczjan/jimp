//
// Created by janek on 02.04.17.
//

#include "GreatestProduct.h"
#include <limits>

using ::std::vector;

int GreatestProduct(const std::vector<int> &numbers, int k) {
    vector<int> greatest;
    int product = 1;

    int minus = 0;
    bool isallminus = true;


    for (int v : numbers) {
        if (v >= 0) {
            isallminus = false;
            break;
        }
    }


    if (isallminus)
        for (int v : numbers) {
            SpecialOneIfFunction(greatest, v, k);
        }

    else {
        for (int v : numbers) {
            minus = minus + TryToInsert(greatest, v, k);
        }
    }

    for (int v : greatest) {
        product *= v;
    }

    return product;
}




int TryToInsert(vector<int> &greatest, int value, int k) {
    bool inserted = false;
    int minus = 0;
    bool tmp = false;

    if (value < 0) {
        value = (-1) * value;
        tmp = true;
    }
    if (greatest.size() == 0) {
        greatest.push_back(value);
        if(tmp)
            minus = 1;
    } else {
        for (int i = 0; i < greatest.size(); i++) {
            if (value >= greatest[i]) {
                greatest.insert(greatest.begin() + i, value);
                inserted = true;
                if(tmp)
                    minus = 1;
                if (greatest.size() > k) {
                    greatest.pop_back();
                }
                break;
            }
        }
        if (!inserted && greatest.size() < k) {
            greatest.push_back(value);
        }
    }
    return minus;
}


void SpecialOneIfFunction(vector<int> &minus, int value, int k) {
    bool inserted = false;
    if (minus.size() == 0) {
        minus.push_back(value);
    } else {
        for (int i = 0; i < minus.size(); i++) {
            if (value >= minus[i]) {
                minus.insert(minus.begin() + i, value);
                inserted = true;
                if (minus.size() > k) {
                    minus.pop_back();
                }
                break;
            }
        }
        if (!inserted && minus.size() < k) {
            minus.push_back(value);
        }
    }
}