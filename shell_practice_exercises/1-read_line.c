#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * main - prints the command line arguments passed through
 * the main function
 * Return: Always 0 (success)
 */

int main(__attribute__ ((unused)) int ac, char *av[])
{
	int i;

	i = 0;
	while (av[i] != NULL)
	{
		printf("$ ");
		if (scanf("%s", av[i]) != EOF)
		{
			printf("%s\n", av[i]);
		}
		else
		{
			exit(0);
		}
	}
	return (0);
}
