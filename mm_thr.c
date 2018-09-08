#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "timing.h"

#define size 200 //Defining size of all matrices

int matrix1[size][size], matrix2[size][size], result1[size][size], result2[size][size], num_of_thr;

/***** Matrix multiplication using multi threads *****/
void *matrix_mul(void *ptr)
{
    int i,j,k;
    int k_ptr = (int) ptr;
    int m = (k_ptr * 200)/num_of_thr; // assign starting row limit to thread
    int n = ((k_ptr + 1) * 200)/num_of_thr; // assign ending row limit to thread
    
    // Loop for execution of matrix
    for(i=m; i<n; i++)
    {
        for(j=0; j<size; j++)
        {
            result2[i][j] = 0;
            for(k=0; k<size; k++)
            {
                result2[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main(int argc, char **argv)
{
    int i,j,k;
    if(argc < 2)
    {
        printf("Please enter number of threads\n");
    }
    else
    {
        num_of_thr = atoi(argv[1]); //Command line input
        
        //Filling matrix 1
        for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
                matrix1[i][j] = rand();
        }
        
        //Filling matrix 2
        for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
                matrix2[i][j] = rand();
        }
        
        /***** Normal Matrix multiplication *****/
        printf("\nRegular process\n");
        start_timer();
        for(i=0; i<size; i++)
        {
            for(j=0; j<size; j++)
            {
                result1[i][j] = 0;
                for(k=0; k<size; k++)
                {
                    result1[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
        printf("Elpased time is %f ",stop_timer());
        
        // Dynamically allocating memory for threads
        pthread_t *thr = (pthread_t*) calloc(num_of_thr, sizeof(pthread_t));
        
        printf("\n=============================\n\nMultithread\n");
        start_timer();
        
        // Loop for creation of threads
        for(i=0;i<num_of_thr;i++)
        {
            // Creating each thread one by one
            if(pthread_create(&thr[i], NULL, matrix_mul, (void*)i)!=0)
                printf("Failed to create thread no. %d \n",i);
        }
        
        // Main thread waiting for other threads to complete their execution
        for(i=0;i<num_of_thr;i++)
        {
            pthread_join(thr[i],NULL);
        }
        printf("Elpased time is %f \n",stop_timer());
        

        free(thr);
    }
    
    return 0;
}

