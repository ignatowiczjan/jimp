//
// Created by mwypych on 02.02.17.
//
#include "Factorial.h"

/*
//rekurencyjnie
int factorial(int value) {
  if(value < -12 || value > 12)
    return 0;
  if(value == 1 || value == 0)
    return 1;
  if(value < 0)
    return value * factorial(value + 1);
  if(value > 1)
    return value * factorial(value - 1);
}
*/


//iteracyjnie
int factorial(int value){
  int result=1;
  if(value < -12 || value > 12)
    return 0;
  if(value == 1 || value == 0)
    return 1;
  if(value < 0)
    for(int i=value; i<0; i++)
      result *= i;
  if(value > 1)
    for(int i=1; i<=value; i++)
      result *= i;
  return result;
}