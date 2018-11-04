# Binary Tree
The Binary Tree also know as Binary Search Tree is a data structure that allows search in Ologn2 scenario and On in the worst scenario.

## Requirements
Here you will find tree directories: dist (where the executable files will be created), include (where the header file can be find with the data structure definition) and src (where you can find the "c" file witht the data structure implementation)

You must have instaled in your computer a c compiler and make to be able to execute the commands.

### Compiling
To compile the code in the binaryTree folder execute the comand:

```
make compile
```

### Executing 
To execute  the code alread compiled execute the comand:

```
make run
```

### Clean
To clean the executable file once it is compiled, execute the comand:

```
make clean
```

## Implementation

### Node
The start point of the tree implementation is the struct "Node":

```
typedef int TYPEKEY;

typedef struct aux {
    TYPEKEY key;
    struct aux *left, *right;
} NODE;
```

The node contains a key value, in this case a int value, and two pointers point the left and the right node.

### Creating a new Tree
Create a new tree is simple as return a null pointer:
```
POINTER startUp() {
    return (NULL);
}
```

This new pointer is actually a root that is the starting point of the tree.

```
POINTER root = startUp(); 
```

### Creating a Node 
A basic operation is create a node, we allocate the necessary memory for the node and set all struct properties.

```
POINTER newNODE(TYPEKEY key){
    POINTER node = (POINTER) malloc(sizeof(NODE));
    node->left = NULL;
    node->right = NULL;
    node->key = key;
    return(node);
}
```

### Search a value in the binary tree
To search for a node in a binrary tree you run trought to the nodes in the right or node in the left according to the value of the key.

```
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

```

A usage for the method searchNODE would be like the code below.

```
    int key = 20;
    POINTER father, node, p, q;
    node = searchNODE(root, key, &father);
```    

### Remove Node from a binary tree
The main concern about to remove a node is to keep the tree balanced and release memory referent to the node when it is not necessary anymore.  

```
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
```