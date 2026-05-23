#ifndef STEST_COLORS_H
#define STEST_COLORS_H

#include "ascii_codes.h"

typedef struct {
	char symbol;
	const char* color_code;
} ColorChar;

#define DEFAULT_COLOR  DEFAULT_CODE

#define ERROR_COLOR    BRIGHT_RED_CODE
#define CORRECT_COLOR  BRIGHT_GREEN_CODE
#define INFO_COLOR     BRIGHT_BLUE_CODE
#define WRITTEN_COLOR  DARK_WHITE_CODE

#define DEFAULT_CHAR   'd'
#define ERROR_CHAR     'e'
#define CORRECT_CHAR   'c'
#define WRITTEN_CHAR   'w'
#define INFO_CHAR      'i'
#define UNDERLINE_CHAR 'u'

extern const ColorChar color_mappings[];

const char* get_color(char symbol);

#endif // STEST_COLORS_H
