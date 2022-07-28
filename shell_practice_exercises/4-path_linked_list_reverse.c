#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "main2.h"

/**
 * *_strdup - returns a pointer to a newly allocated space in memory
 * containing a copy of a string
 * @str: the string
 * Return: a pointer
 */

char *_strdup(const char *str)
{
	char *a;
	unsigned int i, j;

	if (str == NULL)
	{
		return (NULL);
	}

	i = 0;
	while (str[i] != '\0')
	{
		i = i + 1;
	}

	a = malloc(sizeof(*str) * i + 1);
	if (a == NULL)
	{
		return (NULL);
	}

	j = 0;
	while (j < i)
	{
		a[j] = str[j];
		j = j + 1;
	}
	a[j] = '\0';
	return (a);
}

/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: pointer to a pointer to head of linked list
 * @str: string to be assigned to the node
 * Return: the address of the new element, or NULL upon failure
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;

	new_node = malloc(sizeof(*new_node));
	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->str = _strdup(str);
	new_node->next = *head;

	*head = new_node;
	return (new_node);
}

int main ()
{
	char *str, *token;
	list_t *head;

	head = NULL;
	str = getenv("PATH");
	token = strtok(str, ":");
	while (token != NULL)
	{
		add_node(&head, token);
		token = strtok(NULL, ":");
	}
	return (0);
}
