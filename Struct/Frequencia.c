#include <stdio.h>
#include <stdlib.h>

#define size 5

struct frequencia{
    int number;
    int cont;
};

int main()
{
    struct frequencia *acesso = (struct frequencia*)calloc(size, sizeof(struct frequencia));

    int arr[size];

    for (unsigned i = 0;i < size;i++)
        scanf("%d", &arr[i]);

    for (unsigned i = 0;i < size;i++)
    {
        acesso[arr[i]].number = arr[i];
        acesso[arr[i]].cont++;
    }

    for (unsigned i = 0;i < size;i++)
    {
        if(acesso[arr[i]].cont == 1)
            printf("%d\n",acesso[arr[i]].number);
    }

    free(acesso);
    
    return 0;
}