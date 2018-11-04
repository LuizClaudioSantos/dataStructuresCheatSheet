#include "../include/avlTree.h"

POINTER createNode(TYPEKEY key) {
    POINTER newNODE = (POINTER) malloc(sizeof(NODE));
    newNODE->left = NULL;
    newNODE->right = NULL;
    newNODE->key = key;
    newNODE->h = 0;
    return (newNODE);
}

POINTER startup() {
   return(NULL);
}

int maxInt(int a, int b) {
   return ( a > b) ? a: b;
}

POINTER turnRight(POINTER root) {
    POINTER aux;
    aux = root->left;
    root->left = aux->right;

    root->h = maxInt(heigh(root->right), heigh(root->left)) + 1;
    aux->h = maxInt(heigh(aux->left), root->h) +1;
}

POINTER turnLeft(POINTER root) {
    POINTER aux;
    aux = root->right;
    root->right = aux->left;
    aux->left = root;

    root->h = maxInt(heigh(root->right), heigh(root->left)) + 1;
    aux->h = maxInt(heigh(aux->right), root->h) + 1;
    return(aux);
}

POINTER turnLeftRight(POINTER root) {
    root->left = turnLeft(root->left);
    return(turnRight(root));
}

POINTER turnRightLeft(POINTER root) {
    root->right = turnRight(root->right);
    return(turnLeft(root));
}

int heigh(POINTER root) {
    if(root == NULL) {
        return -1;
    }
    return root->h;
}

POINTER insert (POINTER root, TYPEKEY key ) {

    if (!root) return (createNode(key));
    if (key < root->key) 
        root->left = insert(root->left, key);
        if (heigh(root->left) - heigh(root->right) == 2) {
            if(key < root->left->key) 
                root = turnRight(root);
            else 
                root = turnLeftRight(root);
        }
    else 
        if (key > root->key) {
            root->right = insert(root->right, key);
            if (heigh(root->right) - heigh(root->left) == 2) 
                if (key > root->right->key) 
                    root = turnLeft(root);
                else 
                    root =  turnRightLeft(root); 
        }
    root->h = maxInt(heigh(root->left), heigh(root->right)) + 1;
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

int main() {
    POINTER root = startup();

    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    
    printTree(root);
}