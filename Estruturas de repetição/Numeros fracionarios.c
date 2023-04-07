#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
    int size;

    srand((unsigned)time(NULL));

    scanf("%d", &size);

    while(size--)
    {
        int aleatorio = rand() % RAND_MAX;
        double numero_aleatorio = (double) rand() / RAND_MAX;

        printf("%d%lf", aleatorio, numero_aleatorio);
        printf("\n");
    }
    

    return 0;
}
