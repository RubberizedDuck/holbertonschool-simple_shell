#include "main.h"

/**
 * print_env - prints the environment variables
 * Return: 0 as always success
 */

int print_env(void)
{
	int count = 0;

	while (environ[count] != NULL)
	{
		write(STDOUT_FILENO, environ[count], _strlen(environ[count]));
		write(STDOUT_FILENO, "\n", 1);
		count++;
	}
	return (0);
}
