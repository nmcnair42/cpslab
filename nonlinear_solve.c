#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x);
double d_f(double);
int sign(double);
double bisection(int a, int b);
double newton(int init);
double secant(int a, int b);

double error = 0.00000001;
double tol = 0.00000001;
int maxIter = 100;

int main () {

    int input, x0, x1, initialguess;
    double result;


    printf("Options are: (input integer)\n(1) Bisection method\n(2) Newton's method\n(3) Secant method\n");
    scanf("%d", &input);
    switch (input) {
        case 1:
            printf("Input an initial bound (lower): \n");
            scanf("%d", &x0);
            printf("Input an initial bound (upper): \n");
            scanf("%d", &x1);
            printf("Finding zero for domain [%d, %d].\n", x0, x1);
            result = bisection(x0, x1);
            break;
        /*
        case 2:
            printf("Input an initial guess: \n");
            scanf("%d \n", &initialguess);
            result = newton(initialguess);
            break;
        case 3:
            printf("Input initial values: \n");
            scanf("%d \n", &x0);
            scanf("%d \n", &x1);
            break;
            */
        default:
            printf("Entry unacceptable.");
    }

}

double f(double x) {

    return (pow(x,6))-x-1;
}

double d_f(double x) {

    return 6*(pow(x, 5)) - 1;
}

int sign(double x) {
    if (x < 0) {
        return 0;
    } else if (x > 0) {
        return 1;
    } else {
        printf("Value is zero.\n");
        return 2;
    }
}

double bisection (int a, int b) {
    
    double c, fb, fa, w;
    int counter = 0;

    fb = f(b);
    fa = f(a);

    printf("Function values: lower:%f, upper:%f\n", fa, fb);

    if ( sign(fb) == sign(fa) ) {
        counter = maxIter;
        printf("Initial condition not satisfied\n");
    }

    while (counter < maxIter) {
        c = (double)(b+a)/2;
        w = f(c);
        printf("Midpoint %d: x=%f, f(x)=%f\n", counter, c, w );

        if ( (fabs(b-a) < tol) || fabs(w) < error ) {
            break;
        }

        if ( sign(fb) != sign(fa) ) {
            b = c;
            fb = w;
        } else {
            a = c;
            fa = w;
        }

        counter += 1;
    }

    printf("Converged to %lf in %d iterations!\n", c, counter);
    return c;
}

double newton(int init) {
    return 0;
}

double secant(int init, int first) {
    return 0;
}