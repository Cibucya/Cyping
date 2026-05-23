#include "user_io.h"

#include <stdio.h>
#include <stdlib.h>

#include "phrase.h"
#include "input_utils.h"
#include "output_utils.h"
#include "stest_colors.h"

char* pickup_user_phrase(char* path, char delimiter, size_t words_num, size_t *phrase_size) {
	char* phrase;
	int like_phrase = 0;
	while (!like_phrase) {
		clr_screen();
		phrase = get_rand_phrase(path, delimiter, words_num, phrase_size);
		printf("%s\n\n", phrase);
		printf("Regenerate? (press %s'r'%s if yes)\n", CORRECT_COLOR, DEFAULT_COLOR);
		char ch = getch();
		if (ch != 'r')
			like_phrase = 1;
	}
	return phrase;
}
