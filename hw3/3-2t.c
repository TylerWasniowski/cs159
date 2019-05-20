#include <stdio.h>
#include <omp.h>
int main()
{
    omp_set_num_threads(2);
    #pragma omp parallel
    {
        printf("\n Hello from thread = %d ", omp_get_thread_num() );
    }

    printf("\n\n GoodBye – Team Destroyed – Exiting Program \n\n");

}
