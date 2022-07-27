#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

extern char **environ;

char *_getenv(const char *name);
int _strlen(char *s);
void print_env(char *env_name);
int _env(void);
void fork_exec(char **argv);

#endif /* _MAIN_H_ */
