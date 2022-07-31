#include "main.h"

/**
 * fork_exec - forks a child process to execute a command
 * whilst the parent process waits
 * @argv: an array of arguments containing the pathname
 * as well as any command arguments
 */
void fork_exec(char **argv)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror(argv[0]);
		}
		exit(EXIT_FAILURE);
	}
	else if (child_pid < 0)
	{
		perror(argv[0]);
	}
	else
	{
		wait(NULL);
	}
}
