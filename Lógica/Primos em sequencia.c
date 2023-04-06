#include <stdio.h>
#include <math.h>

int isPrimo(int x){
    if(x <= 1)
        return 0;
    if(x == 2)
        return 1;

    for(int i = 2; i <= sqrt(x);i++){
        if(x % i == 0){
            return 0;
        }
    }
    return 1;
}

int main(int argc, char **argv){
    int size;
    scanf("%d",&size);

    for(int i = 2; i < size; i++){
        if(isPrimo(i)){
            printf("%d ",i);
        }
    }
    return 0;
}
