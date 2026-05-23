#ifndef STEST_H
#define STEST_H

#include <stddef.h> // For size_t

typedef struct speed_test {
	size_t words_num;
	size_t phrase_size;
	size_t curr_idx;

	size_t errors;
	size_t errors_when_ended;

	double accurancy;
	double wpm;

	char* phrase;
	char* phrase_colors;
} stest;

stest create_stest();
void free_stest(stest* test);

double get_wpm(double words_num, double time_elapsed);
double get_accurancy(size_t phrase_size, size_t errors);
size_t get_errors_when_ended(const char* colors, size_t colors_size);
void setup_stest(stest* test);
void update_stats_stest(stest* test, double time_elapsed);

#endif // STAST_H
