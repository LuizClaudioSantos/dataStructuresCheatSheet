## Linear List

Let start with simple implementation of a linar list based in a array.

### Define the list interface

```c
void listStartup(LIST* l);

int size(LIST* l);

int sequentialSearch(LIST* l, KEYTYPE key);

bool insertElement(LIST* l, REGISTER* reg, int i);

bool deleteElementList(KEYTYPE key, LIST* l);

void listRestartup(LIST* l);

void showList(LIST* l);

REGISTER* createRegister( int key );
```

### Implement each one of the methods
```c
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
```

