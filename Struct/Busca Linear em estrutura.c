#include <stdio.h>

#define size 5

struct Busca{
    int chave;
};

int Buscar_elemento(struct Busca *auxiliary, int k)
{
    for (int i = 0;i < size;i++)
    {
        if (auxiliary[i].chave == k)
        {
            return i;
        }    
    } 
    return 0;
}

int main()
{
    struct Busca auxiliary[size];

    int k;

    for (int i = 0;i < size;i++)
        scanf("%d", &auxiliary[i].chave);

    scanf("%d", &k);

    int validar = Buscar_elemento(auxiliary, k);

    if(!validar) printf("Valor nao encontrado\n");
    else
        printf("Valor encontrado no indice %d\n",validar);

    return 0;
}