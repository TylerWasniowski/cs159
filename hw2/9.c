#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/wait.h>

#include <signal.h>

#include <sys/types.h>

void alarmHandler();

int main(int argc, char** argv) {
    signal(SIGALRM, alarmHandler);

    printf("Please input a number or this program will self destruct in 10 seconds.\n");
    alarm(10);
    int num;
    scanf("%d", &num);
    alarm(0);

    printf("Alarm disabled with num %d.\n", num);

    return EXIT_SUCCESS;
}

void alarmHandler() {
    printf("Alarm triggered, program exitting.\n");
    exit(EXIT_FAILURE);
}