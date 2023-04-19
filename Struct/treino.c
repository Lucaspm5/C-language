#include <stdio.h>
#include <string.h>

void buscaPadrao(char P[], char T[])
{

    int size_t = strlen(T);
    int size_p = strlen(P);

    for(int i = 0; i < size_t; i++)
    {
        int found = 1;

        for(int j = 0; j < size_p && found; j++){
            if (i + j >= size_t || P[j] != T[i + j]){
                found = 0;
            }
        }
        if(found) printf("P is found at index %d in T\n", i);
        if(found == 0) printf("P is not found\n");
    }
}

int main(int argc, char const **argv)
{
    char T[100];
    char P[100];

    fgets(T , 100, stdin);
    T[strcspn(T, "\n")] = '\0';

    fgets(P, 100, stdin);
    P[strcspn(P, "\n")] = '\0';

    buscaPadrao(P, T);

    return 0;
}
