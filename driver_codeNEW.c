//CJ Sturiale
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "virt-os.h"

#define MAX_BUFFER 1024
char command_buffer[MAX_BUFFER];
int buffer_index = 0;

void my_key_press_callback(int key_code) {
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
        my_command_handler_callback(command_buffer);
        buffer_index = 0;
    } else if ((key_code >= 32 && key_code <= 126) && buffer_index < MAX_BUFFER - 1) {
        char c = (char) key_code;
        command_buffer[buffer_index++] = c;
        char str[2] = {c, '\0'};
        insertKeyData(str);
    }
}

void my_command_handler_callback(const char *command_string) {
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
    registerKeyPressCallback(my_key_press_callback);
    registerCommandHandler(my_command_handler_callback);
    initializeOS();
    return 0;
}
