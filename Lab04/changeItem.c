/*
    changeitem.c library includes the functions: changeItem and getUserInput for lab 4

*/

// includes
#include <stdlib.h>
#include <stdio.h>
#include "changeItem.h"

// get_user_input gets the input from terminal and returns the number
double get_user_input(void) {
    double temp;
    scanf("%lf", &temp);
    return temp;
}

/*
    changeItem takes the value and outputs the amount in denominations
    
    Duncan Stannard
    C0444224
    Feb 16, 2021
*/
double changeItem(double changeTotal, double billAmount, const char *billNames ){
    int totalTender = changeTotal / billAmount;
    if (totalTender > 0) {
            changeTotal = changeTotal - (billAmount * totalTender);
            if (totalTender>1 && billAmount !=20)
            {
                printf("%i %ss \n", totalTender, billNames);
            }
            else if (totalTender>1 && billAmount==20)
            {
                 printf("%i Twenties \n",totalTender);
            }
            else
            {
                printf("%i %s \n", totalTender, billNames);
            }
        }
    
    
    return changeTotal;
}