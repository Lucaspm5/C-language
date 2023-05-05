#include <stdio.h>
#include <stdlib.h>

//Eleva ao quadrado e depois ordena em ordem crescente
int compare (const void *a,const void *b)
{
    return (*(int*)a - *(int*)b);
}

int *sortedSquares (int* nums, int numsSize, int* returnSize)
{
    int *result = NULL;

    result = (int*)malloc(numsSize * sizeof(int));

    for (int i = 0;i < numsSize;i++)
    {
        *(result + i) = *(nums + i) * *(nums + i);
    }

    qsort (result, numsSize, sizeof(int), compare);

    *returnSize = numsSize;

    return result;
}

int main(int argc, char const **argv)
{
    int arrSize;
    int size;

    scanf("%d", &arrSize);

    int *arr = NULL;

    arr = (int*)malloc(arrSize * sizeof(int));

    for (int i = 0;i < arrSize;i++)
        scanf("%d", &*(arr + i));

    int *aux = sortedSquares(arr, arrSize, &size);

    for (int i = 0;i < size;i++)
        printf("%d ", aux[i]);

    free(arr);

    return 0;
}