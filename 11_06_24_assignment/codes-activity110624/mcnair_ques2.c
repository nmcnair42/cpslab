#include <stdio.h>
//This program calculates the average of the scores of 5 students.

int find_mode(int *x, int len);
double find_mean(int *x);

int main(){
	int n = 5;
	//int max_student_size = 1000;
	int x[n];//array of variable length. 
	//x[1]= x[2]= wrong because 
	// indexing begins at 0. x[0] and x[1].
	double avg=-5.0;
	x[0]= 10;
	x[1]= 7;
	x[2]= 5;
	x[3]= 9;
	x[4]= 10;
	avg = find_mean(x);
	printf("the average score is: %lf \n", avg);

	int mode = find_mode(x, n);
	printf("The mod eof the scores is: %d\n", mode);
	
}

int find_mode(int *x, int len) {

	//double sizeX = (sizeof(x)/sizeof(x[0]));
	//printf("size of x is %ld\n", sizeof(x[0]));

	int modes[len];
	for (int i=0;i<len;i++) {
		modes[i]=0;
	}
	
	for (int j=0;j<len;j++) {
		for (int k=0;k<len;k++) {
			if (x[j]==x[k]) {
				modes[j] += 1;
			}
		}
	}

	int max = 0;
    for (int a=0; a<len; a++) {
        if (modes[max] <= modes[a]) {
            max = a;
        }
    }

	return x[max];
}

double find_mean(int *x) {

	double sum = 0.0;//sum 41
	for (int i = 0 ;i < 5; ++i)
		{
		sum +=x[i];
		//printf("for i = %d, sum = %lf \n ", i, sum );
			//more for checking if the right sum is being 
			//computed.
		} // for-loop
	
	return sum/5;

	//printf("the average score is: %lf \n", avg);
}