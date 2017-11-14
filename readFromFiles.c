#include <stdio.h>
#include <string.h>
#include "lib/fileReaders.h"

void int_numbers(char **files, size_t count) {
	for (int i = 0; i < count; i++) {
		size_t n;
		int *numbers = read_int_numbers(files[i], &n);

		for (size_t j = 0; j < n; j++)
			printf("%ld. %d\n", j + 1, numbers[j]);

		free(numbers);
	}
}

void double_numbers(char **files, size_t count) {
	for (int i = 0; i < count; i++) {
		size_t n;
		double *numbers = read_double_numbers(files[i], &n);

		for (size_t j = 0; j < n; j++)
			printf("%ld. %lf\n", j + 1, numbers[j]);

		free(numbers);
	}
}

void lines(char **files, size_t count) {
	for (int i = 0; i < count; i++) {
		size_t n;
		char **lines = read_lines(files[i], &n);

		for (size_t j = 0; j < n; j++)
			printf("%ld. %s\n", j + 1, lines[j]);

		for (size_t j = 0; j < n; j++)
			free(lines[j]);

		free(lines);
	}
}

void lines_non_empty(char **files, size_t count) {
	for (int i = 0; i < count; i++) {
		size_t n;
		char **lines = read_non_empty_lines(files[i], &n);

		for (size_t j = 0; j < n; j++)
			printf("%ld. %s\n", j + 1, lines[j]);

		for (size_t j = 0; j < n; j++)
			free(lines[j]);

		free(lines);
	}
}

void words(char **files, size_t count) {
	for (int i = 0; i < count; i++) {
		size_t n;
		char **words = read_words(files[i], &n);

		for (size_t j = 0; j < n; j++)
			printf("%ld. %s\n", j + 1, words[j]);

		for (size_t j = 0; j < n; j++)
			free(words[j]);

		free(words);
	}
}

void words_delimited(char **files, size_t count, char *delimeters) {
	for (int i = 0; i < count; i++) {
		size_t n;
		char **words = read_delimited_words(files[i], &n, delimeters);

		for (size_t j = 0; j < n; j++)
			printf("%ld. %s\n", j + 1, words[j]);

		for (size_t j = 0; j < n; j++)
			free(words[j]);

		free(words);
	}
}

void examples(char **files, size_t count) {
	for (int i = 0; i < count; i++) {
		size_t n;
		example_t **examples = read_examples(files[i], &n);

		for (size_t j = 0; j < n; j++)
			printf("%ld. %s %s %s age: %d, weight: %lf kg\n", j + 1, examples[j]->surname, examples[j]->name, examples[j]->patronymic, examples[j]->age, examples[j]->weight);

		for (size_t j = 0; j < n; j++) {
			free(examples[j]->surname);
			free(examples[j]->name);
			free(examples[j]->patronymic);

			free(examples[j]);
		}

		free(examples);
	}
}

void examples_bin(char **files, size_t count) {
	for (int i = 0; i < count; i++) {
		size_t n;
		example_bin_t **examples = read_examples_bin(files[i], &n);

		for (size_t j = 0; j < n; j++)
			printf("%ld. %s %s %s age: %d, weight: %lf kg\n", j + 1, examples[j]->surname, examples[j]->name, examples[j]->patronymic, examples[j]->age, examples[j]->weight);

		for (size_t j = 0; j < n; j++)
			free(examples[j]);

		free(examples);
	}
}

int main(int argc, char **argv) {
	if (argc < 3) {
		printf("Incorrect number of arguments.\n");
		return -1;
	}

	if (!strcmp(argv[1], "int"))
		int_numbers(argv + 2, argc - 2);
	else if (!strcmp(argv[1], "double"))
		double_numbers(argv + 2, argc - 2);
	else if (!strcmp(argv[1], "lines"))
		lines(argv + 2, argc - 2);
	else if (!strcmp(argv[1], "lines-non-empty"))
		lines_non_empty(argv + 2, argc - 2);
	else if (!strcmp(argv[1], "words"))
		words(argv + 2, argc - 2);
	else if (!strcmp(argv[1], "words-delimited"))
		words_delimited(argv + 3, argc - 3, argv[2]);
	else if (!strcmp(argv[1], "examples"))
		examples(argv + 2, argc - 2);
	else if (!strcmp(argv[1], "examples-bin"))
		examples_bin(argv + 2, argc - 2);
	else
		printf("Undefined option\n");
	
	return 0;
}