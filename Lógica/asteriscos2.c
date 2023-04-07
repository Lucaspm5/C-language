#include <stdio.h>

int main(int argc, char **argv){
    
    int casos;

    scanf("%d", &casos);

    for(int i = 0;i < casos;i++){
        for(int j = i;j < casos;j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}