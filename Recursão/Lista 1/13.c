#include <stdio.h>

void par(int n, int auxiliary) {
    if (n + 1 == 0) return 1;
    return (auxiliary % 2 == 0) ? (printf("%d ", auxiliary), par(n - 1, auxiliary + 1)) : par(n - 1, auxiliary + 1);
}

int main() {
    int n = 10;
    par(n , 0);
    return 0;
}