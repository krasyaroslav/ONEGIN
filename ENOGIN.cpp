#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <assert.h>
#include <ctype.h>
#include "KnightSort.h"
#include "StringComparator.h"


int main()
{
    FILE* filePtr = fopen("EugeneOnegin.txt", "r"); // open check
    struct stat fileStat = {};
    fstat(fileno(filePtr), &fileStat);

    //printf("number of symbols = %d\n\n", fileStat.st_size);

    char* strings = (char*)calloc(fileStat.st_size + 1, sizeof(char));
    int symbNum = fread(strings, sizeof(char), fileStat.st_size, filePtr);

    //printf("fread (..., %d, ...) returned %d\n", fileStat.st_size, nRead);

    int strNum = fileStat.st_size - symbNum;

    for (int i = symbNum + 1; i < fileStat.st_size; i++)
    {
        strings[i] = '\0';
    }

    printf("number of strings = %d\n\n", strNum);

    string_inf* stringsInf = (string_inf*)calloc(strNum, sizeof(string_inf));   // zero struct
    stringsInf[0].ptr = strings;

    FillStringsInf(strings, stringsInf, symbNum);

    KnightSort(stringsInf, strNum, sizeof(string_inf), &CompareReverseStringInf);

    OneginPrintf(stringsInf, strNum);

    fclose(filePtr);
    free(stringsInf);
    free(strings);
}
