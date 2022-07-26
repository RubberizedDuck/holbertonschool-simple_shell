#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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
 * main - prints the command line arguments passed through
 * the main function
 * Return: Always 0 (success)
 */

int main(void)
{
	/* define buffer and buffer size */
	char *line;
	size_t len;

	line = NULL;
	len = 32;

	/* 1 allows to loop forever */
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
		printf("%s", line);
	}
	free(line);
	return (0);
}
