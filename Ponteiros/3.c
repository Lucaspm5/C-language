#include <stdio.h>
#include <stdlib.h>
// duplica os zeros caso tiver, e afasta o elemento em sequencia
int *duplicateZeros(int* arr, int arrSize)
{
    for(int i = 0;i < arrSize;i++)
    {
        if(*(arr + i) == 0)
        {
            for(int j = arrSize - 1;j > i;j--)
            {
                *(arr + j) = *(arr + j - 1);
            }
            i++;
        }
    }

    return arr;
}

int main(int argc, char const **argv)
{
    int arrSize;

    scanf("%d", &arrSize);

    int *arr = (int*)malloc(arrSize * sizeof(int));

    for(int i = 0; i < arrSize; i++)
        scanf("%d", &*(arr + i));

    duplicateZeros(arr, arrSize);

    for(int i = 0; i < arrSize; i++)
        printf("%d ", *(arr + i));

    return(arr);

    return 0;
}