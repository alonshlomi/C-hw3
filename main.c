#include <stdio.h>
#include "isort.h"

int main()
{

    int arr[ARR_SIZE];
    int len = ARR_SIZE;
    printf("Insert 50 numbers:\n");
    for (int i = 0; i < ARR_SIZE; i++)
    {
        scanf(" %d", &arr[i]);
    }

    insertion_sort(arr, len);

    for (int i = 0; i < len; ++i)
    {
        printf("%d", arr[i]);
        if (i != len - 1)
        {
            printf(",");
        }
    }
    printf("\n");

    return 0;
}