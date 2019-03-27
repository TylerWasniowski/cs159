#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/wait.h>

#include <signal.h>
#include <string.h>

#include <sys/types.h>


void alarmHandler();

int count = 0;

int main(int argc, char** argv) {
    signal(SIGALRM, alarmHandler);

    int pipeArr[2];
    pipe(pipeArr);

    while (1) {
        alarm(1);
        write(pipeArr[1], "a", 1);
        alarm(0);
        count++;

        if (count % (1 << 10) == 0) printf("%d characters in pipe\n", count);
    }

    return EXIT_FAILURE;
}

void alarmHandler() {
    printf("Write blocked after %d characters.\n", count);
    exit(EXIT_SUCCESS);
}