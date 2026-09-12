.DEFAULT_GOAL := all

CC = gcc
CFLAGS = -Wall -Wextra -g

prog1: prog1.c
	$(CC) $(CFLAGS) -o prog1 prog1.c

shellforge: shellforge.c parser.c
	$(CC) $(CFLAGS) -Iinclude -o shellforge shellforge.c parser.c

all: prog1 shellforge

run:
	./shellforge

clean:
	rm -f prog1 shellforge


