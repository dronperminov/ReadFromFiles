APPLICATION=ReadFromFiles
COMPLIER=clang
FILES=readFromFiles.c lib/*.c
FLAGS=-Wall -fsanitize=address

all:
	$(COMPLIER) $(FLAGS) $(FILES) -o $(APPLICATION)

clean:
	rm -rf $(APPLICATION)