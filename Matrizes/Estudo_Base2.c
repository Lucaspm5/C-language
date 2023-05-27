#include <stdio.h>

int main()
{
    // Crio uma array de strings com capacidade de 99 caracteres, para 5 nomes
    char nome[5][100];
    // Utilizo um for para sobrescrever cada nome em uma linha
    for (int i = 0;i < 5;i++)
        scanf("%s", nome[i]);
    // Imprimo o nome 2
    printf("%s\n",nome[2]);

    return 0;
}