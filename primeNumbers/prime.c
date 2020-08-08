//This code relies on the header file options.h and the c file options.c to accomplish the following task given to me:

/*
In the base system, when you execute ./prime <OUTPUT_FILE>, 
all prime numbers less than 100 should be printed in OUTPUT_FILE. 
Beyond the base system, the user should also be able to include the following options when executing:

-i N All prime numbers less than N are printed in the provided output file; 
for simplicity, the smallest prime number for this assignment is defined as 2.

-i File You may assume that the name File in question is not purely numeric; 
this option, when included, should print all the prime numbers that are contained in File to the provided output file. 
Numbers in File should be positive integers, one per line (no initial spacing). 
For example, if you construct a file named testing in the same directory as your C file system,
executing ./prime -i testing <OUTPUT_FILE> should print all the prime numbers in testing in <OUTPUT_FILE>, one per line (no initial spacing).

For this assignment, you should construct two new source files (prime.c and options.c) and a header file (options.h). 
Your options.c file MUST use the getopt() function described in the attached link, 
which is frequently used in various C programs.
*/

#include <stdio.h>
#include <stdbool.h>
#include "options.h"

bool isPrime(int num)
{       
        if(num < 2)
        {       
                return false;
        }
        for(int i = 2; i < num; i++)
        {       
                if(num % i == 0)
                {       
                        return false;
                }
        }
        return true;
}


void generatePrimes1(int y, char *file)
{
        FILE *fp = fopen(file, "w");
        if(fp == NULL)
        {
                perror("Could not open output file");
        }
        for(int i = 2; i < y; i++)
        {
                if(isPrime(i))
                {
                        fprintf(fp, "%d\n", i);

                }
        }
        fclose(fp);
}

void generatePrimes2(char *inputFile, char *outputFile)
{

        FILE *inFile = fopen(inputFile, "r");
        FILE *outFile = fopen(outputFile, "w");
        if(inFile == NULL)
        {
                perror("Could not open input file");
        }
        if(outFile == NULL)
        {
                perror("Could not open output file");
        }
        while(1)
        {
                if(feof(inFile))
                {
                        break;
                }

                int num;
                int returnVal = fscanf(inFile, "%d", &num);
                if(returnVal != 1)
                {
                        continue;
                }
                if(isPrime(num))
                {
                        fprintf(outFile, "%d\n", num);
                }

        }
        fclose(inFile);
        fclose(outFile);
}

int main(int argc, char *argv[])
{
        struct commandLineOptions clo;
        clo = readOptions(argc, argv);
        if(clo.isNum)
        {
                generatePrimes1(clo.value, clo.outputFile);
        }
        else
        {
                generatePrimes2(clo.inputFile, clo.outputFile);
        }
}
