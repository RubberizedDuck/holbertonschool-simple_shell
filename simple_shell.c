#include "main.h"

/**
 * tokens - separates a string by words (tokens) and stores
 * each in an array
 * @string: the string in question
 * Return: 0 (success)
 */

char **tokens(char *string)
{
	char **toks;
	char *token;
	int count = 0;

	toks = malloc(sizeof(*toks) * 32);
	if (toks == NULL)
	{
		return (NULL);
	}
	/* First token, delimiter set */
	token = strtok(string, " ");
	/* Printing tokens until exhausted */
	while (token != NULL)
	{
		toks[count] = _strdup(token);
		token = strtok(NULL, " ");
		count = count + 1;
	}
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
			if (isatty(STDIN_FILENO))
				printf("\n");
			exit(0);
		}
		if (g == EOF)
		{
			printf("\n");
			exit(0);
		}
		line[_strlen(line) - 1] = '\0';
		args = tokens(line);
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
