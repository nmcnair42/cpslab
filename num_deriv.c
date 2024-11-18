#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double forward(double *x, double *result, int N, double H);
double central(double *x, double *result, int N, double H);
double funct(double X);
double deriv_funct(double X);

int main (int argc, char *argv[]) {

    // Catch no arguments given seg fault
    if (!argv[1]) {
        printf("No arguments given. Ending program.\n");
        return 0;
    }

    // Domain of approximation

    double b = 2*M_PI;  // fix pi
    double a = 0.0;

    int n = atoi(argv[1]);
    printf("The value of n is %d\n", n);
    printf("The value of b is %f\n", b);

    double h = (b-a)/n;

    double *act_deriv = malloc(sizeof(double)*n); // actual solution
    double *num_deriv = malloc(sizeof(double)*n); // approximated solution
    double *x_vals = malloc(sizeof(double)*n); // x values

    printf("The value of h is %f\n", h);

    // choose method
    int input;
    printf("\nInput [1] to use forward difference method or\n[2] to use central difference:\n");
    scanf("%d", &input);

    for (int i=0; i<n; i++) {
        x_vals[i] = (i+1)*h;
        printf("X value [%d] is %f\n", i, x_vals[i]);
    }

    for (int i=0; i<n; i++) {
        act_deriv[i] = deriv_funct(x_vals[i]);
        printf("Actual derivative [%d] is %f\n", i, act_deriv[i]);
    }

    switch(input) {
        case 1:
            printf("Using forward difference:\n");
            forward(x_vals, num_deriv, n, h);
            for (int i=0; i<n; i++) {
                printf("Numerical derivative [%d] is %f\n", i, num_deriv[i]);
            }
            break;

        case 2:
            printf("Using central difference: \n");
            central(x_vals, num_deriv, n, h);
            for (int i=0; i<n; i++) {
                printf("Numerical derivative [%d] is %f\n", i, num_deriv[i]);
            }
            break;
    }

    free(act_deriv);
    free(num_deriv);
    free(x_vals);

    return 0;

}

double forward(double *x, double *result, int N, double H) {

    for (int i=0; i<N-1; i++) {
        result[i] = (funct(x[i+1]) - funct(x[i]))/H;
        //x[i] = (i+1)*H;
        //printf("Value %d is %f\n", i, result[i]);
    }
    result[N] = (funct(x[N]) - funct(x[N-1]))/H; // using final two points
}


double central(double *x, double *result, int N, double H) {
    for (int i=1; i<N-1; i++) {
        result[i] = (funct(x[i+1]) - funct(x[i-1]))/(2*H);
        //x[i] = (i+1)*H;
        //printf("Value %d is %f\n", i, result[i]);
    }
    result[0] = (funct(x[1]) - funct(x[0]))/H; // using first and last two points
    result[N] = (funct(x[N]) - funct(x[N-1]))/H;
}


double funct(double X) {
    return sin(X);
}


double deriv_funct(double X) {
    return cos(X);
}