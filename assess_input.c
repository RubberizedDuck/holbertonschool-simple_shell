#include "main.h"

/**
 * assess_input - determines what to do with user input
 * @args: user input to consider
 * @envp: the environmental array
 * @dirs: a tokenised list of PATH directories
 * Return: always 0
 */
int assess_input(char *args[], char * const envp[], char **dirs)
{
	char *newpath;

	if (*args[0] == '/' || *args[0] == '.')
	{
		newpath = _strdup(args[0]);
		if (access(args[0], F_OK | X_OK) == 1)
		{
			perror("error 3 ");
			return (0);
		}
	}
	else
	{
		newpath = _stat(args, dirs);
	}
	if (newpath == NULL)
		return (-1);
	fork_exec(args, newpath, envp);
	free(newpath);
	return (0);
}
