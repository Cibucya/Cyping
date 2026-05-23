#include "output_utils.h"

#include <stdio.h>

#include "ascii_codes.h"
#include "stest_colors.h"
#include "array_utils.h"

void clr_screen() {
	printf(CLR_SCREEN_CODE);
}

/* This fuction prints the phrase of the given test with it's colors
 *
 * It works the following way:
 * We are getting color of current symbol in "current_color"
 * Then we count how many times this color appears in a row in phrase_colors
 * If only 1 time then just print the char
 * other wise create a string of text which must be printed with 1 color */
void print_colored_text(const char* text, const char* text_colors, size_t text_size) {
	size_t i = 0;
	while (i < text_size) {
		const char* current_color = get_color(text_colors[i]);
		size_t color_run = count_run(text_colors, i, text_size);
		if (color_run == 1) {
			printf("%s%c%s", current_color, text[i], DEFAULT_COLOR);
			i++;
			continue;
		}

		char* to_print = malloc(color_run * sizeof(char));
		if (!to_print)
			return;

		to_print[color_run] = '\0';
		for (size_t j=0; j<color_run; ++j)
			to_print[j] = text[j + i];
		printf("%s%s%s", current_color, to_print, DEFAULT_COLOR);

		i += color_run;
		free(to_print);
	}
	printf("%s\n", DEFAULT_COLOR);
}

