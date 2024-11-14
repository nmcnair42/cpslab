#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char *argv[]) {

    // Catch no arguments given seg fault
    if (!argv[1]) {
        printf("No arguments given. Ending program.\n");
        return 0;
    }

    // Domain of approximation

    double b = 2* M_PI;  // fix pi
    double a = 0.0;


    int n = atoi(argv[1]);
    printf("The value of n is %d\n", n);

    double h = (b-a)/n;

    double *a_deriv = malloc(sizeof(double)*n);
    double *numer = malloc(sizeof(double)*n);

    return 0;

}