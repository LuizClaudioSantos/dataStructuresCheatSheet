#include "../include/trie.h"

POINTER createNODE() {
    POINTER p = NULL;

    p = (POINTER) malloc(sizeof(NODE));
    if (p) {
        p->end = false;
        for (int i=0; i < N_ALPHABET; i++) {
            p->children[i] = NULL;
        }
    }
    return(p);
}

POINTER startup() {
    return(createNODE());
}

int mapIndex(char c) {
    return ((int) c - (int)'a');
}

void insert(POINTER root, char *key) {
    int level;
    int length = strlen(key);

    POINTER p = root;
    for (level = 0; level < length; level++) {
        int i = mapIndex(key[level]);
        if (!p->children[i]) {
            p->children[i] = createNODE();
        }
        p = p->children[i];
    }
    p->end = true;

}

bool search(POINTER root, char *key) {
    int level;
    int length = strlen(key);
    int i;
    POINTER p = root;

    for (level = 0; level < length; level++) {
        i = mapIndex(key[level]);
        if (!p->children[i]) {
            return false;
        }
        p = p->children[i];
    }
    return(p->end);
}

void printTree (POINTER root) {

   POINTER p = root;
   int index = 0; 

}

int main( ) {

    POINTER root = startup();

    char* know = "know";
    char* knowledge = "knowledge";
    char* knowing = "knwoing";
    char* knowth = "knowth";

    printf("k %i\n", mapIndex('k'));
    insert(root, know);
    insert(root, knowledge);
    insert(root, knowing);
    insert(root, knowth);

    char* amazon = "amazon";
    char* abacus = "abacus";
    char* ascii = "ascii";
    char* acre = "acre";

    insert(root, amazon);
    insert(root, abacus);
    insert(root, ascii);
    insert(root, acre);

    printf("%s", root->children);

}