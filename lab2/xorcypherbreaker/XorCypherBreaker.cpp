//
// Created by janek on 02.04.17.
//

#include "XorCypherBreaker.h"
#include <algorithm>
#include <iostream>
using std::find;
using std::vector;
using std::string;




string XorCypherBreaker(const std::vector<char> &cryptogram,
                        int key_length,
                        const std::vector<string> &dictionary) {


    string arr;
    string str = "";
    int counter = 0;
    int ite=0;

    for(int i = 0 ; i < key_length ; i++){
        arr += "a";
    }

    for (int i = 97; i <= 122; i++) {
        arr[0] = char(i);
        for (int j = 97; j <= 122; j++) {
            arr[1] = char(j);
            for (int k = 97; k <= 122; k++) {
                arr[2] = char(k);

                for (const auto &n : cryptogram) {
                    if (ite == key_length)
                        ite = 0;

                    if ((n ^ arr[ite]) == ' ' || (n ^ arr[ite]) == '?' || (n ^ arr[ite]) == '!' ||
                        (n ^ arr[ite]) == '.') {
                        if (DictionarySearch(dictionary, str)) {
                            counter++;
                            ite++;
                            str = "";
                        } else {
                            str = "";
                            ite++;
                        }
                    } else {
                        str += n ^ arr[ite];
                        ite++;
                    }
                }
                if (counter > 17) {
                    return arr;
                } else {
                    counter = 0;
                }
                ite = 0;
            }
        }
    }
    return str;
}


bool DictionarySearch(const vector<string> &dictionary, string suspect){
    int i = 0;
    while(suspect[i] != '\0'){
        suspect[i] = (char) tolower(suspect[i]);
        i++;
    }

    for(string v : dictionary){
        if( !v.compare(suspect) ){
            return true;
        }
    }
    return false;
}