#include <stdio.h>
#include <ctype.h>
#include "StringComparator.h"


int CompareStringInf(const void* arg1, const void* arg2)
{
    int i = 0, j = 0;
    const string_inf* str1 = (const string_inf*)arg1, * str2 = (const string_inf*)arg2;
    while (1)
    {
        if (i == (*str1).len)
        {
            return -1;
        }

        if (j == (*str2).len)
        {
            return 1;
        }

        if (!isalpha((*str1).ptr[i]))
        {
            i++;
            continue;
        }

        if (!isalpha((*str2).ptr[j]))
        {
            j++;
            continue;
        }

        if (tolower((*str1).ptr[i]) == tolower((*str2).ptr[j]))
        {
            i++;
            j++;
            continue;
        }

        if (tolower((*str1).ptr[i]) < tolower((*str2).ptr[j]))
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
}


int CompareReverseStringInf(const void* arg1, const void* arg2)
{
    const string_inf* str1 = (const string_inf*)arg1, * str2 = (const string_inf*)arg2;
    int i = (*str1).len, j = (*str2).len;
    while (1)
    {
        if (i == 0)
        {
            return -1;
        }

        if (j == 0)
        {
            return 1;
        }

        if (!isalpha((*str1).ptr[i]))
        {
            i--;
            continue;
        }

        if (!isalpha((*str2).ptr[j]))
        {
            j--;
            continue;
        }

        if (tolower((*str1).ptr[i]) == tolower((*str2).ptr[j]))
        {
            i--;
            j--;
            continue;
        }

        if (tolower((*str1).ptr[i]) < tolower((*str2).ptr[j]))
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
}


void OneginPrintf(string_inf* stringsInf, int strNum)
{
    for (int i = 0; i < strNum; i++)
    {
        printf("%p | %d | ", stringsInf[i].ptr, i);

        for (int j = 0; j < stringsInf[i].len; j++)
        {
            printf("%c", (stringsInf[i].ptr)[j]);

        }

        printf("\n");
    }
}


void FillStringsInf(char* strings, string_inf * stringsInf, int symbNum)
{
    int strCount = 0, prevI = -1;
    for (int i = 0; i < symbNum; i++)
    {
        if (strings[i] == '\0')
        {
            break;
        }

        if (strings[i] == '\n')
        {
            strings[i] = '\0';
            stringsInf[strCount].len = i - prevI;
            stringsInf[++strCount].ptr = strings + i;
            prevI = i;
        }
    }
}
