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
 * add_node_end - adds a new node at the end of a list_t list
 * @head: pointer to a pointer to head of linked list
 * @str: string to be assigned to the node
 * Return: the address of the new element, or NULL upon failure
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node, *last_node;

	new_node = malloc(sizeof(*new_node));
	if (new_node == NULL || str == NULL)
	{
		return (NULL);
	}

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}
	else
	{
		last_node = *head;
		while (last_node->next != NULL)
		{
			last_node = last_node->next;
		}
	}
	last_node->next = new_node;
	return (new_node);
}

/**
 * main - builds a linked list, adding nodes at the end
 * Return: 0 upon success
 */

int main ()
{
	char *str, *token;
	list_t *head;

	head = NULL;
	str = getenv("PATH");
	token = strtok(str, ":");
	while (token != NULL)
	{
		add_node_end(&head, token);
		token = strtok(NULL, ":");
	}
	print_list(head);
	return (0);
}
