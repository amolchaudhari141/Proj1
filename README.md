# Proj1
Matrix Multiplication using thread
# You are asked to evaluate the creation/deletion cost for threads and process.
# You also need to measure and compare the performance of thread based parallel matrix multiplication program. You are asked to write four C files: et.c ep.c mm_thr.c and timing.c.
First, we will create timing.c file.
# timing.c
The timing.c file has two functions namely start_timer() and stop_timer(). For information
hiding we have used static global variable elapsed_sec. We declared it static because it won’t
be accessible to other programs if they try to include that variable in their program.
# et.c
In this file, we have created the dynamic memory allocation in which we can accept the
argument and pass it to the thread for execution.
 Here we have compared the time taken by main process and time taken by thread by using
different function like pthread_create &amp; pthread_join.
 For comparing the execution time, we have performed the function of copying data into
memory.
# ep.c
  The aim for this file creation is to compare and check the execution time required by single
process and time for creating new child process and simultaneous writing/copying data into
dynamically allocated memory.
   The following screenshot shows the code for this file. In this file, we have first dynamically
allocated the memory using calloc() function.
   First we have counted the elapsed time taken by normal process. Here for this we just need
to add start_timer() before loop and stop_timer() after loop.
   In second part of this file we have created child process by using fork() function and we
have given the task to copy the data into memory.
   So, the total time taken for this fork process will be equal to time required for fork
process+wait time for process+time required for copy function.
# mm_thr.c:
In this file, we have written code to do matrix multiplication of size 200*200.
We have tried to compare normal the matrix multiplication and multiple threaded matrix
multiplication.
We are accepting the value of number of threads using command line argument, also we have
used rand() function to get the random value to fill in matrix.
In normal matrix multiplication, we have counted the elapsed time required for the
multiplication of two matrices using single normal process.
For using multithreading in matrix multiplication, we have created thread pointer and
dynamically allocated it based on number of threads. After that we have created each thread
using for loop and it will go to matrix_mul() along with parameter.
In matrix_mul() function we have assigned the number of rows for each thread using variable
m and n.
m will be the starting and n will be the ending row number for each thread.
