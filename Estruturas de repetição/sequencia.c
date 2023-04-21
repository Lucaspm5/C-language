#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
    for(int i = 1;i <= 10;i++)
    {
        for(int j = 1;j <= i;j++){
            printf("%d",i);
            printf(" ");
        }
        printf("\n");
    }
        
    return 0;
}