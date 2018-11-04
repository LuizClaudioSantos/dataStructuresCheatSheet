#include "stdio.h"
#include "../include/ntree.h"


POINTER newNode(TYPEKEY key) {
    POINTER newNode = malloc(sizeof(NODE));
    newNode->firstChild = NULL;
    newNode->brother = NULL;
    newNode->key = key;
    return newNode;
}

POINTER startup(TYPEKEY key) {
    return newNode(key);
}

bool insert(POINTER root, TYPEKEY key, TYPEKEY fatherKey) {
    POINTER father = searchKey(fatherKey, root);
    if (!father) {
        return(false);
    }
    POINTER son = newNode(key);
    POINTER p = father->firstChild;

    if (!p) {
        father->firstChild = son;
    } else {
        while(firstSon->brother){
            p = p->brother;
        }
        p->brother = son;
    }
    return(true);
}

void printTree (POINTER root) {
    if ( root == NULL) {
        return;
    }
    printf("%d(", root->key);

    POINTER p = root->firstChild;
    while(p) {
        printTree(p);
        p = p->brother;
    }
    printf(")");
}

POINTER searchKey(TYPEKEY key, POINTER root) {
    if (root == NULL) {
        return NULL;
    }
    if (root->key == ch) {
        return root;
    }
    while (p) {
        POINTER answer = searchKey(key, p);
        if (answer) {
            return(answer);
        }
        p = p->brother;
    }
    return(NULL);
}

int main() {
    POINTER r = startup();
}