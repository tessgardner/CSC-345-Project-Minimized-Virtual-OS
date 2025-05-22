//CJ Sturiale
#include <stdio.h>
#include "virt-os.h"

// Dummy versions of the real functions
void initializeOS() {
    printf("initializeOS() called\n");
}

void registerKeyPressCallback(key_press_callback_t callback) {
    printf("registerKeyPressCallback() called\n");

    // testing a terminal command
    const char *test_command = "ls -l";
    for (int i = 0; test_command[i] != '\0'; i++) {
        callback(test_command[i]);
    }
    callback(13);  // Enter

    // Simulate a user typing "echo Hello", then pressing Enter
    callback('e');
    callback('c');
    callback('h');
    callback('o');
    callback(' ');
    callback('H');
    callback('e');
    callback('l');
    callback('l');
    callback('o');
    callback(13);  // Enter
}

void registerCommandHandler(command_handler_callback_t callback) {
    printf("registerCommandHandler() called\n");
}

void insertKeyData(const char *data) {
    printf("[DISPLAY]: %s", data);
}
