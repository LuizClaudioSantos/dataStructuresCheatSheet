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

void listStartup(LIST* l);

int size(LIST* l);

int sequentialSearch(LIST* l, KEYTYPE key);

bool insertElement(LIST* l, REGISTER* reg, int i);

bool deleteElementList(KEYTYPE key, LIST* l);

void listRestartup(LIST* l);

REGISTER* createRegister( int key );