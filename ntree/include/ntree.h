#define true  1
#define false 0

typedef int bool;
typedef int TYPEKEY;

typedef struct node {
    TYPEKEY key;
    struct node * firstChild;
    struct node * brother;
} NODE;
 
typedef NODE* POINTER;

POINTER newNode(TYPEKEY key);

POINTER startup(TYPEKEY key);

bool insert(POINTER root, TYPEKEY key, TYPEKEY fatherKey);

void printTree (POINTER root);
