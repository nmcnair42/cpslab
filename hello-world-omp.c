#include <stdio.h>

int main (int *argc, char *argv[]) {

    #pragma omp parallel
    {
        int th_id = omp_get_thread_num();
        printf("Hello World from thread = %d \n", th_id);
    }

}