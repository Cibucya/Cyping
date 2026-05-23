#include "input_utils.h"

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

// Disables canonical mode and echo
void disable_input_buffering(struct termios *old) {
    if (tcgetattr(0, old) < 0)
        perror("tcgetattr()");  // Save current terminal settings

    struct termios new = *old;
    new.c_lflag &= ~ICANON;  // Disable canonical mode
    new.c_lflag &= ~ECHO;    // Disable echo
    new.c_cc[VMIN] = 1;      // Read at least one character
    new.c_cc[VTIME] = 0;     // No timeout

    if (tcsetattr(0, TCSANOW, &new) < 0)
        perror("tcsetattr ICANON");  // Apply new settings
}

// Restore original terminal settings
void restore_input_buffering(struct termios *old) {
    if (tcsetattr(0, TCSADRAIN, old) < 0)
        perror("tcsetattr ~ICANON");  // Restore original settings
}

// Reads a single character
char getch() {
    char buf = 0;
    struct termios old;

    disable_input_buffering(&old);  // Disable input buffering
    if (read(0, &buf, 1) < 0)
        perror("read()");  // Read one character
    restore_input_buffering(&old);  // Restore original settings

    return buf;  // Return the read character
}
