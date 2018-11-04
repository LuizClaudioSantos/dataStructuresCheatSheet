#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#define MAX 50

typedef int KEYTYPE;

typedef struct {
    KEYTYPE key;
    //
} REGISTER;

typedef struct {
    REGISTER A[MAX];
    int elementNumber;
} LIST;

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

int binarySearch(LIST* l, KEYTYPE key) {
    int left, right,  half;
    left = 0;
    right = l->elementNumber-1;
    while(left <= right) {
        half = (left + right)/2;
        if( l->A[half].key == key ) {
            return half;
        } else {
            if (l->A[half].key < key) {
                left = half + 1;
            } else {
                half = right -1;
            }
        }
    }
}

bool insertElement(LIST* l, REGISTER* reg) {
   if(l->elementNumber >= MAX) {
       return false;
   }   
   int position = l->elementNumber;
   while(position > 0 && l->A[position-1].key > reg->key) {
       l->A[position] = l->A[position-1];
       position--;
   }
   l->A[position] = *reg;
   l->elementNumber++;
}

bool deleteElementList(KEYTYPE key, LIST* l) {
    int pos, j;
    pos = binarySearch(l, key);
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

    insertElement(l, createRegister(1));
    insertElement(l, createRegister(23));
    insertElement(l, createRegister(4));
    insertElement(l, createRegister(5));
    insertElement(l, createRegister(7));
    insertElement(l, createRegister(89));
    
    showList(l);

    printf("Positon of 5 is %i",binarySearch(l, 5));

    return 0;
}