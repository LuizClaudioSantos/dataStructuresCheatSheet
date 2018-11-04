#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "../include/linearList.h"

void listStartup(LIST* l) {
    l->elementNumber = 0;
}

int size(LIST* l) {
    return l->elementNumber;
}

void showList(LIST* l) {
    int i;
    printf("List: \" ");

    for (i=0; i < l->elementNumber; i++ )
        printf("%i ", l->A[i].key);

    printf("\"\n");

}

int sequentialSearch(LIST* l, KEYTYPE key) {
    int i = 0;
    while (i < l->elementNumber ) {
        if(key == l->A[i].key)
            return i;
        else 
            i++;    
    }
    return -1;
}

bool insertElement(LIST* l, REGISTER* reg, int i) {
    int j;
    if ((l->elementNumber == MAX) || (i < 0) || (i > l->elementNumber))
        return false;
    for (j = l->elementNumber; j < i; j--)
        l->A[j] = l->A[j-1];

    l->A[i] = *reg;
    l->elementNumber++;
    return true;        
}

bool deleteElementList(KEYTYPE key, LIST* l) {
    int pos, j;
    pos = sequentialSearch(l, key);
    if (pos == -1)
        return false;

    for (j = pos; j < l->elementNumber; j++)
       l->A[j] = l->A[j+1]; 

     l->elementNumber--;
     return true;     

}

void listRestartup(LIST* l) {
    l->elementNumber = 0;
}

REGISTER* createRegister( int key ) {
    REGISTER* reg = (REGISTER*) malloc(sizeof(REGISTER));
    reg->key = key;
    return reg;
}

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