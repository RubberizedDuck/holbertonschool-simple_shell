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
	_getenv.c

SRC2=	*.c

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

betty:
	$(BETTY) $(SRC)

val:
	$(VALGRIND) $(VFLAGS)
