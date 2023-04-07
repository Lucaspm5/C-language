#include <stdio.h>
#include <math.h>

int main() {
    int a, b;
    int centro_x = 30;
    int centro_y = 15;

    printf("Digite o valor do eixo maior (a): ");
    scanf("%d", &a);

    printf("Digite o valor do eixo menor (b): ");
    scanf("%d", &b);

    for(int y = centro_y - b; y <= centro_y + b; y++){
        for(int x = centro_x - a; x <= centro_x + a; x++){
            double dentro_elipse = pow(x - centro_x, 2) / pow(a, 2) 
            + pow(y - centro_y, 2) / pow(b, 2);
            if(dentro_elipse <= 1.0){
                printf("*");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
