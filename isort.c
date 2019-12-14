#include <stdio.h>
#include "isort.h"

void shift_element(int *arr, int i)
{
    for (int j = i; j > 0; --j)
    {
        *(arr + j + 1) = *(arr + j);
    }
}

void insertion_sort(int *arr, int len)
{
    int key;
    for (int j = 1; j < len; ++j)
    {
        key = *(arr + j);
        int i = j - 1;
        while (i >= 0 && *(arr + i) > key)
        {
            shift_element(arr + i - 1, 1);
            i--;
        }
        *(arr + i + 1) = key;
    }
}