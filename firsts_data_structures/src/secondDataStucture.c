#include <stdio.h>
#include <malloc.h>
#define maxHeight 225

typedef struct {
    int weight;
    int height;
} WeightHeight;


int main() {

    WeightHeight* person = (WeightHeight*) malloc(sizeof(WeightHeight));
    person->weight = 93;
    person->height = 176;

    printf("Weight: %i, Height: %i\n", person->weight, person->height);

    if(person->height > maxHeight) {
        printf("Heigher than max height!\n");
    } else {
        printf("Shorter than max height!\n");
    }

    return 0;
}