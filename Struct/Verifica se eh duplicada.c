#include <stdio.h>

#define size 5

struct verifica{
    int number;
    int cont;
};

int main()
{
    struct verifica *acesso = (struct verifica*)calloc(size, sizeof(struct verifica));

    int arr[size];

    for (int i = 0;i < size;i++)
        scanf("%d", &arr[i]);

    for (int i = 0;i < size;i++)
    {
        acesso[arr[i]].number = arr[i];
        acesso[arr[i]].cont++;
    }
    
    for (int i = 0;i < size;i++)
    {
        if (acesso[i].cont > 1)
            printf("%d",acesso[i].number);
    }

    return 0;
}