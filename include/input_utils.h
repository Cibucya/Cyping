#ifndef INPUT_UTILS_H
#define INPUT_UTILS_H

#include <termios.h>

void disable_input_buffering(struct termios *old);
void restore_input_buffering(struct termios *old);
char getch();

#endif // INPUT_UTLIS_H
