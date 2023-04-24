#include <stdio.h>
#include <string.h>

int main(int argc, char const **argv){

    char str[100];

    scanf("%[^\n]s",str);

    int size = strlen(str);

    char abertura[] = {"([{"};
    char fechamento[] = {")]}"};

    int auxiliary[100];
    int verificacion = -1;
    int valido = 1;

    for(int i = 0;i < size;i++){
        for(int j = 0;j < 3;j++){
            if(str[i] == abertura[j]) {auxiliary[++verificacion] = str[i];}
            else if(str[i] == fechamento[j])
            {
                if(verificacion == -1){valido = 0; break;}
                verificacion--;
            }
        }
    }

    if(valido && verificacion == -1) printf("True\n");
    else printf("False\n");

    return 0;
}