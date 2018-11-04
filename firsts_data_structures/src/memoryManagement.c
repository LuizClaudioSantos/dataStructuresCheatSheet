#include <stdio.h>

int main() {
    int x = 25;
    int* y = &x;
    *y = 30;
    printf("Current value of x: %i\n", x);
    return 0;
}