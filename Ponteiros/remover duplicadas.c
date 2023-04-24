#include <stdio.h>
#include <stdlib.h>

remove_duplicadas(int *arr, int size, int *new_size){
    int *result = NULL;

    result = (int*)malloc(size * sizeof(int));
    int j = 0, k = 0;

    for(int i = 0;i < size;i++){
        for(j = 0;j < k;j++)
        {
            if(*(arr + i) == *(result + j)) break;
        }

        if(j == k){*(result + k) = *(arr + i);k++;}
    }

    *new_size = k;
    return result;
}

int main(int argc, char const **argv)
{

    int *arr = NULL;
    int *auxiliary = NULL;
    int size, new_size;
    printf("Informe o tamanho do vetor:\n");
    scanf("%d",&size);

    arr = (int*)malloc(size * sizeof(int));

    printf("Informe os elementos do vetor:\n");
    for(int i = 0;i < size;i++)
        scanf("%d", & *(arr + i));

    auxiliary = remove_duplicadas(arr,size,&new_size);

    printf("duplicadas removidas:\n");
    for(int i = 0;i < new_size;i++)
        printf("%d",*(auxiliary + i));
    printf("\n");

    free(arr);
    free(auxiliary);

    return 0;
}