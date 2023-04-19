#include <stdio.h>

typedef struct{
    char nome[100];
    char cpf[100];
}cadastro;

void cadastrar_aluno(cadastro *aluno)
{
    printf("Informe o nome do aluno:\n");
    scanf("%s", aluno->nome);

    printf("Informe o cpf do aluno:\n");
    scanf("%s", aluno->cpf);
}

void imprimir(cadastro *aluno)
{
    printf("Nome do aluno: %s",aluno->nome);
    printf("CPF do aluno: %s",aluno->cpf);
}

int main(int argc, char const **argv){
    cadastro aluno;

    cadastrar_aluno(&aluno);
    imprimir(&aluno);

    return 0;
}
