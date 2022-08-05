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
		return (NULL);
	/* First token, delimiter set */
	token = strtok(string, " \t\r\n");
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
		token = strtok(NULL, " \t\r\n");
		count = count + 1;
	}
	toks[count] = NULL;
	free(token);
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
	char *line = NULL;
	size_t len = 32;
	int g, count = 0, i = 0;

	dirs = _getpath(envp);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");

		g = getline(&line, &len, stdin);
		if (g == -1)
		{
			if (g == EOF)
				break;
		}
		line[_strlen(line) - 1] = '\0';
		args = tokens(line);
		if (args == NULL)
			continue;
		if (_builtin(args) == -1)
		{
			if (args[count] != NULL)
				free_tab(args);
			exit(2);
			break;
		}
		else
		{
			if (assess_input(args, envp, dirs) == -1)
				printf("command not found\n");
			count = 0;
			if (args[count] != NULL)
				free_tab(args);
		}
	}
	if (dirs[i] != NULL)
		free_tab(dirs);
	free(line);
	return (0);
}

/**
 * main - returns the result of the _getline function
 * @ac: UNUSED - the number of arguments passed
 * @av: UNUSED - the arguments to be printed as strings
 * @envp: the environmental array
 * Return: the result of the _getline function.
 */

int main(__attribute__ ((unused)) int ac, __attribute__ ((unused)) char *av[],
	 char * const envp[])
{
	return (_getline(envp));
}
