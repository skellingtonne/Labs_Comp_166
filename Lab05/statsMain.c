/*
    Lab 05: Statistics File
    
    Reqs:   Write a C program that computes simple statistics from a file of ASCII numbers.
            Your program must:
            1) Check for the correct number of command-line arguments X
            2) Get the name of the input file from the command line and try to open that file X
            3) Check that the file was opened successfully and handle the error if not successful. X
            4) Read all of the values in that file while updating the required variables X
            5) NOT use an array for the data X
            6) Check that there was at least two values read from the file X
            7) Display the result to the console X
            8) Write the same result to an output file where the name of that output file is Result_xxx, where “xxx”
            is the name of the input file. You must dynamically allocate memory for a string that holds the
            name of this file. You must also check that this file was opened successfully. X
            9) Close files when you are done with them X
            10) Consist of three files: two source files (statsMain.c, statistics.c) and a header file (statistics.h). X
            11) Use #ifndef to prevent the possibility of multiple inclusions of the header file X
    
    Duncan Stannard 
    C0444224

    Comp 166
    
    Feb 16, 2021

*/

// includes
#include <stdio.h>
#include <libgen.h>
#include <stdlib.h>
#include <string.h>
#include "statistics.h"

// Function Declares
static void printStats (FILE *dest, const int count, const double mean, const double ssdev);

// Defines
#define PREFIX "Result_"

/*
    main takes file name from terminal. Error checks to make sure data is there and file has opened.
    Calls Mean and Standard deviation functions. Outputs to a file using the prefix and original file name as
    new file name
*/
int main(int argc, char **argv)
{
    // Variable Declaratrions
    double tempValues, sampleSums, sampleSumsSq, stdDev;
    int valCount=0;

    // Check for proper amount of input files, exit if not 2 (main and numbers)
    if(argc!=2){
        printf("ERR: Please Enter One File Name\nie: main.exe numbers.txt");
        return(EXIT_FAILURE);
    }

    // File variable, open file given by the argument from terminal
    FILE *inFile = fopen(argv[1],"r");
    // ERR checking, if file could be opened or not
    if(inFile==NULL){
        printf("\n File %s Could not be opened", basename(argv[1]));
        return(EXIT_FAILURE);
    }
    
    // While loop to read out values from the files
    while (fscanf(inFile,"%lf",&tempValues)==1){
        sampleSums+=tempValues;
        sampleSumsSq+=tempValues*tempValues;
        valCount++;
    }
    // ERR checking if more than 2 values are in file or if there was a reading error
    if(valCount<=2){
        printf("\nless than 2 samples in file OR Read error\n");
        return(EXIT_FAILURE);
    }
    // Close the file
    fclose(inFile);

    // Setup variables for mean and std deviation and get the values from the function
    double tempMean=mean(sampleSums,valCount);
    double tempStdDev=ssdev(sampleSums,sampleSumsSq,valCount);
    // output to terminal
    printStats(stdout,valCount,tempMean,tempStdDev);
    // Allocate char size for file name, and setup name
    char *fileOutName=(char *) malloc(strlen(argv[1])+strlen(PREFIX)+1);
    strcpy(fileOutName,PREFIX);
    strcat(fileOutName,argv[1]);

    // output file
    FILE *outFile=fopen(fileOutName,"w+");

    printStats(outFile,valCount,tempMean,tempStdDev);
    // ERR checking if file was created
    if(outFile==NULL){
        printf("\nUnable to open new file \n");
        return EXIT_FAILURE;
    }
    // Cleanup
    fclose(outFile);
    free(fileOutName);
    return(EXIT_SUCCESS);
}


// Format for outputting given for lab
static void printStats (FILE *dest, const int count, const double mean, const double ssdev){
    fprintf(dest,"%i Values, Mean = %.5lf, Sample Standard Deviation = %.5lf",count,mean,ssdev);
}