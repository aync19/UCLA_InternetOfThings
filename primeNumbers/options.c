//This file is a helper file for prime.c. For more information of the task, refer to that file.

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include "options.h"

struct commandLineOptions readOptions(int argc, char *argv[])
{
        struct commandLineOptions clo;
        int opt;
        clo.isNum = true;
        clo.value = 100;

        // put ':' in the starting of the
        // string so that program can
        //distinguish between '?' and ':'
        int numOfDigits;
        while((opt = getopt(argc, argv, ":i:")) != -1)
        {
                switch(opt)
                {
                        case 'i':
                                numOfDigits = strspn(optarg, "0123456789");
                                if(numOfDigits != strlen(optarg))
                                {
                                        clo.isNum = false;
                                }
                                if(clo.isNum)
                                {
                                        clo.value = atoi(optarg);
                                }
                                else
                                {
                                        clo.inputFile = optarg;
                                }
                                break;
                        case ':':
                                printf("option needs a value\n");
                                break;
                        case '?':
                                printf("unknown option: %c\n", optopt);
                                break;
                }
        }

        // optind is for the extra arguments
        // which are not parsed

        if(optind < argc)
        {
                clo.outputFile = argv[optind];
                optind ++;
        }
        else
        {
                perror("Output file not specified");
        }
        //printf("isNum = %d, val = %d, input = %s, output = %s\n",clo.isNum,clo.value,clo.inputFile,clo.outputFile);
        return clo;
}
