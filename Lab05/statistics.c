/*
    Duncan Stannard 
    C0444224

    Comp 166
    
    Feb 16, 2021

*/

// includes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "statistics.h"

// Mean calculation
double mean(const double sum, const int count){
    return sum/count;
}

// Standard deviation using squared sum 
double ssdev(const double sum, const double sumsq, const int count){
    return(sqrt(((count*sumsq)-pow(sum,2))/(count*(count-1.0))));
}