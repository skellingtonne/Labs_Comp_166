/*
Duncan Stannard C0444224
March 11, 2021
Comp 166 Lab 06

Requirements Write a C program that reads in a file containing binary integers and then search for a user-specified number.
Your program must:
1)Check for the correct number of command-line arguments (i.e., three) X
2)Get the name of the input file from the command line and try to open that file X
3)Check that the file was opened successfully and handle the error if not. X
4)Get the number of numbers from the command line. X
5)Read all of the values in that file into an array using a single fread() X
6)Repeatedly prompt the user for a number for which to search X
7)Linearly search the array and, if found print the location index of the number.  Otherwise, print a “not found” message.   X
Display the result to the console
8) Close the input file when you are done reading the data X
9) Consist of three files:  two source files (searchMain.c, arraySearch.c) and a header file (arraySearch.h). X
    a)The following function must be in arraySearch. c Search an array for a given value.  
        * A linear search is used, so the data need not be sorted  
        * Returns: the zero-based index of the number (if found)          
        * otherwise -1 
        * int linearSearch (const int value, const int numbers[], const int nNumbers)
        *  Do NOT print from inside of this function!
    * b)The loop for prompting the user (and printing) must be in main()
10) Use #ifndef to prevent the possibility of multiple inclusions of the header file X
*/

// includes
#include <stdio.h>
#include <libgen.h>
#include <stdlib.h>
#include "arraySearch.h"

int main(int argc, char *argv[])
{
    // Variables
    int userSize,userNumber,positionVal;
    char tempChar[10];
    // Check for proper amount of input files, exit if not 3 (main numbers and specified #)
    if(argc!=3){
        printf("ERR: Please Enter One File Name and the amount of numbers wanted\nie: main.exe numbers.txt 7");
        return(EXIT_FAILURE);
    }else if (sscanf(argv[2],"%d",&userSize)!=1){ //ERR checking for converting the user entered number for size
        printf("\nUser number read error: %s could not be converted to an int\n",argv[2]);
        return(EXIT_FAILURE);
    }
    

    //open file in Read Binary mode so it doesn't end at breaks
    FILE *inFile = fopen(argv[1],"rb");
    // ERR checking, if file could be opened or not
    if(inFile==NULL){
        printf("\n File %s Could not be opened", basename(argv[1]));
        return(EXIT_FAILURE);
    }

    int *numberArray = (int*) malloc(userSize * sizeof(int)); // setup array for specified user size
    // Read the values out to the array
    fread(numberArray,sizeof(int),userSize,inFile);
    fclose(inFile);
    // while loop that will exit if q or Q is entered into the 
    while(1){
        //User Prompt
        printf("\nEnter the integer value to find ('q' to quit): ");
        //Scan terminal limit to 9 + null, should not require more as the vals are -4096 to 4096
        scanf("%s",&tempChar);
        if(tempChar[0]=='q' || tempChar[0]=='Q'){
            printf("\nBye");
            return EXIT_SUCCESS;
        }
        //Scan str to int 
        sscanf(tempChar,"%d",&userNumber);
        //Get the position in the array
        positionVal = linearSearch(userNumber, numberArray,userSize);
        // If the value does not exist then not found, if it is print out number and position
        if(positionVal==-1){
            printf("\n%i was not found",userNumber);
        }else{
            printf("\n%i was found at %i",userNumber,positionVal);
        }
        
    }
    printf("\nBye");
    return EXIT_SUCCESS;
}
