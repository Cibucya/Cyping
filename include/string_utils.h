#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <stdlib.h> // For size_t

size_t count_splits(const char* str, char delimiter);
char** split_alloc(char* const str, char delimiter, size_t* count);

size_t count_symbol(const char* str, size_t str_size, char target);

#endif // STRING_UTILS_H
