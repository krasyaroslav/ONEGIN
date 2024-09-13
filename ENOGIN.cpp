#include <stdio.h>
#include <stdlib.h>

void StrSort(char** dataPtr, int strNum);
int CompareStr(char* a, char* b, int lenA, int lenB);

int main()
{
    FILE* fileP = fopen("text.txt", "r");

    int charr = 0, strNum = 0, charNum = 0;

    while ((charr = getc(fileP)) != EOF)
    {
        if (charr == '\n')
        {
            strNum++;
        }
        charNum++;
    }

    fseek(fileP, 0, SEEK_SET);

    char** strPtr = (char**)calloc(strNum+1, sizeof(char*));
    char* strs = (char*)calloc(charNum, sizeof(char));

    strPtr[0] = strs;
    int strLen = 0, strCount = 1;

    printf("Read log:\n");

    for (int i = 0; i < charNum; i++)
    {
        charr = getc(fileP);

        strs[i] = charr;

        printf("%c", charr);

        strLen++;

        if (charr == '\n')
        {
            printf("strCount = %d\nstrLen = %d\n\n", strCount, strLen);
            strPtr[strCount] = strPtr[strCount-1] + strLen;

            strCount = strCount+1;
            strLen = 0;
        }
    }
    fclose(fileP);

    printf("Normal\n");
    for (int i = 0; i < strNum; i++)
    {
        for (int j = 0; j < (strPtr[i+1]-strPtr[i])/(int)sizeof(char); j++)
        {
            printf("%c", *(strPtr[i]+j));
        }
    }

    StrSort(strPtr, strNum);

    printf("\nSorted\n");
    for (int i = 0; i < strNum; i++)
    {

        for (int j = 0;; j++)
        {
            printf("%c", *(strPtr[i]+j));

            if (*(strPtr[i]+j) == '\n')
            {
                break;
            }
        }
    }
}

void StrSort(char** dataPtr, int strNum)
{
    char* bufer = 0;

    for (int i = 1; i < strNum; i++)
    {
        for (int j = 0; j < strNum - i; j++)
        {
            if (CompareStr(dataPtr[j], dataPtr[j+1], (dataPtr[j+1]-dataPtr[j])/(int)sizeof(char*), (dataPtr[j+2]-dataPtr[j+1])/(int)sizeof(char*)) < 0)
            {
                bufer = dataPtr[j+1];
                dataPtr[j+1] = dataPtr[j];
                dataPtr[j] = bufer;
            }
        }
    }

}


int CompareStr(char* a, char* b, int lenA, int lenB)
{
    for (int i = 0; i < lenA; i++)
    {
        if (i == lenA-1 && i < lenB)
        {
            return 1;
        }
        if (i == lenA-1 && i == lenB)
        {
            return 0;
        }
        if (i == lenA-1 && i > lenB)
        {
            return -1;
        }

        if (a[i] < b[i])
        {
            return 1;
        }
        if (a[i] > b[i])
        {
            return -1;
        }
    }
}


