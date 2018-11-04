#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "../include/binaryTree.h"


POINTER startUp() {
    return (NULL);
}

POINTER insert(POINTER root, POINTER node) {
    if (root == NULL) {
        return node;
    } 
    if(root->key > node->key ) {
        root->left = insert(root->left, node);
    } else {
        root->right = insert(root->right, node);
    }

    return (root);
}

POINTER newNODE(TYPEKEY key){
    POINTER node = (POINTER) malloc(sizeof(NODE));
    node->left = NULL;
    node->right = NULL;
    node->key = key;
    return(node);
}

POINTER searchNODE(POINTER root, TYPEKEY key, POINTER *father) {
    POINTER current = root;
    *father = NULL;
    while (current) {
        if(current->key == key) {
            return(current);
        }
        *father = current;
        if(key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return(NULL);
}

POINTER removeNODE(POINTER root, TYPEKEY key) {
    POINTER father, node, p, q;
    node = searchNODE(root, key, &father);
    if(node == NULL) {
        return(root);
    }
    if (!node->left || !node->right) {
        if(!node->left) {
           q = node->right;
        } else {
           q = node->left;
        }
    } else {
        p = node;
        q = node->left;
        while (q->right) {
            p = q;
            q = q->right;
        }
        if (p != node) {
            p->right = q->left;
            q->left = node->left;
        }
        q->right = node->right;
    }
    if (!father) {
        free(node);
        return(q);
    }
    if ( key < father->key ) {
        father->left = q;
    }else{
        father->right = q;
    }
    free(node);
    return(root);
}


void printTree (POINTER root) {

      printf("%i(", root->key);

    if(root->left != NULL)
       printTree(root->left);

    if(root->right != NULL) 
       printTree(root->right);   
    
    printf(")");   

}

int maxInt(int a, int b) {
    if( a > b) {
       return a;
    } else {
       return b;
    }

}

int treeHigh(POINTER root) {

    if (root == NULL) {
        return -1;
    }

    int highLeft = treeHigh(root->left);

    int highRight = treeHigh(root->right);

    return (maxInt(highLeft, highLeft) + 1);
}

int main() {
    POINTER root = startUp(); 

    POINTER node = newNODE(23);
    root = insert(root, node);
    
    node = newNODE(12);
    root = insert(root, node);

    node = newNODE(25);
    root = insert(root, node);

    node = newNODE(15);
    root = insert(root, node);

    node = newNODE(8);
    root = insert(root, node);

    printTree(root);
    printf("The tree high is %i\n", treeHigh(root));

    printf("Removing 12 \n");
    removeNODE(root, 12);

    printTree(root);

    printf("The tree high is %i\n", treeHigh(root));

}
