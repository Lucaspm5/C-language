#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int fibonacci(int n, int* auxiliary, bool* calculeted) {
    if (!calculeted[n])
    {
        if (n <= 1) auxiliary[n] = n;
        else {
            auxiliary[n] = fibonacci(n-1, auxiliary, calculeted) + fibonacci(n-2, auxiliary, calculeted);
        }
    }
    calculeted[n] = true;
    return auxiliary[n];
}

int main() {
    int n = 5;
    int auxiliary[n+1];
    bool calculeted[n+1];
    memset(calculeted, false, sizeof(calculeted));

    printf("%d\n", fibonacci(n-1, auxiliary, calculeted));

    return 0;
}
