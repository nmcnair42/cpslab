#include<stdio.h>
#include<stdlib.h>
#define SIZE 20
int main()
    {
          int number[SIZE]; 
          int i=0;
          FILE* in_file = fopen("data.txt", "r"); //only open a pre-exisiting file in read mode. 
         
          if (! in_file ) // equivalent to saying if ( in_file == NULL ) 
             {  
                printf("oops, file can't be read\n"); 
                exit(-1); 
             } 
          // attempt to read the next line and store 
          // the value in the "number" variable 
          while ( fscanf(in_file, "%d", & number[i] ) == 1 )  
             { 
               printf("Scores read: %d\n", number[i]);
               i++; 
             } 
    int j,k;         
    int counter_mat[SIZE][2];
    for (i =0 ; i<SIZE ; ++i)
            {
            counter_mat[i][0]=number[i];    
            counter_mat[i][1]=1;
            }
    for (i = 0; i < SIZE; i++)
        {
            int ctr = 1;  // Reset the counter for each element
            for (j = 0, k = SIZE; j < k + 1; j++)
            {
                /* Increment the counter when the search value is duplicate. */
                if (i != j)
                {
                    if (number[i] == number[j])
                    {
                        ctr++;
                        counter_mat[i][1]+=1;
                    }
                    // else
                    // {ctr=1;}
                }
            }
            //printf("array entry arr1[%d]= %d has appeared %d times \n", i, number[i], counter_mat[i][1]);
            if (ctr == 1)
            {
                printf("unique score: arr1[%d]=%d \n", i, number[i]);  // Print the unique element
            }
        }
    
    int max = counter_mat[0][1];
    int mode=0;
    for (i=0; i<SIZE ;++i)
        {
            if(max < counter_mat[i][1])
                {
                    max = counter_mat[i][1];
                    mode=i;

                }


        }

    printf("mode = %d which appears %d times \n",  counter_mat[mode][0], counter_mat[mode][1]);

             
      return 0;
    }
