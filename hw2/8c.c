#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/wait.h>

#include <signal.h>

#include <sys/types.h>


void sleepPrint(int, int);

void interruptHandler();

int main(int argc, char** argv) {
    signal(SIGINT, interruptHandler);

    int n = 0;
    sleepPrint(1, ++n);
    sleepPrint(1, ++n);
    sleepPrint(1, ++n);
    sleepPrint(1, ++n);
    sleepPrint(1, ++n);

    printf("Program exiting\n");
    return EXIT_SUCCESS;
}

void sleepPrint(int seconds, int n) {
    printf("Sleep #%d\n", n);
    sleep(seconds);
}

void interruptHandler() {
    printf("Jumped to interrupt handler.\n");
}