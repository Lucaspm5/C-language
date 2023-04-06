#include <stdio.h>
#include <math.h>

int isPrimo(int x){
    if(x <= 1)
        return 0;
    
    for(int i = 2; i <= sqrt(x);i++){
        if(x % i == 0){
            return 0;
        }else{
            return 1;
        }
    }
}
int main(int argc, char **argv){
    int size;

    scanf("%d",&size);

    for(int i = 0;i < size;i++){
        if(isPrimo(i)){
            printf("%d ",i);
        }
    }
    return 0;
}