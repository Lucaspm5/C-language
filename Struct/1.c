#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ponto{
    float x, y;
};

void imprimir(struct ponto *p)
{
    for (int i = 0;i < 10;i++)
        printf("%.2f - %.2f\n",p[i].x,p[i].y);
}

int main()
{
    struct ponto *p = malloc(10 * sizeof(struct ponto));

    srand ((unsigned)time(NULL));

    for (int i = 0;i < 10;i++)
    {
        p[i].x = rand() % 10;
        p[i].y = rand() % 100;
    }
    imprimir(p);

    free(p);

    return 0;
}
