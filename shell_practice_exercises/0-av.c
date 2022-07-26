#include <stdio.h>
#include <unistd.h>

/**
 * main - prints the command line arguments passed through
 * the main function
 * Return: Always 0 (success)
 */

int main(int ac, char *av[])
{
	int i;

	i = 0;
	while (av[i] != NULL)
	{
		printf("%s\n", av[i]);
		i = i + 1;
	}
	return (0);
}
