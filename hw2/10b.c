#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/wait.h>

#include <signal.h>
#include <string.h>

#include <sys/types.h>

int main(int argc, char** argv) {
    char* message1 = "Message 1";
    char* message2 = "Message 2";
    char* message3 = "Message 3";
    char* message4 = "Message 4";


    int pipeArr[2];
    pipe(pipeArr);

    printf("About to fork\n");
    fflush(stdin);
    switch (fork()) {
        case 0:
            printf("I am the child. Closing write end...\n");
            close(pipeArr[1]);

            char res1[10];
            char res2[10];
            char res3[10];
            char res4[10];

            printf("This is the child process. Reading first message from the pipe.\n");
            read(pipeArr[0], res1, 10);
            printf("This is the child process. Finished Reading. First message is: %s\n", res1);

            printf("This is the child process. Reading second message from the pipe.\n");
            read(pipeArr[0], res2, 10);
            printf("This is the child process. Finished Reading. Second message is: %s\n", res2);

            printf("This is the child process. Reading third message from the pipe.\n");
            read(pipeArr[0], res3, 10);
            printf("This is the child process. Finished Reading. Third message is: %s\n", res3);

            printf("This is the child process. Reading fourth message from the pipe.\n");
            read(pipeArr[0], res4, 10);
            printf("This is the child process. Finished Reading. Fourth message is: %s\n", res4);

            printf("Child process exiting.\n");

            exit(EXIT_SUCCESS);
        case -1:
            printf("Error forking. Exiting...\n");
            return EXIT_FAILURE;
            break;
        default:
            printf("I am the parent. Closing read end...\n");
            close(pipeArr[0]);

            printf("This is the parent process. Writing first message into the pipe.\n");
            write(pipeArr[1], message1, strlen(message1) + 1);

            printf("This is the parent process. Writing second message into the pipe.\n");
            write(pipeArr[1], message2, strlen(message2) + 1);

            printf("This is the parent process. Writing third message into the pipe.\n");
            write(pipeArr[1], message3, strlen(message3) + 1);

            printf("This is the parent process. Writing fourth message into the pipe.\n");
            write(pipeArr[1], message4, strlen(message4) + 1);

            printf("Parent process waiting on child.\n");
            wait(NULL);

            printf("Parent process exiting.\n");

            return EXIT_SUCCESS;
    }
}