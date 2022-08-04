#include "main.h"

/**
 * _getpath - builds a linked list of
 * folders in the PATH, adding nodes at the end
 * @name: Will be PATH for our purposes, but can be any
 * environment variable.
 * Return: 0 upon success
 */

char **_getpath(char * const envp[])
{
	char *str, *token;
	char **dirs;
	list_t *node, *head;
	int listlength, count;

	head = NULL;
	str = _getenv(envp, "PATH");
	if (str == NULL)
	{
		return (NULL);
	}
	token = strtok(str, "=");
	token = strtok(NULL, ":");
	while (token != NULL)
	{
		add_node_end(&head, token);
		token = strtok(NULL, ":");
	}
	listlength = list_len(head);
	dirs = malloc(sizeof(*dirs) * (listlength + 1));
	if (dirs == NULL)
	{
		return (NULL);
	}

	count = 0;
	node = head;
	while (count < listlength)
	{
		dirs[count] = _strdup(node->str);
		count = count + 1;
		node = node->next;
	}
	free(token);
	dirs[count] = NULL;
	free_list(head);
	return (dirs);
}
