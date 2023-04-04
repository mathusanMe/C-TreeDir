CC=gcc
CFLAGS=-Wall -std=c99
EXEC=main
SRC= $(wildcard src/*.c src/*/*.c src/*/*/*.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $(EXEC) $^ $(CFLAGS)

%.o : %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf $(OBJ)

mrproper: clean
	rm -rf $(EXEC)