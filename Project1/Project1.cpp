

#include <stdio.h> // provides declarations for printf and putchar
#include <stdint.h> // provides declarations for int32_t uint32_t and the other (new) standard C types
#include <string.h>

/*
All of your code must be in this file. Please no #includes other than standard system headers (ie.., stdio.h, stdint.h)

You must write this function (printSuperStrings). Do not change the way the function is declared (i.e., it has
exactly two parameters, each parameter is a standard (mundane) C string (see Instruction).
*/

void printSuperStrings(char targets [], char candidates []) {

    char test[30];
    char compare[30];
    char candidates2[1000];
    strcpy(candidates2, candidates);
    int i = 0;
    while (targets[i] != '\0') {
        int w = 0;
        while (!(targets[i] == ' ' || targets[i] == '\0' || targets[i] == '\n') ) {
            test[w] = targets[i];
            i++;
            w++;
        }
        test[w] = '\0';
        for (int o = w + 1; o < 30; o++){
            test[o] = 33;
        }


        //printf("target: %s\n", test);
        char delimit[] = " \t\r\n\v\f";
        strcpy(candidates2, candidates);
        char *newString = strtok(candidates2, delimit);
        while (newString != NULL) {
            strcpy(compare, newString);
            int count = 0;
            int count2 = 0;
            while(compare[count] != '\0'){
                if(compare[count] == test[count2]){
                    count2++;
                }
                count++;
            }
            if (w == count2){
                printf("%s\n", newString);
            }
            //printf("candidate: %s\n", newString);
            newString = strtok(NULL, delimit);
        }
        if (targets[i] == '\0') {
            i--;
        }
        i++;
    }

}

