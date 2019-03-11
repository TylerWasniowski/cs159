#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>

void printInfo(char label);

int exitProc(char label);

int main(int argc, char** argv) {
    printInfo('A');

    printf("Immediately before creating B. Only one process at this point.\n");
    fflush(stdout); // Clear buffer before forking.

    pid_t pid = fork();
    if (pid < 0) { printf("Forking B error.\n"); return EXIT_FAILURE; }
    else if (pid == 0) {
        printInfo('B');

        printf("Immediately before creating D.\n");
        fflush(stdout);

        pid = fork();
        if (pid < 0) { printf("Forking D error.\n"); return EXIT_FAILURE; }
        else if (pid == 0) { printInfo('D'); return exitProc('D'); }
        
        wait(NULL);
        return exitProc('B');
    }

    printf("Immediately before creating C.\n");
    fflush(stdout);

    pid = fork();
    if (pid < 0) { printf("Forking C error.\n"); return EXIT_FAILURE; }
    else if (pid == 0) {
        printInfo('C');

        printf("Immediately before creating E.\n");
        fflush(stdout);

        pid = fork();
        if (pid < 0) { printf("Forking E error.\n"); return EXIT_FAILURE; }
        else if (pid == 0) { printInfo('E'); return exitProc('E'); }

        printf("Immediately before creating F.\n");
        fflush(stdout);

        pid = fork();
        if (pid < 0) { printf("Forking F error.\n"); return EXIT_FAILURE; }
        else if (pid == 0) { printInfo('F'); return exitProc('F'); }
        
        wait(NULL);
        wait(NULL);
        return exitProc('C');
    }

    wait(NULL);
    wait(NULL);
    return exitProc('A');
}

void printInfo(char label) {
    printf("Immediately after creating %c.\n", label);
    printf("%c: I am %d, and my parent is %d.\n", label, getpid(), getppid());
    fflush(stdout); // Make sure result is printed at this point.
}

int exitProc(char label) {
    printf("Exiting %c...\n", label);
    fflush(stdout);

    return EXIT_SUCCESS;
}