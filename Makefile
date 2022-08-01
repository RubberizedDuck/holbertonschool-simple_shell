# Compiling for the hsh simple shell requirements are as follows;
# gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -std=gnu89

TARGET=hsh
SRC=	simple_shell.c \
	string_funcs.c \
	linklist_funcs.c \
	fork_exec.c

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)