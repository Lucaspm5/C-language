#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
    int size;

    srand((unsigned)time(NULL));

    scanf("%d", &size);
    // Gera um número fracionário aleatório entre 0 e 1
    while(size--)
    {
        int aleatorio = rand() % RAND_MAX;
        double numero_aleatorio = (double) rand() / RAND_MAX;

        printf("%d%lf", aleatorio, numero_aleatorio);
        printf("\n");
    }
    

    return 0;
}
