#include<stdio.h>

int main() {
    int x = 25;
    int* y = &x;
    *y = 30;
    printf("Value of x:%i, the address of x is: %i", *y, y);
    return 0;
}