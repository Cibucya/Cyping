#include "array_utils.h"

#include <stdlib.h>

/* Frees 2 dimentional array */
void free_2d_array(void** arr, size_t count) {
	if (!arr) return;
	for (size_t i=0; i<count; ++i) free(arr[i]);
	free(arr);
}

size_t count_run(const char* arr, size_t from, size_t to) {
	if (from > to)
		return 0;

	char prev = arr[from++];
	size_t count = 1;
	for (; from < to; ++from) {
		if (arr[from] != prev)
			break;
		++count;
	}
	return count;
}
