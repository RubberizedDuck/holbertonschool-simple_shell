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
	int count;

	toks = malloc(sizeof(*toks) * 32);
	if (toks == NULL)
	{
		return (NULL);
	}
	/* First token, delimiter set */
	token = strtok(string, " ");
	if (token == NULL)
	{
		free(toks);
		return (NULL);
	}
	/* Printing tokens until exhausted */
	count = 0;
	while (token != NULL)
	{
		toks[count] = _strdup(token);
		token = strtok(NULL, " ");
		count = count + 1;
	}
	toks[count] = NULL;
	return (toks);
}

/**
 * _getline - prints the command line arguments passed through
 * the main function
 * @envp: the current environment
 * Return: Always 0 (success)
 */

int _getline(char * const envp[])
{
	char **args, **dirs;
	/* define buffer and buffer size */
	char *line = NULL;
	size_t len = 32;
	int g, count;

	dirs = _getpath(envp);
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

		assess_input(args, envp, dirs);
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

int main(__attribute__ ((unused)) int ac, __attribute__ ((unused)) char *av[],
	 char * const envp[])
{
	return (_getline(envp));
}
