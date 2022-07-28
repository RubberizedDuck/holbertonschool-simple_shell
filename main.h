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

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

/* string functions */
int _strlen(char *s);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
/* linked list functions */
list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);
size_t print_list(const list_t *head);
void free_list(list_t *head);
size_t list_len(const list_t *head);
/* (insert name of funcs) */
char *_getenv(const char *name);
void print_env(char *env_name);
int _env(void);
void fork_exec(char **argv);

#endif /* _MAIN_H_ */
