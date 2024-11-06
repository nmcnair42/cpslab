#include <stdio.h>

#define SIZE 10

int main() {

    int array[SIZE] = {9, 4, 20, 94, 2, 49, 2, 83, 41, 22};

    int max = 0;
    
    printf("%d\n", max);

    for(int i=0; i<SIZE; i++) {
        printf("%d\n", *(array+i));
        

        if(*(array+i) >= max) {
            max = *(array+i);
        }
    }

    printf("The max of this data set is %d\n", max);

}