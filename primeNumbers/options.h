//This file is a helper file for prime.c. For more information of the task, refer to that file.

#ifndef OPTIONS_H
#define OPTIONS_H

struct commandLineOptions
{
        bool isNum;
        int value;
        char *inputFile;
        char *outputFile;
};

struct commandLineOptions readOptions(int argc, char *argv[]);

#endif
