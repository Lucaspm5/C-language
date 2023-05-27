#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[1000];
    int minutos;
} Avistamento;

int compare(const void* a, const void* b)
{
    Avistamento *avistamentoA = (Avistamento *)a;
    Avistamento *avistamentoB = (Avistamento *)b;
    return avistamentoA->minutos - avistamentoB->minutos;
}

int main()
{
    int temp_aproximacao, size;

    scanf("%d %d", &temp_aproximacao, &size);

    char horario[size][1000];
    Avistamento avistamentos[size];
    int horas, minutos;

    for (int i = 0; i < size; i++)
    {
        scanf("%s %s", horario[i], avistamentos[i].nome);
        sscanf(horario[i], "%d:%d", &horas, &minutos);
        avistamentos[i].minutos = horas * 60 + minutos;
        if (avistamentos[i].minutos >= 23 * 60)
            avistamentos[i].minutos -= 24 * 60;
    }

    qsort(avistamentos, size, sizeof(Avistamento), compare);

    for (int i = 0; i < size; i++)
    {
        if (abs(avistamentos[i].minutos) <= temp_aproximacao)
            printf("%s\n", avistamentos[i].nome);
    }

    return 0;
}
