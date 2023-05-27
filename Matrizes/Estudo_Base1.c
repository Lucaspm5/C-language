#include <stdio.h>

int main()
{
    int value, i;
    // Criando um vetor bidmensional de 10 linhas e 2 colunas
    int mat[10][2] = {
        {1,1} ,
        {2,2} ,
        {3,3} ,
        {4,4} ,
        {5,5} ,
        {6,6} ,
        {7,7} ,
        {8,8} ,
        {9,9} ,
        {10,10}
    };
    // Estou procurando um valor na matriz
    scanf("%d", &value);

    // Percorro toda a linha da matriz, procurando o elemento que eu inseri, se achar paro, com isso aonda o value for achado o i foi alterado
    for (i = 0;i < 10;i++)
    {
        if (mat[i][0] == value) break;
    }
    // O valor de i que foi incrementado até achar o valor, pego o elemento do lado dele com a expressão mat[i][1]
    printf("%d\n",mat[i][1]);

    return 0;
}
/*
    Se o value = 1
    o i = 0
    mat[i][1] = o elemento do lado do 1, que é o próprio 1
*/