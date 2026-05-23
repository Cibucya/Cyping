#include "stest_logic.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "stest.h"
#include "stest_statistic.h"

#include "stest_colors.h"
#include "ascii_codes.h"

#include "array_utils.h"
#include "string_utils.h"

#include "input_utils.h"
#include "output_utils.h"

/* ! Doesn't count errors_when_ended */
void input_logic_stest(stest* test) {
	char user_input = getch();
	if (user_input == test->phrase[test->curr_idx]) {
		test->phrase_colors[test->curr_idx++] = CORRECT_CHAR;
	}
	else if (user_input == BACKSPACE_CODE) {
		if (test->curr_idx > 0) {
			test->phrase_colors[test->curr_idx--] = DEFAULT_CHAR;
		}
	}
	else {
		test->errors++;
		test->phrase_colors[test->curr_idx++] = ERROR_CHAR;
	}
	test->phrase_colors[test->curr_idx] = UNDERLINE_CHAR;
}

/* Returns time spent to complete the test (in seconds) */
double game_loop_stest(stest* test) {
	clock_t start = time(NULL);
	while (test->curr_idx < test->phrase_size) {
		clr_screen();
		print_colored_text(test->phrase, test->phrase_colors, test->phrase_size);
		input_logic_stest(test);
	}
	clock_t end = time(NULL);
	return difftime(end, start); // Difference in seconds
}

void complete_stest(stest* test) {
	setup_stest(test);
	double time_elapsed = game_loop_stest(test);

	update_stats_stest(test, time_elapsed);
	print_statistic_stest(test);
}
