#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int tribonacci(int n, bool* calculed, int* auxiliary) {
    if(!calculed[n]) {
        if (n == 0 || n == 1) auxiliary[n] = 0;
        else if (n == 2) auxiliary[n] = n - 1;
        else if (n > 2) {
            auxiliary[n] = tribonacci(n - 1, calculed, auxiliary) + tribonacci(n - 2, calculed, auxiliary) +
            tribonacci(n - 3, calculed, auxiliary);
        }
    }
    calculed[n] = true;
    return auxiliary[n];
}

int main() {
    int n = 9;
    bool calculed[n+1];
    int auxiliary[n+1];
    memset(calculed, false, sizeof(calculed));

    printf("%d\n", tribonacci(n, calculed, auxiliary));
    return 0;
}