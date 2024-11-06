#include <stdio.h>
#include <stdlib.h>

#define SIZE 11

int main() {

    int array[SIZE] = {0, 0, 1, 2, 1, 0, 1, 1, 1, 2, 0};
    // find the most recurring entry of the array
    int counter = 0;

    int i,j;
    int* array2 = malloc(sizeof(int)*SIZE);
    for (int n=0;n<SIZE; n++) {
        array2[n]=0;
    }

    //printf("checkpoint 1\n");

    for (i=0;i<SIZE; i++) {
        //printf("%dth element is %d\n", i+1, array[i]);
        //printf("mode is %d\n", array2[i]);
        for (j=0; j<SIZE; j++) {
            if (array[i] == array[j]) {
                array2[i] += 1;
            }
        }
        //printf("Frequency of %d is %d\n", array[i], array2[i]);
    }

    int max = 0;
    for (int a=0; a<SIZE; a++) {
        if (array2[max] <= array2[a]) {
            max = a;
        }
    }

    printf("The mode of the data is %d, with a frequency of %d\n", array[max], array2[max]);
    printf("%p\n", &array2);

    free(array2);

    return 0;
}