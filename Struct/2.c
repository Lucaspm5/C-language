#include <stdio.h>
#include <stdlib.h>

#define AUX1(x) scanf("%d", &x)
#define AUX2(x) scanf("%lf", &x)
// Mini sistema de banco
struct Banco
{
    double saldo_inicial;
    double deposito;
    double sacar;
    double saldo;
};
//-----------------------------------------------------------
void depositar(struct Banco *acesso, int *ptr)
{
    acesso->saldo = acesso->saldo + acesso->deposito;
    *ptr = 2;
}
//-----------------------------------------------------------
void sacar(struct Banco *acesso, int *ptr)
{
    acesso->saldo = acesso->saldo - acesso->sacar;
    *ptr = 1;
}
//-----------------------------------------------------------
void imprimir_saldo(struct Banco *imprimir, int *ptr)
{
    if (*ptr == 1) printf("Valor bancario apos o saque: %.2lf\n", imprimir->saldo);
    if (*ptr == 2) printf("Valor bancario apos o deposito: %.2lf\n", imprimir->saldo);
    //else if (*ptr == 3) printf("Saldo final: %.2lf\n", imprimir->saldo_inicial);
}
//-----------------------------------------------------------
int main()
{
    struct Banco *p = malloc(sizeof(struct Banco));

    int validar = 0;
    int op;

    printf("Informe seu saldo bancario:\n");
    AUX2(p->saldo_inicial);

    p->saldo = p->saldo_inicial;

    while(1 && op != 3)
    {
        printf("Voce deseja (1 - Depositar 2 - Sacar 3 - Finalizar)\n");
        AUX1(op);

        switch(op)
        {
            case 1:
                printf("Quanto voce deseja depositar:\n");
                AUX2(p->deposito);
                depositar(p, &validar);
                break;
            case 2:
                printf("Quanto você deseja sacar:\n");
                AUX2(p->sacar);
                sacar(p, &validar);
                break;
        }

        imprimir_saldo(p, &validar);
    }

    free(p);
}
