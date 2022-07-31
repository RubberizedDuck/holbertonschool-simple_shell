#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
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

	toks = malloc(sizeof(*toks) * 64);
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
	toks[count] = NULL;
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
	int g;

	line = NULL;
	len = 32;

	/* allows to loop forever */
	while (1)
	{
		printf("$ ");
		g = getline(&line, &len, stdin);
		if (g == -1)
		{
			printf("getline error");
		}
		if (g == EOF)
		{
			printf("\n");
			exit(0);
		}
		line[_strlen(line) - 1] = '\0';
		args = tokens(line);
		fork_exec(args);
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
