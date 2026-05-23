#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include <stdlib.h> // For size_t

/* Frees 2 dimentional array */
void free_2d_array(void** arr, size_t count);
size_t count_run(const char* arr, size_t from, size_t to);

#endif // ARRAY_UTILS_H
