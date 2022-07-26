#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * _strlen - returns the length of a string
 * @s: the string in question
 * Return: always 0 (success)
 */

int _strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i = i + 1;
	}
	return (i);
}

/**
 * tokens - separates a string by words (tokens) and stores
 * each in an array
 * @string: the string in question
 * Return: 0 (success)
 */

int tokens(char *string)
{
	char *token;

	/* First token, delimiter set */
	token = strtok(string, " ");
	/* Printing tokens until exhausted */
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}
	return (0);
}

/**
 * _getline - prints the command line arguments passed through
 * the main function
 * Return: Always 0 (success)
 */

int _getline()
{
	/* define buffer and buffer size */
	char *line;
	size_t len;

	line = NULL;
	len = 32;

	/* allows to loop forever */
	while (1)
	{
		printf("$ ");
		if (getline(&line, &len, stdin) == -1)
		{
			printf("getline error");
		}
		if (feof(stdin))
		{
			printf("\n");
			exit(0);
		}
		line[_strlen(line) - 1] = '\0';
		tokens(line);
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
