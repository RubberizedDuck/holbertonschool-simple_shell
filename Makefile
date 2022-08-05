# Compiling for the hsh simple shell requirements are as follows;
# gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -std=gnu89 -g
BETTY=betty
VALGRIND=valgrind
VFLAGS= --leak-check=full --show-leak-kinds=all ./hsh

TARGET=hsh
SRC=	simple_shell.c \
	string_funcs.c \
	linklist_funcs.c \
	fork_exec.c \
	_getpath.c \
	_stat.c \
	assess_input.c \
	builtin_funcs.c \
	_getenv.c

SRC2=	*.c

all: 1 2

1:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

2:
	$(CC) $(CFLAGS) $(SRC2) -o $(TARGET)

betty:
	$(BETTY) $(SRC2)

val:
	$(VALGRIND) $(VFLAGS)
