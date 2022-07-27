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
	if (child_pid == -1)
	{
		printf("error\n");
		return (1);
	}
	if (child_pid == 0)
		execve(argv[0], argv, NULL);

	wait(NULL);
	}
}
