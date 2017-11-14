#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* read_int_numbers(const char *file_path, size_t *length);
double* read_double_numbers(const char *file_path, size_t *length);

char **read_lines(const char *file_path, size_t *length);
char **read_non_empty_lines(const char *file_path, size_t *length);

char **read_words(const char *file_path, size_t *length);
char **read_delimited_words(const char *file_path, size_t *length, const char *delimeters);