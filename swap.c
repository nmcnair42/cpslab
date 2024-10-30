#include <stdio.h>

void myswap ( int *a, int *b) {

	int c = a;
	a = b;
	b = c;

	printf("Swap function prints: a= %d, b = %d \n", a, b);

}

int mult (int a, int b) {

	return a*b;

}

int main () {

	int cat1, cat2;
	printf("Enter two integers: \n");

	scanf("%d %d", &cat1, &cat2);
	printf("Values of the integers before swap: %d and %d \n", cat1, cat2);
	myswap(&cat1, &cat2);
	printf("values of the integers after swap: %d and %d \n", cat1, cat2);

	return 0;
}
