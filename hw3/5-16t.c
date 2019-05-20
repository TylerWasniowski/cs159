#include <stdio.h>
#include <omp.h>
int main()
{
    int i;
    int sum=0;
    omp_set_num_threads(16);
    #pragma omp parallel for
    for (i=0; i<COUNT; i++)
    {
        sum = sum + i;
        printf("Thread number: %d  Iteration: %d  Local Sum: %d \n",
            omp_get_thread_num(), i, sum);
    }
    printf("\n All Threads Done – Final Global Sum: %d \n\n", sum);
}
