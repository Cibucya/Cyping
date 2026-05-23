#include "random.h"

#include <stdlib.h>
#include <string.h>

size_t* generate_unique_nums(size_t needed_nums, size_t max_num) {
	size_t* rand_idxs = malloc(needed_nums * sizeof(size_t));
	if (!rand_idxs) return NULL;

	int* used = calloc(max_num, sizeof(int));
	if (!used) {
		free(rand_idxs);
		return NULL;
	}

	size_t i = 0;
	while (i < needed_nums) {
		int rand_idx = rand() % max_num;
		if (!used[rand_idx]) {
			rand_idxs[i++] = rand_idx;
			used[rand_idx] = 1;
		}
	}

	free(used);
	return rand_idxs;
}
