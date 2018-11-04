#include <stdio.h>
#include "../include/firstDataStructure.h"



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