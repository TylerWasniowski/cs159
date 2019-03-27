#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/wait.h>

#include <sys/types.h>


void sleepPrint(int, int);

int main(int argc, char** argv) {
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