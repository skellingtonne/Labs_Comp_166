/*
   Lab 04: Making change Functions
   
   Lab 4 is the creating a program that makes change using the canadian currency denominations with seperate files for functions
    REQs
        1) Prompt for the total purchase price
        2) Prompt for the amount tendered
        3) Display the total amount of change due
        4) Compute and display the number and types of bills and coins in the change. 
        Assume that we have the following denominations: $20, $10, $5, $2, $1, 25¢, 10¢, and 5¢.
        5) Store all of the currency values and the denomination names in arrays.
        6) Repeatedly use the function changeItem() in a for loop.
        7) Consist of three files: two source files (makeChange.c, changeItem.c) and a header file
        (changeItem.h).
        8) Use #ifndef to prevent multiple inclusions of the header file
        9) Remember to include your header file in your changeItem.c so that the compiler will complain (in a
        convenient place) if you did not implement what you promised. You should always include
    Duncan Stannard C0444224
 
    Feb, 12, 2021
*/

//Defines
#define N_CURRENCY 8

//Includes
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "changeItem.h"

/*
    main() calls the function get_user_input for both the price of the product
    and the amount paid. main then finds the change due and calls 
    changeItem() to print out the result to the terminal.
*/
int main(void) {
    //declare variables
    const double BILLAMOUNT[N_CURRENCY] = {20.00, 10.00, 5.00, 2.00, 1.00, 0.25, 0.10, 0.05};
    const char *BILLNAMES[N_CURRENCY] = {"Twenty", "Ten", "Five", "Twoonie", "loonie", "Quarter", "Dime", "Nickel"}; //char *names// *<- req for c to st ore strings not just single chars
    double price, paid, changeTotal, tempChange;
    int totalTender;

    // User Input
    printf("$$ Change Maker 2.0 $$ \n");
    printf("Price of product: $ ");
    price = get_user_input();
    printf("\nPaid Amount: $ ");
    paid = get_user_input();

    //Error Handling
    if (paid < price) {
        printf("\nYou need more money\n");
        return EXIT_FAILURE;
    }

    //Change calculation
    changeTotal = paid - price;
    printf("Change Due: $ %.2lf",changeTotal);
    //Find the rounded change to nearest 0.05
    tempChange = fmod(changeTotal, 0.05);  // fmod used to find remainder of division

    // round down if fmod is greater than 0 or less than 0.025 (0.05/2) ie 0.01,0.02, 0.06, 0.07
    if (tempChange < 0.025 && tempChange > 0.00) {
        changeTotal -= tempChange;
    }
    // round up if fmod is greater than 0.025 and less than 0.045 ie 0.03, 0.04, 0.08, 0.09
    else if (tempChange > 0.025 && tempChange < 0.045) {
        changeTotal += (0.05f - tempChange);
    }
    // Display change due
    printf("\nChange Due to nearest nickel: $ %.2lf \n", changeTotal);

    // for loop for displaying bill totals
    for (int i = 0; i < N_CURRENCY; i++) {
       changeTotal= changeItem(changeTotal,BILLAMOUNT[i],BILLNAMES[i]);
    }

    return EXIT_SUCCESS;
}