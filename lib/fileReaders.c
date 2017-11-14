#include "fileReaders.h"

/*	Reading integer numbers from the file "file_path"
	Usage: 
		int n;
		int* numbers = read_int_numbers("numbers.txt", &n);
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
		int* numbers = read_double_numbers("numbers.txt", &n);
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
			numbers = (double *) realloc(numbers, (capacity *= 2) * sizeof(double));
	}

	fclose(f);

	return numbers;
}


/*	Reading all non-empty lines from the file "file_path"
	Usage: 
		int n;
		char** lines = read_non_empty_lines("text.txt", &n);
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
		char** lines = read_lines("text.txt", &n);
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
		char** words = read_words("text.txt", &n);
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
		char** words = read_delimeted_words("text.txt", &n, " !?-");
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

/*	Reading struct example_t from the file "file_path"
	Usage: 
		int n;
		example_t **examples = read_examples("text.txt", &n);
*/
example_t **read_examples(const char *file_path, size_t *length) {
	*length = 0;

	FILE *f = fopen(file_path, "r");

	if (!f)
		return NULL;

	size_t capacity = 1;
	example_t **examples = (example_t **) malloc(capacity * sizeof(example_t *));
	examples[0] = (example_t *) malloc(sizeof(example_t));
	examples[0]->surname = (char *) malloc(32 * sizeof(char));
	examples[0]->name = (char *) malloc(32 * sizeof(char));
	examples[0]->patronymic = (char *) malloc(32 * sizeof(char));

	while (fscanf(f, "%s %s %s %d %lf", examples[*length]->surname, examples[*length]->name, examples[*length]->patronymic, &examples[*length]->age, &examples[*length]->weight) != EOF) {
		(*length)++;

		if (*length >= capacity)
			examples = (example_t **) realloc(examples, (capacity *= 2) * sizeof(example_t *));

		examples[*length] = (example_t *) malloc(sizeof(example_t));
		examples[*length]->surname = (char *) malloc(32 * sizeof(char));
		examples[*length]->name = (char *) malloc(32 * sizeof(char));
		examples[*length]->patronymic = (char *) malloc(32 * sizeof(char));
	}

	free(examples[*length]->surname);
	free(examples[*length]->name);
	free(examples[*length]->patronymic);
	free(examples[*length]);

	fclose(f);

	return examples;
}

/*	Reading struct example_bin_t from the BINARY file "file_path"
	Usage: 
		int n;
		example_bin_t **examples = read_examples_bin("text.txt", &n);
*/
example_bin_t **read_examples_bin(const char *file_path, size_t *length) {
	*length = 0;

	FILE *f = fopen(file_path, "rb");

	if (!f)
		return NULL;

	size_t capacity = 1;

	example_bin_t **examples = (example_bin_t **) malloc(capacity * sizeof(example_bin_t *));
	examples[0] = (example_bin_t *) malloc(sizeof(example_bin_t));

	while (fread(examples[*length], sizeof(example_bin_t), 1, f) > 0) {
		(*length)++;

		if (*length >= capacity)
			examples = (example_bin_t **) realloc(examples, (capacity *= 2) * sizeof(example_bin_t *));

		examples[*length] = (example_bin_t *) malloc(sizeof(example_bin_t));
	}

	free(examples[*length]);

	fclose(f);

	return examples;
}

/*	Reading double matrix from the file "file_path"
	Usage: 
		int n, m;
		double **examples = read_matrix("text.txt", &n, &m);
*/
double **read_matrix(const char *file_path, size_t *n, size_t *m) {
	*n = *m = 0;

	FILE *f = fopen(file_path, "r");

	if (!f)
		return NULL;

	fscanf(f, "%ld %ld", n, m);

	double **matrix = (double **) malloc(*n * sizeof(double *));

	for (int i = 0; i < *n; i++) {
		matrix[i] = (double *) malloc(*m * sizeof(double));

		for (int j = 0; j < *m; j++)
			fscanf(f, "%lf", &matrix[i][j]);
	}

	fclose(f);

	return matrix;
}