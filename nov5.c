
#include <stdio.h>

/* swap two integers using pointers
these integers are entries of an array called dog.
the array is of length 2 */



int main() {

	int dog[2] = { -90 , 8};

	int *husky[2];
	
	printf("array [0] = %d, array [1] = %d\n", dog[0], dog[1]);
	
	for (int i=0; i<2; ++i) {
		printf("dog[%d]=%d\n", i, dog[i]);
		*husky[i]=dog[i]; 
		printf("husky[%d]=%d\n", i, *husky[i]);
	}
	delete husky; 

	return 0;

}



