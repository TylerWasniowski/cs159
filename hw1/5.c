#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>

int main () {
    int pid;
    int i;
    for (i=0; i<3; i++){
        if ((pid=fork()) <0 ) {printf("Sorry...cannot fork\n"); }
        else if (pid ==0) {
            printf("child %d %d %d\n", i, getppid(), getpid());
            fflush(stdout);
        }
        else {
            wait(NULL);
            printf ("parent %d %d %d\n", i, getppid(), getpid());
            fflush(stdout);
        }
    }
    exit(0);
}