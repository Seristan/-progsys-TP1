#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 256
#define PROMPT_MAX_LENGTH 256

int lastStatus = 0;  // status of the latest command

void displayWelcomeMessage() {
    const char *welcome_message = "Bienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\n";
    write(STDOUT_FILENO, welcome_message, strlen(welcome_message));
}

void ByeMessage(){

    const char *bye_message = "Bye bye \n";
    write(STDOUT_FILENO, bye_message, strlen(bye_message));
}


void displayPrompt() {
    char prompt[PROMPT_MAX_LENGTH];
    char *format = "enseash [exit:%d] %% ";
    sprintf(prompt, format, lastStatus);

    write(STDOUT_FILENO, prompt, strlen(prompt));
}


void readCommand(char *command) {
    ssize_t length = read(STDIN_FILENO, command, MAX_COMMAND_LENGTH - 1);
    // Check for read errors
    if (length < 0) { //Exit for ctrl+D
        perror("read");
        exit(EXIT_FAILURE);  // Exit on read error
    }
    if (command[length - 1] == '\n' != 0) {
        command[length - 1] = '\0'; // Replace the newline character with a null terminator
    }
}


int executeCommand(const char *command) {
    pid_t pid = fork();
    int status;

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Execute command without arguments
        execlp(command, command, (char *)NULL);
        // If execlp returns, it must have failed
        perror("execlp");
        _exit(EXIT_FAILURE);
    }else {
        // Parent process, wait for the child to complete
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {//macro returns a non-zero value if the child process terminated normally.
            return WEXITSTATUS(status);
        } else if (WIFSIGNALED(status)) {  // The WIFSIGNALED macro returns a non-zero value if the child process terminated because
            // it received a signal that was not caught.
            return WTERMSIG(status);
        }
    }
    return 0;
}
int main() {
    displayWelcomeMessage();
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        displayPrompt();
        readCommand(command);

        if (strcmp(command, "exit") == 0) {
            ByeMessage();
            exit(EXIT_SUCCESS);
        }

        lastStatus = executeCommand(command);
    }
}