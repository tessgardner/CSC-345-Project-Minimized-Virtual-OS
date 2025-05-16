#ifndef VIRTOS_H
#define VIRTOS_H
#include <stdint.h>

// Callback function type for key press events
// used for registering functions that respond to key presses
typedef void (*key_press_callback_t)(int key_code);

// Callback function type for command handling
// Registers command handling functions
typedef void (*command_handler_callback_t)(const char *command_string);

// Function to initialize the OS and display GUI with a virtual keyboard
// this should be the last function you run
// must register handles before initializing !!
void initializeOS();

// Function to register a callback for key press events
// Registers a function that's called whenever a key is pressed
// Sends the keycode to a defined function (The callback variable)
void registerKeyPressCallback(key_press_callback_t callback);

// Function to register a callback for command handling
// Registers/denotes which function is used to execute commands
void registerCommandHandler(command_handler_callback_t callback);

// Function to insert data onto the display 
// can be called by key driver or command handler
void insertKeyData(const char *data);

#endif