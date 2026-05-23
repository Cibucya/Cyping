#ifndef PHRASE_H
#define PHRASE_H

#include <stddef.h>

/* !!! Need a call of srand() before !!! */
/* Generates random phrase out of words */
char* generate_rand_phrase(char* const words[], size_t words_size, size_t words_num, size_t* phrase_size);

/* Gets random phrase using words out of file */
char* get_rand_phrase(const char* path, char delimiter, size_t words_num, size_t* phrase_size);

#endif // PHRASE_H
