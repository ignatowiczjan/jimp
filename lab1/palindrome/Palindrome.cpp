//
// Created by janek on 01.04.17.
//

#include "Palindrome.h"
#include <string>

using ::std::string;

bool is_palindrome(string str){
    for(int i=0; i<str.length(); i++)
        if(str[i] != str[str.length()-1-i])
            return false;
    return  true;
}