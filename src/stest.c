#include "stest.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "stest_colors.h"
#include "ascii_codes.h"
#include "array_utils.h"
#include "string_utils.h"
#include "input_utils.h"
#include "output_utils.h"

stest create_stest() {
	stest test;

	test.words_num = 0;
	test.phrase_size = 0;
	test.curr_idx = 0;

	test.errors = 0;
	test.errors_when_ended = 0;

	test.accurancy = 0;
	test.wpm = 0;

	test.phrase = NULL;
	test.phrase_colors = NULL;

	return test;
}

void free_stest(stest* test) {
	free(test->phrase);
	free(test->phrase_colors);
}

double get_wpm(double words_num, double time_elapsed) {
	return words_num / (time_elapsed / 60.0);
}

double get_accurancy(size_t phrase_size, size_t errors) {
	return (((double)phrase_size - (double)errors) / (double)phrase_size) * 100.0;
}

size_t get_errors_when_ended(const char* colors, size_t colors_size) {
	return count_symbol(colors, colors_size, ERROR_CHAR);
}

void setup_stest(stest* test) {
	if (test->phrase) {
		if (!test->phrase_colors) { // We have phrase but dont know colors
			test->phrase_colors = malloc(test->phrase_size);
			for (int i=0; i<test->phrase_size; ++i) {
				if (i == test->curr_idx) {
					test->phrase_colors[i] = UNDERLINE_CHAR;
					continue;
				} test->phrase_colors[i] = DEFAULT_CHAR;
			}
		}
	}
}

void update_stats_stest(stest* test, double time_elapsed) {
	test->errors_when_ended = get_errors_when_ended(test->phrase_colors, test->phrase_size);
	test->accurancy = get_accurancy(test->phrase_size, test->errors);
	test->wpm = get_wpm((double)test->words_num, time_elapsed);
}
