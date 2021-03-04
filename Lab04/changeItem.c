/*
    Duncan Stannard
    C0444224
    Feb 16,2021
        
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
    changeItem takes the value of the total change, calculates the amount of bills required, outputs the amount in denominations,
    and returns the new total change amount
*/
double changeItem(double changeTotal, double billAmount, const char *singleName, const char *pluralName){
    int totalTender = changeTotal / billAmount;
    if (totalTender > 0) {
            changeTotal = changeTotal - (billAmount * totalTender);
            if (totalTender>1)
            {
                printf("%i %s \n", totalTender, pluralName);
            }
            else
            {
                printf("%i %s \n", totalTender, singleName);
            }
        }
    
    
    return changeTotal;
}