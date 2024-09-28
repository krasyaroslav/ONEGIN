#ifndef __String_Comparator__
#define __String_comparator__

struct string_inf
{
    int len;
    char* ptr;
};

void OneginPrintf(string_inf* stringsInf, int strNum);
int CompareStringInf(const void* arg1, const void* arg2);
int CompareReverseStringInf(const void* arg1, const void* arg2);
void FillStringsInf(char* strings, string_inf * stringsInf, int symbNum);

#endif
