#include <stdio.h>
#include <stdlib.h>

struct Ponto
{
    int x, y;
};
//-----------------------------------------------------------
void duplica(struct Ponto *duplic)
{
    for (int i = 0;i < 5;i++)
    {
        duplic[i].x *= duplic[i].x;
        duplic[i].y *= duplic[i].y;
    }
}
//-----------------------------------------------------------
void imprimir(struct Ponto *imprim)
{
    for (int i = 0;i < 5;i++)
        printf("%d - %d\n",imprim[i].x,imprim[i].y);
}
//-----------------------------------------------------------
void entrada_valor(struct Ponto *ent)
{
    for (int i = 0;i < 5;i++)
        scanf("%d", &ent[i].x);
    for (int i = 0;i < 5;i++)
        scanf("%d", &ent[i].y);
}
//-----------------------------------------------------------
int main()
{
    struct Ponto *p;

    p = (struct Ponto*)malloc(5 * sizeof(struct Ponto));

    entrada_valor(p);
    duplica(p);
    imprimir(p);

    free(p);

    return 0;
}