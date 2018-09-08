#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <stdlib.h>
#include "timing.h"

int mem_size = 0;
void *split1(void *ptr)
{
    int i;
    char *k_ptr = (char*) ptr;
    for (i=1; i < 1000*mem_size;i+=4096)
    {
        k_ptr[i] = 'y';
    }
    
}

int main(int argc, char **argv)
{
    
    if(argc < 2)
    {
        printf("Argument needed \n");
    }
    else
    {
        mem_size = atoi(argv[1]);
        char *ptr = (char*) calloc(1, 1000 * mem_size);
        pthread_t ch1;
        int i;

        //Calculating the time of for loop run by normal process
        printf("\nRegular process ");
        start_timer();
        for (i=0; i < 1000*mem_size;i+=4096)
        {
            ptr[i]='x';
        }
        printf("\nElapsed Time is %f",stop_timer());
        
        //Calculating the time of for loop run by thread
        printf("\n=============================\n\nThread\n");
        start_timer();
        if(pthread_create(&ch1, NULL, split1, ptr)!=0)
            printf("Failed to create thread\n");
        pthread_join(ch1, NULL);
        printf("Elapsed Time is %f\n",stop_timer());
        
        free(ptr);
    }
    
    return 0;
}

