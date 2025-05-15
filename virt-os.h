#ifndef VIRTOS_H
#define VIRTOS_H

#include <stdint.h>

// Callback function type for key press events
typedef void (*key_press_callback_t)(int key_code);

// Callback function type for command handling
typedef void (*command_handler_callback_t)(const char *command_string);

// Function to initialize the OS and display GUI
// with a virtual keyboard
// this should be the last function you run
void initializeOS();

// Function to register a callback for key press events
void registerKeyPressCallback(key_press_callback_t callback);

// Function to register a callback for command handling
void registerCommandHandler(command_handler_callback_t callback);

// Function to insert data onto the display (can be called by key driver or command handler)
void insertKeyData(const char *data);

#endif