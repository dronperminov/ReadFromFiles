#include "fileReaders.h"

/*	Reading integer numbers from the file "file_path"
	Usage: 
		int n;
		int* numbers = readIntNumbers("numbers.txt", &n);
*/
int* read_int_numbers(const char *file_path, size_t *length) {
	*length = 0;

	FILE *f = fopen(file_path, "r");

	if (!f)
		return NULL;

	size_t capacity = 1;

	int *numbers = (int *) malloc(capacity * sizeof(int));

	while (fscanf(f, "%d", &numbers[(*length)]) != EOF) {
		(*length)++;

		if (*length >= capacity)
			numbers = (int *) realloc(numbers, (capacity *= 2) * sizeof(int));
	}

	fclose(f);

	return numbers;
}

/*	Reading double numbers from the file "file_path"
	Usage: 
		int n;
		int* numbers = readDoubleNumbers("numbers.txt", &n);
*/
double* read_double_numbers(const char *file_path, size_t *length) {
	*length = 0;

	FILE *f = fopen(file_path, "r");

	if (!f)
		return NULL;

	size_t capacity = 1;

	double *numbers = (double *) malloc(capacity * sizeof(double));

	while (fscanf(f, "%lf", &numbers[(*length)]) != EOF) {
		(*length)++;

		if (*length >= capacity)
			numbers = (double *) realloc(numbers, (capacity *= 2) * sizeof(int));
	}

	fclose(f);

	return numbers;
}