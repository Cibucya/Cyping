#include "../include/file_utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* read_file(const char* path) {
	/* This function returns all data from file */
	FILE* fptr;
	// Opening file
	fptr = fopen(path, "r");
	if (fptr == NULL)
		return NULL;

	// Find out file size
	fseek(fptr, 0, SEEK_END);
	size_t fsize = ftell(fptr);
	rewind(fptr); // Returning to the beginning of the file

	char* buffer = (char*)malloc(fsize + 1);
	if (buffer == NULL) {
		perror("Failed to malloc");
		fclose(fptr);
		return NULL;
	}

	fread(buffer, 1, fsize, fptr);
	buffer[fsize] = 0;

	fclose(fptr);

	return buffer;
}
