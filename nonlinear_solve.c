#include <stdio.h>
#include <math.h>

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
    scanf("%d", input);
    switch (input) {
        case 2:
            printf("Input an initial bound (lower): \n");
            scanf("%d \n", x0);
            printf("Input an initial bound (upper): \n");
            scanf("%d \n", x1);
            result = bisection(x0, x1);
            break;
        case 1:
            printf("Input an initial guess: \n");
            scanf("%d \n", initialguess);
            result = newton(initialguess);
            break;
        case 3:
            printf("Input initial values: \n");
            scanf("%d \n", x0);
            scanf("%d \n", x1);
            break;
        default:
            printf("Entry unacceptable.");
    }

}

double function(double x) {

    return ( (x^6)-x-1 );
}

double bisection (int a, int b) {
    
    double c, fb, fa, w;
    int counter = 0;

    fb = function(b);
    fa = function(a);

    while (counter < maxIter) {
        c = (b+a)/2;
        w = function(c);

        if ( (abs(b-a) < tol) || abs(w) < error ) {
            break;
        }

        counter += 1;
    }
}

double newton(int init) {

}

double secant(int init, int first) {
    
}