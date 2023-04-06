CC=gcc
SHELL=/bin/bash
CFLAGS=-Wall -std=c99
EXEC=main
SRC= $(shell find src/ -maxdepth 3 -type f -regex ".*\.c")
OBJ= $(patsubst src/%, bin/%, $(SRC:.c=.o))
DIR = $(patsubst src/%, bin/%, $(shell find src/ -maxdepth 2 -type d))

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $^

bin/%.o: src/%.c | directories
	$(CC) $(CFLAGS) -o $@ -c $<

directories: 
	mkdir -p $(DIR) 1>/dev/null

.PHONY: clean mrproper

clean:
	rm -rf $(OBJ)

mrproper: clean
	rm -rf $(EXEC)%.o : %.c
	rm -R bin
