#include "string_utils.h"

#include <stdlib.h>
#include <string.h>

#include "array_utils.h"

/* Counts the number of parts in string */
size_t count_splits(const char* str, char delimiter) {
	size_t count = 0;
	while (*str) {
		if (*str == delimiter) count++;
		str++;
	}
	return count + 1;
}

/* !! Uses strtok(), be careful when will be using multithreading */
char** split_alloc(char* const str, char delimiter, size_t* count) {
	if (!str) return NULL;

	*count = count_splits(str, delimiter);
	char** result = malloc(*count * sizeof(char*));
	if (!result) return NULL;

	char* str_cpy = strdup(str);
	if (!str_cpy) {
		free(result);
		return NULL;
	}

	size_t i = 0;
	char delimiter_str[] = {delimiter, '\0'};
	char* token = strtok(str_cpy, delimiter_str);
	while (token) {
		result[i] = strdup(token);
		if (!result[i]) {
			free_2d_array((void**)result, i);
			free(str_cpy);
			return NULL;
		}
		i++;
		token = strtok(NULL, delimiter_str);
	}

	free(str_cpy);
	return result;
}

size_t count_symbol(const char* str, size_t str_size, char target) {
	size_t result = 0;
	for (size_t i=0; i<str_size; ++i)
		if (str[i] == target) result++;
	return result;
}
