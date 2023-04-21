#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b)
{
    return strcmp(*(const char**)a, *(const char**)b);
}

int main(int argc, char const **argv)
{
    char **str = (char**)malloc(5 * sizeof(char*));
    
    for(int i = 0; i < 5; i++)
    {
        *(str + i) = malloc(20 * sizeof(char));
        scanf("%s", *(str + i));
    }

    qsort(str, 5, sizeof(char*), compare);

    for(int i = 0; i < 5; i++)
        printf("%s\n", *(str + i));


    for(int i = 0; i < 5; i++)
        free(*(str + i));

    return 0;
}
