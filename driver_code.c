// Name: Tess Gardner
// Date: 05/24/25
/* Description: The goal of this project is to get familiar some ideas 
of an Operating System. For this project, you will work with a Virtual 
screen and Virtual keyboard via a custom library. As this OS has 
little-to-no functionality you will be building drivers (i.e.,
functions) to it get it working appropriately. */

#include <stdio.h>
#include "virt-os.h" 


// CALLBACK FUNCTION
// main driver for keyboard
// used for registering functions that respond to key presses
void my_key_press_callback (int key_code) {
    printf("Hello world");

}

// CALLBACK FUNCTION
// command executor
// Registers command handling functions
void my_command_handler_callback (const char *command_string) {
    printf("Hello world");

}

// MAIN
int main () {
    
    registerKeyPressCallback(my_key_press_callback);
    registerCommandHandler(my_command_handler_callback);
    //insertKeyData(const char *data);


    initializeOS();

    return 0;
}
