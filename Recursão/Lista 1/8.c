#include <stdio.h>

int mdc(int x, int y) {
    if (y == 0) return x;

    return mdc(y, x % y);
}

int main() {
    int x = 107, y = 7;
    printf("%d\n",mdc(x, y));
    return 0;
}