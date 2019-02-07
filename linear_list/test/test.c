#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "../include/linearList.h"

int main() {

    LIST* l = (LIST*) malloc(sizeof(LIST));

    showList(l);

    insertElement(l, createRegister(1), 0);
    insertElement(l, createRegister(23), 1);
    insertElement(l, createRegister(4), 2);
    insertElement(l, createRegister(5), 3);
    insertElement(l, createRegister(7), 4);
    insertElement(l, createRegister(89), 5);
    
    showList(l);

    printf("Positon of 5 is %i",sequentialSearch(l, 5));

    return 0;
}