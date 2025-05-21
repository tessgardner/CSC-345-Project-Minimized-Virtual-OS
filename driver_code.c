// Names: CJ Sturiale and Tess Gardner
// Date: 05/24/25
/* Description: The goal of this project is to get familiar some ideas 
of an Operating System. For this project, you will work with a Virtual 
screen and Virtual keyboard via a custom library. As this OS has 
little-to-no functionality you will be building drivers (i.e.,
functions) to it get it working appropriately. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "virt-os.h"

#define MAX_BUFFER 1024
char command_buffer[MAX_BUFFER];
int buffer_index = 0;

void command_handler_driver(const char *command_string);

void keyboard_driver(int key_code) {
    if (key_code == 27) {  // ESC
        exit(0);
    } else if (key_code == 8) {  // Backspace
         if (buffer_index > 0) {
            buffer_index--;
            insertKeyData("Backspace");
        }
    } else if (key_code == 13) {  // Enter
        insertKeyData("\n");
        command_buffer[buffer_index] = '\0';
        command_handler_driver(command_buffer);
        buffer_index = 0;
    } else if ((key_code >= 32 && key_code <= 126) && buffer_index < MAX_BUFFER - 1) {
        char c = (char) key_code;
        command_buffer[buffer_index++] = c;
        char str[2] = {c, '\0'};
        insertKeyData(str);
    }
    else if (buffer_index >= MAX_BUFFER - 1) { // Overflow error
        insertKeyData("\n[Error]: Command too long.\n");
    }
}

void command_handler_driver(const char *command_string) {
    FILE *fp = popen(command_string, "r");
    if (fp == NULL) {
        insertKeyData("Command failed.\n");
        return;
    }

    char output[256];
    while (fgets(output, sizeof(output), fp)) {
        insertKeyData(output);
    }

    pclose(fp);
}

int main() {
    registerKeyPressCallback(keyboard_driver);
    registerCommandHandler(command_handler_driver);
    initializeOS();
    return 0;
}
