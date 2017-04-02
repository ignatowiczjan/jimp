//
// Created by janek on 31.03.17.
//

#include "ReverseString.h"
#include <string>
using ::std::string;



string Reverse(string str){
    string reversed_characters="";
    //const char *characters = str.c_str(); //uzyskanie z obiektu string wskaźnika na poszczególne znaki
    size_t size = str.size(); //uzyskanie z obiektu string ilości znaków

    for(size_t i=0; i<size; i++){
        reversed_characters = str[i] + reversed_characters;
    }
    return reversed_characters;
}