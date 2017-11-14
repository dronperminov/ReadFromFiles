# ReadFromFiles
Algorithms for reading information from files to an array

## Code can read
- Int array
- Double array
- All text lines
- All non empty text lines
- Words
- Words, separated by delimiters characters
- Example struct with int, double and three char* fields
- Example struct with int, double and three char* fields from _binary_ file
- Double matrix

## Int array
Reading integer numbers from the file `file_path` and save amount of elements to `n`

### Prototype:
```
int* read_int_numbers(const char *file_path, size_t *length);
```
### Usage:
```
int n;  
int* numbers = read_int_numbers("file.txt", &n);
```
  
## Double array
Reading real numbers from the file `file_path` and save amount of elements to `n`
### Prototype:
```
double* read_double_numbers(const char *file_path, size_t *length);
```
### Usage:
```
int n;  
int* numbers = read_double_numbers("file.txt", &n);
```

## All text lines
Reading all lines from the file `file_path` and save amount of lines to `n`
### Prototype:
```
char **read_lines(const char *file_path, size_t *length);
```
### Usage:
```
int n;  
char** lines = read_lines("file.txt", &n);
```

## All non empty text lines
Reading all non empty lines from the file `file_path` and save amount of lines to `n`
### Prototype:
```
char **read_non_empty_lines(const char *file_path, size_t *length);
```
### Usage:
```
int n;  
char** lines = read_non_empty_lines("file.txt", &n);
```

## Words
Reading words from the file `file_path`, separated by space and save amount of words to `n`
### Prototype:
```
char **read_words(const char *file_path, size_t *length);
```
### Usage:
```
int n;  
char** words = read_words("file.txt", &n);
```

## Words, separated by delimiters characters
Reading words from the file `file_path`, separated by `delimeters` characters and save amount of words to `n`
### Prototype:
```
char **read_delimited_words(const char *file_path, size_t *length, const char *delimeters);
```
### Usage:
```
int n;
const char *delimeters = " !?.";
char** words = read_delimited_words("file.txt", &n);
```

## Example struct with int, double and three char* fields
Reading struct example_t from the file `file_path` and save amount of structs to `n`
### Prototype:
```
typedef struct example_t {
	char *surname;
	char *name;
	char *patronymic;
	int age;
	double weight;
} example_t;

example_t **read_examples(const char *file_path, size_t *length);
```
### Usage:
```	 
int n;
example_t **examples = read_examples("file.txt", &n);
```
## Example struct with int, double and three char* fields from _binary_ file
Reading struct example_bin_t from the file `file_path` from binary file and save amount of structs to `n`
### Prototype:
```	
typedef struct example_bin_t {
	char surname[32];
	char name[32];
	char patronymic[32];
	int age;
	double weight;
} example_bin_t;

example_bin_t **read_examples_bin(const char *file_path, size_t *length);
```	
### Usage:
```	 
int n;
example_bin_t **examples = read_examples_bin("file.bin", &n);
```

## Double matrix
Reading double matrix from the file `file_path`, in first row at file  
Тhe first line of the file contains the dimensions of the matrix
### Prototype:
```	
double **read_matrix(const char *file_path, size_t *n, size_t *m);
```	
### Usage:
```	
int n, m;
double **matrix = read_matrix("file.txt", &n, &m);
```	
File `file.txt` example:
```
4 5
1 4 3 4 5
6 7 3 9 0
1 2 1 2 0
0 0 0 0 1
```
