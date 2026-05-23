#include "phrase.h"

#include <stdlib.h>
#include <string.h>

#include "array_utils.h"
#include "string_utils.h"
#include "file_utils.h"
#include "random.h"

/* !!! Need a call of srand() before !!! */
/* Generates random phrase out of words */
char* generate_rand_phrase(char* const words[], size_t words_size, size_t words_num, size_t* phrase_size) {
	// Cant generate 100 random words if we have <100 words
	if (!words || words_num > words_size) return NULL;

	size_t* rand_idxs = generate_unique_nums(words_num, words_size);

	// Count the length of phrase
	size_t local_phrase_size = 0;
	for (size_t i=0; i<words_num; ++i)
		local_phrase_size += strlen(words[rand_idxs[i]]) + 1; // + space
	local_phrase_size ? local_phrase_size-- : 0; // We dont need space at the end of phrase

	char* phrase = malloc(local_phrase_size + 1);
	if (!phrase) return NULL;

	// Generate phrase
	char* ptr = phrase;
	for (size_t i=0; i<words_num; ++i) {
		size_t len = strlen(words[rand_idxs[i]]);
		memcpy(ptr, words[rand_idxs[i]], len);
		ptr += len;
		if (i < words_num - 1) *ptr++ = ' ';
	}
	*ptr = '\0';

	*phrase_size = local_phrase_size;
	return phrase;
}

/* Gets random phrase using words out of file */
char* get_rand_phrase(const char* path, char delimiter, size_t words_num, size_t* phrase_size) {
	char* words = read_file(path);
	if (!words) return NULL;

	size_t max_words_num = 0;
	char** splitted_words = split_alloc(words, delimiter, &max_words_num);
	free(words);
	if (!splitted_words) return NULL;

	char* phrase = generate_rand_phrase(splitted_words, max_words_num, words_num, phrase_size);
	free_2d_array((void**)splitted_words, max_words_num);

	return phrase;
}
