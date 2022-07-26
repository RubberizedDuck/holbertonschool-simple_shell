#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * main - prints the command line arguments passed through
 * the main function
 * Return: Always 0 (success)
 */

int main(int ac, char *av[])
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
