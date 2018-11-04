#define true 1
#define false 0

typedef int bool;
typedef int TYPEKEY;

typedef struct aux {
    TYPEKEY key;
    struct aux *left, *right;
} NODE;

typedef NODE* POINTER;

POINTER startUp();

POINTER insert(POINTER root, POINTER node);

POINTER newNODE(TYPEKEY key);

POINTER searchNODE(POINTER root, TYPEKEY key, POINTER *father);

POINTER removeNODE(POINTER root, TYPEKEY key);

void printTree (POINTER root);

int treeHigh(POINTER root);
