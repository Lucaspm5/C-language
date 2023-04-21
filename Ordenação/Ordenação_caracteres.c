#include <stdio.h>
#include <stdlib.h>

char compare(const void *a, const void *b)
{
    return (*(char*)a - *(char*)b);
}
int main(int argc, char const **argv)
{
    char *str[] = {"apple", "banana", "cebola", "dinamite"};

    int size = sizeof(str) / sizeof(char*);

    qsort(str, size, sizeof(char*), compare);

    for(int i = 0;i < size;i++){
        printf("%s\n", str[i]);
    }
    return 0;
}