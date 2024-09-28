#ifndef __KNIGHT_SORT__
#define __KNIGHT_SORT__

typedef int (* comparator_t) (const void* arg1, const void* arg2);

void ElemSwap(void* elem1, void* elem2, int elemSize);
int KnightSort(void* firstElem, int elemNum, int elemSize, comparator_t comparator);

#endif
