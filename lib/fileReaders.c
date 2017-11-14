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


/*	Reading all non-empty lines from the file "file_path"
	Usage: 
		int n;
		char** lines = readNonEmptyLines("text.txt", &n);
*/
char **read_non_empty_lines(const char *file_path, size_t *length) {
	*length = 0;

	FILE *f = fopen(file_path, "r");

	if (!f)
		return NULL;

	size_t capacity = 1;

	char **lines = (char **) malloc(capacity * sizeof(char *));

	char c = fgetc(f);

	while (c != EOF) {
		size_t line_size = 0;
		size_t line_capacity = 1;
		char *line = (char *) malloc(line_capacity * sizeof(char));

		while (c != EOF && c == '\n')
			c = fgetc(f);

		while (c != EOF && c != '\n') {
			line[line_size++] = c;

			if (line_size >= line_capacity)
				line = (char *) realloc(line, (line_capacity *= 2) * sizeof(char));

			c = fgetc(f);
		}

		line[line_size] = '\0';

		lines[(*length)++] = line;

		if (*length >= capacity) 
			lines = (char **) realloc(lines, (capacity *= 2) * sizeof(char *));
	}

	fclose(f);

	return lines;
}

/*	Reading all lines from the file "file_path"
	Usage: 
		int n;
		char** lines = readLines("text.txt", &n);
*/
char **read_lines(const char *file_path, size_t *length) {
	*length = 0;

	FILE *f = fopen(file_path, "r");

	if (!f)
		return NULL;

	size_t capacity = 1;

	char **lines = (char **) malloc(capacity * sizeof(char *));

	char c = fgetc(f);

	while (c != EOF) {
		size_t line_size = 0;
		size_t line_capacity = 1;
		char *line = (char *) malloc(line_capacity * sizeof(char));

		if (c != '\n') {
			while (c != EOF && c != '\n') {
				line[line_size++] = c;

				if (line_size >= line_capacity)
					line = (char *) realloc(line, (line_capacity *= 2) * sizeof(char));

				c = fgetc(f);
			}
		}
		
		c = fgetc(f);

		line[line_size] = '\0';

		lines[(*length)++] = line;

		if (*length >= capacity) 
			lines = (char **) realloc(lines, (capacity *= 2) * sizeof(char *));
	}

	fclose(f);

	return lines;
}

/*	Reading words from the file "file_path", separated by space
	Usage: 
		int n;
		char** words = readWords("text.txt", &n);
*/
char **read_words(const char *file_path, size_t *length) {
	*length = 0;

	FILE *f = fopen(file_path, "r");

	if (!f)
		return NULL;

	size_t capacity = 1;

	char **words = (char **) malloc(capacity * sizeof(char *));

	char c = fgetc(f);

	while (c != EOF) {
		size_t word_size = 0;
		size_t word_capacity = 1;
		char *word = (char *) malloc(word_capacity * sizeof(char));

		while (c != EOF && (c == '\n' || c == ' '))
			c = fgetc(f);

		while (c != EOF && c != '\n' && c != ' ') {
			word[word_size++] = c;

			if (word_size >= word_capacity)
				word = (char *) realloc(word, (word_capacity *= 2) * sizeof(char));

			c = fgetc(f);
		}

		if (word_size > 0) {
			word[word_size] = '\0';

			words[(*length)++] = word;

			if (*length >= capacity) 
				words = (char **) realloc(words, (capacity *= 2) * sizeof(char *));
		} else
			free(word);
	}

	fclose(f);

	return words;
}

int is_delim(char c, const char* delimeters) {
	size_t delimeters_size = strlen(delimeters);

	for (int i = 0; i < delimeters_size; i++)
		if (c == delimeters[i])
			return 1;

	return 0;
}

/*	Reading words from the file "file_path", separated by symbols from the array of delimiters 'delimeters'
	Usage: 
		int n;
		char** words = readDelimetedWords("text.txt", &n, " !?-");
*/
char **read_delimited_words(const char *file_path, size_t *length, const char *delimeters) {
	*length = 0;

	FILE *f = fopen(file_path, "r");

	if (!f)
		return NULL;

	size_t capacity = 1;
	char **words = (char **) malloc(capacity * sizeof(char *));

	char c = fgetc(f);

	while (c != EOF) {
		size_t word_size = 0;
		size_t word_capacity = 1;
		char *word = (char *) malloc(word_capacity * sizeof(char));

		while (c != EOF && (c == '\n' || is_delim(c, delimeters)))
			c = fgetc(f);

		while (c != EOF && c != '\n' && !is_delim(c, delimeters)) {
			word[word_size++] = c;

			if (word_size >= word_capacity)
				word = (char *) realloc(word, (word_capacity *= 2) * sizeof(char));

			c = fgetc(f);
		}

		if (word_size > 0) {
			word[word_size] = '\0';

			words[(*length)++] = word;

			if (*length >= capacity) 
				words = (char **) realloc(words, (capacity *= 2) * sizeof(char *));
		} else
			free(word);
	}

	fclose(f);

	return words;
}