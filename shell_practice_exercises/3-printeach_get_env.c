#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * main - prints each directory contained in PATH
 * Return: 0 upon success
 */

int main ()
{
	char *str, *token;

	str = getenv("PATH");
	token = strtok(str, ":");
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, ":");
	}
	return (0);
}
