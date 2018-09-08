#include <stdio.h>
#include <unistd.h> 
#include <stdlib.h>
#include <sys/time.h>
#include "timing.h"

int main(int argc, char **argv)
{

    int i;
    int mem_size;
    if(argc < 2)
    {
        printf("Argument needed \n");
    }
    else
    {
        mem_size = atoi(argv[1]);
        
        //Creation buffer for writing data
        char *buf = (char*) calloc(1, 1000 * mem_size);
        
        //Calculating the time of "for loop run by normal process"
        printf("\nRegular process\n");
	    start_timer();
        for (i=0; i < 1000*mem_size;i+=4096)
        {
          buf[i]='x';
        }
	    printf("Elapsed Time is %f",stop_timer());
        
        
        
        //Calculating the time of "for loop run by fork"
        printf("\n=============================\n\nFork\n");
	    start_timer();
        pid_t pid;
        pid = fork();  //Creating child process
        int status;
        if(pid == 0)
        {
           for(i=1;i<1000*mem_size ;i+=4096)
           {
                 buf[i]='y';
           }
           exit(0);
        }
        else
        {
            wait(&status);
        }
        printf("Elapsed Time is %f\n",stop_timer());
        
	    free(buf);
    }
    
    return 0;
}
