# First Data Structure
This is a simple example about how to create a simple structure in C. 

For this example I have create struct with the weight and heught of perso, struct like this will be like the essential Lego block to build complex datastructures.

```c
#include <stdio.h>
#define maxHeight 225

typedef struct {
    int weight;
    int height;
} WeightHeight;
```

Just use the struct as in the code below:

```c
    WeightHeight person;
    person.weight = 80;
    person.height = 185;

    printf("Weight: %i, Height: %i\n", person.weight, person.height);

    if(person.height > maxHeight) {
        printf("Heigher than max height!\n");
    } else {
        printf("Shorter than max height!\n");
    }
```