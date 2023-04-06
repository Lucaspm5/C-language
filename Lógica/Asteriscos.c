#include <stdio.h>

int main(int argc, char **argv){
    int casos;

    scanf("%d",&casos);

    for(int i = 0; i < casos; i++){
        for(int j = 0; j < casos - i; j++)
            printf(" ");
        for(int j = 0; j < i + 1; j++)
            printf("*");
        printf("\n");
    }
    return 0;
}
