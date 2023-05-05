#include <stdio.h>
//conta os digitos e se os digitos do vetor tiverem casas pares adiciona ao contador
int conta_par(int *nums, int numsSize)
{
    int repets = 0;

    for(int i = 0;i < numsSize;i++)
    {
        int cont = 0;
        while(*(nums + i) != 0)
        {
            *(nums + i) /= 10;
                cont++;
        }

        if(cont % 2 == 0) repets++;
    }
    return repets;
}

int main(int argc, char const **argv)
{
    int *arr = NULL;
    int arrSize;

    scanf("%d", &arrSize);

    arr = (int*)malloc(arrSize * sizeof(int));

    for(int i = 0;i < arrSize;i++)
        scanf("%d", &*(arr + i));

    int aux = conta_par(arr,arrSize);

    printf("%d\n",aux);

    return 0;
}