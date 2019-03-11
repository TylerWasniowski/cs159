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
    else if (pid == 0) printf("I am the child. My pid is %d. My parent's pid is %d.\n", getpid(), getppid());
    else {printf("I am the parent. My pid is %d. My child's pid is %d.\n", getpid(), pid); wait(NULL); }
    fflush(stdout); // Clear buffer after finishing.

    return EXIT_SUCCESS;
}