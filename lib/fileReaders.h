#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// example struct for reading
typedef struct example_t {
	char *surname;
	char *name;
	char *patronymic;
	int age;
	double weight;
} example_t;

// unfortunately, strings must be of constant length
typedef struct example_bin_t {
	char surname[32];
	char name[32];
	char patronymic[32];
	int age;
	double weight;
} example_bin_t;

int* read_int_numbers(const char *file_path, size_t *length);
double* read_double_numbers(const char *file_path, size_t *length);

char **read_lines(const char *file_path, size_t *length);
char **read_non_empty_lines(const char *file_path, size_t *length);

char **read_words(const char *file_path, size_t *length);
char **read_delimited_words(const char *file_path, size_t *length, const char *delimeters);

example_t **read_examples(const char *file_path, size_t *length);
example_bin_t **read_examples_bin(const char *file_path, size_t *length);