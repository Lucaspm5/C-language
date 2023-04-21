#include <stdio.h>

int fatorial(int x){
    if(x == 0 || x == 1)
        return 1;
    else
        return x*fatorial(x-1);
}

int main(int argc, char const **argv){
    int fac;

    scanf("%d",&fac);
    
    int auxiliary = fatorial(fac);

    printf("!%d = %d",fac,auxiliary);
    return 0;
}