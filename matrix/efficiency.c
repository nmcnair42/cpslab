#include <stdio.h>
#include <time.h>


int main(int argc, char* argv[]) 
{
  clock_t start, end;
  double cpu_time_used;
     
  start = clock();
     /* Do the work. */
     printf("Printing something.");
 
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  // print the result
  printf("This task took %f seconds to execute \n", cpu_time_used);

  return 0.;
}

     