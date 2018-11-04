#include <stdio.h>
#include <malloc.h>

int main() {
    int* y = (int*) malloc(sizeof(int));
    *y = 20;
    int z = sizeof(20);
    printf("Current value of y: %i, the size is %i bytes.\n", *y, z);
    return 0;
}