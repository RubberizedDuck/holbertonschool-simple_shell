#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

extern char **environ;

char *_getenv(const char *name);
int _strlen(char *s);

#endif /* _MAIN_H_ */
