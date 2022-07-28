#ifndef _MAIN_H_
#define _MAIN_H_

#include <stddef.h>

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
	struct list_s *next;
} list_t;

/* string functions */
int _strlen(char *s);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
/* linked list functions */
list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);
size_t print_list(const list_t *head);
void free_list(list_t *head);
size_t list_len(const list_t *head);

#endif /* _MAIN_H_ */
