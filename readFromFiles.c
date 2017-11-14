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

int main(int argc, char **argv) {
	if (argc < 3) {
		printf("Incorrect number of arguments.\n");
		return -1;
	}

	if (!strcmp(argv[1], "int"))
		int_numbers(argv + 2, argc - 2);
	else if (!strcmp(argv[1], "double"))
		double_numbers(argv + 2, argc - 2);
	else
		printf("Undefined option\n");
	
	return 0;
}