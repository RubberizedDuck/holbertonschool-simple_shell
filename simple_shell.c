#include "main.h"

/**
 * tokens - separates a string by words (tokens) and stores
 * each in an array
 * @string: the string in question
 * Return: 0 (success)
 */

char **tokens(char *string)
{
	list_t *node, *head = NULL;
	char **toks;
	char *token;
	int listlength, count = 0;

	/* First token, delimiter set */
	token = strtok(string, " ");
	if (token == NULL)
	{
		free(token);
		return (NULL);
	}
	add_node(&head, token);
	/* Printing tokens until exhausted */
	while (token != NULL)
	{
		token = strtok(NULL, " ");
		if (token != NULL)
			add_node_end(&head, token);
	}
	listlength = list_len(head);
	toks = malloc(sizeof(*toks) * (listlength + 1));
	if (toks == NULL)
		return (NULL);

	node = head;
	while (count < listlength)
	{
		toks[count] = _strdup(node->str);
		count++;
		node = node->next;
	}
	free(token);
	toks[count] = NULL;
	free_list(head);
	return (toks);
}

/**
 * _getline - prints the command line arguments passed through
 * the main function
 * Return: Always 0 (success)
 */

int _getline(void)
{
	char **args;
	/* define buffer and buffer size */
	char *line;
	size_t len;
	int g, count;

	line = NULL;
	len = 32;

	/* allows to loop forever */
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");

		g = getline(&line, &len, stdin);
		if (g == -1)
		{
			free(line);
			if (g == EOF)
				exit(0);
			else
				exit(1);
		}
		line[_strlen(line) - 1] = '\0';
		args = tokens(line);
		if (args == NULL)
			continue;

		fork_exec(args);
		count = 0;
		while (args[count] != NULL)
		{
			free(args[count]);
			count = count + 1;
		}
		free(args);
	}
	free(line);
	return (0);
}

/**
 * main - returns the result of the _getline function
 * @ac: UNUSED - the number of arguments passed
 * @av: UNUSED - the arguments to be printed as strings
 * Return: the result of the _getline function.
 */

int main(__attribute__ ((unused)) int ac, __attribute__ ((unused)) char *av[])
{
	return (_getline());
}
