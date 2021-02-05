/*
    Lab 02: Temperature Conversion

    Your program must:
    1)Prompt for the temperature, e.g., 24.7F
    2)Perform the necessary conversions
    3)Display the temperature in Kelvins, Celsius, and Fahrenheit

    Duncan Stannard C0444224
    Jan 19, 2020

*/

//includes
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Function decleration

int main(void) {
    //variable decleration
    double inputTemp, tempF, tempC, tempK;
    char line[11];  // reserve 11bytes for storage including
    char type;
    // get user input
    printf("~~~~ Temperature Converter ~~~~ \nPlease write your temperature in this format: 59.01f \nEnter Temperature to convert: ");
    scanf("%lf%10s", &inputTemp, line);
    type = line[0];

    switch (type) {
        case 'f':
        case 'F':
            tempF = inputTemp;
            tempC = ((inputTemp - 32.00) * (5.0 / 9.0));
            tempK = tempC + 273.15;
            break;
        case 'k':
        case 'K':
            tempK = inputTemp;
            tempC = (inputTemp - 273.15);
            tempF = (tempC * (9.0 / 5.0)) + 32;
            break;

        case 'c':
        case 'C':
            tempC = inputTemp;
            tempK = tempC + 273.15;
            tempF = (tempC * (9.0 / 5.0)) + 32;
            break;

        default:
            printf("Unknown temperature: %c", type);
            return EXIT_FAILURE;
            break;
    }

    printf("\n~~~~~~~~~~ Converted ~~~~~~~~~~\n%.3lf F   %.3lf C   %.3lf K", tempF, tempC, tempK);

    return EXIT_SUCCESS;
}
