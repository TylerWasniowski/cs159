#include <stdio.h>
#include <omp.h>

int main()
{
    omp_set_num_threads(4);
    #pragma omp parallel
    {
        printf(" Hello ");
    }
    printf("\n\n GoodBye – Team Destroyed – Exiting Program \n\n");
}
