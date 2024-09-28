#include <assert.h>
#include <cstring>
#include "KnightSort.h"


void ElemSwap(void* elem1, void* elem2, int elemSize)
{
    int imax = elemSize / 8;
    double buff = 0;
    for (int i = 0; i < imax; i++)
    {
        memcpy((char*)&buff        , (char*)elem1 + i * 8, 8);
        memcpy((char*)elem1 + i * 8, (char*)elem2 + i * 8, 8);
        memcpy((char*)elem2 + i * 8, (char*)&buff        , 8);
        elemSize -= 8;
    }

    imax--;

    for (int i = 0; i < elemSize; i++)
    {
        memcpy((char*)&buff               , (char*)elem1 + imax * 8 + i, 1);
        memcpy((char*)elem1 + imax * 8 + i, (char*)elem2 + imax * 8 + i, 1);
        memcpy((char*)elem2 + imax * 8 + i, (char*)&buff               , 1);
    }
}


int KnightSort(void* firstElem, int elemNum, int elemSize, comparator_t comparator)
{
    assert(elemNum >= 0);

    if (elemNum <= 1)
    {
        return 0;
    }


    int x = -1;
    void * pivot = (char*)firstElem + (elemNum - 1) * elemSize;

    for (int y = 0; y < elemNum; y++)
    {
        if ((*comparator)((char*)firstElem + y * elemSize, pivot) <= 0)
        {
            x++;

            if (x != y)
            {
                ElemSwap((char*)firstElem + y * elemSize, (char*)firstElem + x * elemSize, elemSize);
            }
        }
    }

    KnightSort((char*)firstElem, x, elemSize, comparator);
    KnightSort((char*)firstElem + (x + 1)*elemSize, elemNum - x - 1, elemSize, comparator);
}
