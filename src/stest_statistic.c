#include "stest_statistic.h"

#include <stdio.h>
#include <stdlib.h>

#include "stest.h"
#include "output_utils.h"

void print_statistic_stest(const stest* test) {
	if (!test) return;

	clr_screen();
	printf("--- Phrase ---\n%s\n ------------ \n", test->phrase);
	printf("%-22s %zu\n", "Words:", test->words_num);
	printf("%-22s %zu\n", "Characters:", test->phrase_size);
	printf("%-22s %zu\n", "Errors:", test->errors);
	printf("%-22s %zu\n", "Errors when finished:", test->errors_when_ended);
	printf("%-22s %.1f%%\n", "Accurancy:", test->accurancy);
	printf("%-22s %.0f\n", "Wpm:", test->wpm);
}
