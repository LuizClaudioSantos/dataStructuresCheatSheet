#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int bool;
typedef int TYPEKEY;

typedef struct aux {
    TYPEKEY key;
    struct aux *left, *right;
    int h;
} NODE, *POINTER;

POINTER createNode(TYPEKEY key);

POINTER startup();

POINTER turnRight(POINTER root);

POINTER turnLeft(POINTER root);

int heigh(POINTER root);

int maxInt(int a, int b);

POINTER insert (POINTER root, TYPEKEY key );

void printTree (POINTER root);