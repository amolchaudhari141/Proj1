#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

static float elapsed_secs = 0;
struct timeval start_time, stop_time;

void start_timer()
{
    gettimeofday(&start_time, (struct timezone*) NULL);
}

float stop_timer()
{
    gettimeofday(&stop_time, (struct timezone*) NULL);
    elapsed_secs = ((stop_time.tv_sec - start_time.tv_sec) + (stop_time.tv_usec - start_time.tv_usec) / 1000000.0);
    return elapsed_secs;
    
}

