#include <string.h>
#include <stdio.h>

/**
 * tokens - separates a string by words (tokens) and stores
 * each in an array
 * @str: the string in question
 * Return: 0 (success)
 */

char **tokens(char *string);
{
	char *token;

	/* First token, delimiter set */
	token = strtok(string, " ");
	/* Pinting tokens until exhausted */
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}
	return (0);
}
