#include "stest_colors.h"
#include "ascii_codes.h"

#include <stdlib.h> // size_t

const ColorChar color_mappings[] = {
	{ DEFAULT_CHAR,   DEFAULT_COLOR  },
	{ ERROR_CHAR,     ERROR_COLOR    },
	{ CORRECT_CHAR,   CORRECT_COLOR  },
	{ WRITTEN_CHAR,   WRITTEN_COLOR  },
	{ INFO_CHAR,      INFO_COLOR     },
	{ UNDERLINE_CHAR, UNDERLINE_CODE }
};

const size_t color_mappings_size = sizeof(color_mappings) / sizeof(color_mappings[0]);

const char* get_color(char symbol) {
	for (size_t i = 0; i < color_mappings_size; ++i) {
		if (color_mappings[i].symbol == symbol) {
			return color_mappings[i].color_code;
		}
	}
	return "";
}
