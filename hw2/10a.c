#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/wait.h>

#include <signal.h>
#include <string.h>

#include <sys/types.h>

int main(int argc, char** argv) {
    int pipeArr[2];

    pipe(pipeArr);

    char* message1 = "Message 1\n";
    char* message2 = "Message 2\n";
    char* message3 = "Message 3\n";
    char* message4 = "Message 4\n";
    char* nullTerm = "\0";

    write(pipeArr[1], message1, strlen(message1));
    write(pipeArr[1], message2, strlen(message2));
    write(pipeArr[1], message3, strlen(message3));
    write(pipeArr[1], message4, strlen(message4));
    write(pipeArr[1], nullTerm, strlen(nullTerm));

    int messageLength = strlen(message1) + strlen(message2) + strlen(message3) + strlen(message4) + strlen(nullTerm);
    char message[messageLength];

    read(pipeArr[0], message, messageLength);

    printf("%s\n", message);
}