#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main( int argc, char *argv[] ) {

    int n = atoi(argv[1]);
    printf("n is %d\n", n);

    clock_t begin, end;
    double time_taken;

    int *v1 = malloc(sizeof(int)*n);
    int *v2 = malloc(sizeof(int)*n);
    int v3 = 0;

    for (int i=0; i<n; i++) {

        // I tested with these vectors first
        //v1[i] = i*i;
        //v2[i] = i+i;

        if ( n%2 ==0) {
            v1[i] = 1;
            v2[i] = -1;
        } else {
            v1[i] = -1;
            v2[i] = 1;
        }
    }

    begin = clock();

    for (int i=0; i<n; i++) {

        v3 += v1[i]*v2[i];

        printf("The first values are %d, and %d\n", v1[i], v2[i]);
    }

    printf("The final value is: %d\n", v3);

    end = clock();

    time_taken = ((double)(end - begin))/CLOCKS_PER_SEC;
    printf("Time taken for this code is %f\n", time_taken);

}

