/*
 *  Lab 01: Making change
 *  Lab 1 is the creating a program that makes change using the canadian currency denominations
 *   REQs
 *   1) Prompt for the total purchase price x
 *   2) prompt for the amount tendered x
 *   3) display the total amount of change due x
 *   4) Compute and display the number and type of bills and coins in the change. 
 *   Assume that we have the following denominations: 20,10,5,2,1,25c,10c,5c x
 *
 *   Duncan Stannard C0444224
 *
 *   January, 15, 2021
*/

//Function Declare
double get_user_input(void);

//Includes
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
/*
    main() calls the function get_user_input for both the price of the product
    and the amount paid. main then finds the change due and prints out the result 
    to the terminal.
*/
int main(void) {
    //declare variables
    const double BILLAMOUNT[8] = {20.00f, 10.00f, 5.00f, 2.00f, 1.00f, 0.25f, 0.10f, 0.05f};
    const char *BILLNAMES[8] = {"Twenty", "Ten", "Five", "Twoonie", "loonie", "Quarter", "Dime", "Nickle"}; //char *names// *<- req for c to st ore strings not just single chars
    double price, paid, changeTotal, tempChange;
    int totalTender;

    // User Input
    printf("$$ Change Maker $$ \n");
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
    printf("\nChange Due: $ %.2lf \n", changeTotal);

    // for loop for displaying bill totals
    for (int i = 0; i < 8; i++) {
        totalTender = changeTotal / BILLAMOUNT[i];
        if (totalTender > 0) {
            changeTotal = changeTotal - (BILLAMOUNT[i] * totalTender);
        }
        printf("%i %s \n", totalTender, BILLNAMES[i]);
        totalTender = 0;
    }

    return EXIT_SUCCESS;
}

//Function for getting user input
double get_user_input(void) {
    double temp = 0.0f;
    scanf("%lf", &temp);
    return temp;
}