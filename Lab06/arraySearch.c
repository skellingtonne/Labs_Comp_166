/*
Duncan Stannard C0444224
March 11, 2021
Comp 166 Lab 06
*/
#include <stdlib.h>
#include <stdio.h>
#include "arraySearch.h"

// check if the value is the same as the number in the array, return the position of return -1 indicating no value found
int linearSearch (const int value, const int numbers[], const int nNumbers){
    for(int i=0;i<nNumbers;i++){
        if(value == numbers[i]){
            return i;
        }
    }
    return -1;
}