#include <stdio.h>

int exponecial(int k, int n)
{
    if (n == 0) return 1;
    if (n == 1) return k;

    else
        return k * exponecial(k, n - 1);
}
int main()
{
    int k, n;

    scanf("%d %d", &k, &n);

    printf("%d\n", exponecial(k, n));

    return 0;
}