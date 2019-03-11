#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
    printf("Immediately before the fork. Only one process at this point.\n");
    fflush(stdout); // Clear buffer before forking.

    pid_t pid = fork();
    printf("Immediately after the fork. This statement should print twice.\n");
    if (pid < 0) { printf("Forking error.\n"); return EXIT_FAILURE; }
    else if (pid == 0) {
        printf("Child going to sleep.\n");
        fflush(stdout);

        sleep(5);

        printf("Child finished sleeping.\n");
        printf("Child exiting...\n");
        fflush(stdout);

        return EXIT_SUCCESS;        
    }
    
    printf("Parent starting wait.\n");
    fflush(stdout);

    wait(NULL);

    printf("Parent finished wait.\n");
    fflush(stdout);

    return EXIT_SUCCESS;
}