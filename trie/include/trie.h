#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0
#define N_ALPHABET 26

typedef int bool;
typedef bool TYPERET;

typedef struct node {
    struct node *children[N_ALPHABET];
    TYPERET end;
} NODE;

typedef NODE* POINTER;

POINTER createNODE();

POINTER startup();

int mapIndex(char c);

void insert(POINTER root, char *key);

bool search(POINTER root, char *key);