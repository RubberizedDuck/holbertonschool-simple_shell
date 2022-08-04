#include "main.h"

/**
 * assess_input - determines what to do with user input
 * @args: user input to consider
 * @envp: the environment in which to search, if required
  * Return: always 0
 */
int assess_input(char *args[], char * const envp[])
{
	char **dirs;
	char *newpath;

	if (*args[0] == '/')
	{
		newpath = args[0];
		if (access(args[0], F_OK | X_OK) == 1)
		{
			perror("error 3 ");
			return (0);
		}
	}
	else
	{
		dirs = _getpath(envp);
		newpath = _stat(args, dirs);
	}
	fork_exec(args, newpath);
	return (0);
}
