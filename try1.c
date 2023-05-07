#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX 1024

int main() {
    char command[MAX];
    char *args[MAX/2 + 1];
    char *token;

    while (1) {
        printf("AH $$ ");
        fflush(stdout);

        fgets(command, MAX, stdin);

        
        command[strcspn(command, "\n")] = '\0';

        
        token = strtok(command, " ");
        int i = 0;
        while (token != NULL) {
            args[i] = token;
            i++;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        if (strcmp(args[0], "exit") == 0) {
            exit(0);
        }

        if (strcmp(args[0], "cd") == 0) {
            if (args[1] == NULL) {
                fprintf(stderr, "mysh: expected argument to \"cd\"\n");
            } else {
                if (chdir(args[1]) != 0) {
                    perror("mysh");
                }
            }
            continue;
        }
        pid_t pid = fork();

        if (pid == -1) {
            perror("Error");
            exit(1);
        } else if (pid == 0) {
            execvp(args[0], args);
            perror("Error");
            exit(1);
        } else {
            wait(NULL);
        }
    }

    return 0;
}
