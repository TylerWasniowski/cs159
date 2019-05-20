#include <stdio.h>
#include <omp.h>
int main()
{
    int i;
    omp_set_num_threads(4);
    #pragma omp parallel for
    for (i=0; i<16; i++)
    {
            printf("Hello from thread number: %d Iteration: %d \n",
            omp_get_thread_num(), i);
    }
    printf("\n GoodBye – Team Destroyed – Exiting Program \n\n");
}
