#include<stdio.h>
#include<stdlib.h>

int main()
    {
          double number; 
          FILE* in_file = fopen("scores-data.txt", "r"); //only open a pre-exisiting file in read mode. 
         
          if (! in_file ) // equivalent to saying if ( in_file == NULL ) 
             {  
                printf("oops, file can't be read\n"); 
                exit(-1); 
             } 
          // attempt to read the next line and store 
          // the value in the "number" variable 
          while ( fscanf(in_file, "%lf", & number ) == 1 )  
             { 
               printf("We just read %lf\n", number); 
             } 
    }
