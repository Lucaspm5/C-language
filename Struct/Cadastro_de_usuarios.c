#include <stdio.h>

#define MAX_USUARIOS 100

typedef struct{
    char nome[100];
    char matricula[100];
    int numero_usuario;
}cadastro;

//---------------------------------------------------
cadastro lista_usuarios[MAX_USUARIOS];
int numero_usuarios = 0;
//---------------------------------------------------

void cadastrar_aluno()
{
    int valido = 1;
    int validacao;

    for(int i = 0; i < MAX_USUARIOS && valido; i++)
    {
        printf("Informe o nome do aluno(a):\n");
        scanf("%s", lista_usuarios[numero_usuarios].nome);

        printf("Informe a matricula do aluno(a):\n");
        scanf("%s", lista_usuarios[numero_usuarios].matricula);

        printf("Deseja finalizar o cadastro 1-sim 2-nao:");
        scanf("%d", &validacao);

        if(validacao == 1) valido = 0;

        numero_usuarios++;
    }
}

//---------------------------------------------------

void imprimir()
{
    for(int i = 0; i < numero_usuarios; i++)
    {
        printf("Nome do aluno: %s\n", lista_usuarios[i].nome);
        printf("CPF do aluno: %s\n", lista_usuarios[i].matricula);
    }
}

//---------------------------------------------------

void imprimir_numero_usuarios()
{
    printf("Numero de usuarios do sistema: %d\n", numero_usuarios);
}

//---------------------------------------------------

int main(int argc, char const **argv)
{
    cadastrar_aluno();
    imprimir();
    imprimir_numero_usuarios();

    return 0;
}
