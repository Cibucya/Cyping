#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <time.h>

#include "stest.h"
#include "stest_logic.h"
#include "phrase.h"
#include "user_io.h"

int main(int argc, char** argv) {
	srand(time(NULL));
	stest curr_test = create_stest();

	printf("How many words?: ");
	scanf("%zu", &curr_test.words_num);

	// Picking up a phrase for a user
	curr_test.phrase = pickup_user_phrase("../words/keybr.txt", '\n', curr_test.words_num, &curr_test.phrase_size);

	complete_stest(&curr_test);

	return 0;
}
