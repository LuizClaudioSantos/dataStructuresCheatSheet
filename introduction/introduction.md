
# Data Structure

This all about data structures in C.

## Setup the environment

In windows install mysys2 `https://www.msys2.org/` for gcc.

Check the gcc version

```bash
gcc -v
```

Check the git version

```bash
git --version
```

Check the make version

```bash
make --version
```

## Step 1

First things first, this must be basicest example of program in C, it print the message "Hello World" in the screen.

```c
#include <stdio.h>

int main() {
    printf("Hello World!\n");
    return 0;
}
```

I am using the gcc to compile it:

```bash
gcc helloWorld.c -o helloWorld
```

## Step 2

Let create our first data structure in c. In the code below I have create a constant called.

```c
#define maxHeight 225
```

In c we must use a struct to create a complex types, by complex I meant types that a compose by differnt chunck of data. In the code below I have created a struct composed by weight and height, that I have called WeightHeight.

```c
typedef struct {
    int weight;
    int height;
} WeightHeight;
```

```c
#include <stdio.h>
#define maxHeight 225

typedef struct {
    int weight;
    int height;
} WeightHeight;


int main() {

    WeightHeight person;
    person.weight = 80;
    person.height = 185;

    printf("Weight: %i, Height: %i\n", person.weight, person.height);

    if(person.height > maxHeight) {
        printf("Heigher than max height!\n");
    } else {
        printf("Shorter than max height!\n");
    }

    return 0;
}
```

