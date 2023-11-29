#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define MAX_COMMAND_LENGTH 256 // size of a buffer used to store commands entered by the user,
// 256 byte is arbitrary but should be enough for any command


int main() {
    char *welcome_message = "Bienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\n";
    write(STDOUT_FILENO, welcome_message, strlen(welcome_message)); // display the welcome message
    
    while (1){
        char command[MAX_COMMAND_LENGTH];
        char *prompt = "enseash % ";
        write(STDOUT_FILENO, prompt, strlen(prompt));
        ssize_t length = read(STDIN_FILENO, command, MAX_COMMAND_LENGTH - 1); // Read user input


        if (length > 0 && command[length - 1] == '\n')
        {
            command[length - 1] = '\0'; // Replacing the newline character with an end of string
        }

        // exit the program when "exit" is entered in the shell
        if (strcmp(command, "exit") == 0) {
            exit(0);
        }

}
    return 0;
}

