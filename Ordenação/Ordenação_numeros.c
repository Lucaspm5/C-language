#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) 
{
    return (*(int*)b - *(int*)a);
}

int main(int argc, char const **argv) 
{
    int *arr = (int*)malloc(10 * sizeof(int));

    for(int i = 0;i < 10;i++){
        scanf("%d",&*(arr + i));
    }

    qsort(arr, 10, sizeof(int), compare);

    for(int i = 0; i < 10; i++) 
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    return 0;
}
