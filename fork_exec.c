#include "main.h"

/**
 * fork_exec - forks a child process to execute a command
 * whilst the parent process waits
 * @args: user input
 * @newpath: the newly constructed path to send to execve
 * @envp: the environmental array
 * Return: 0, always
 */
void fork_exec(char *args[], char *newpath, char * const envp[])
{
	pid_t child_pid;

	if (newpath == NULL)
	{
		return;
	}

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(newpath, args, envp) == -1)
		{
			perror("error 1 ");
		}
		free(newpath);
		exit(EXIT_FAILURE);
	}
	else if (child_pid < 0)
	{
		perror("error 2 ");
	}
	else
	{
		wait(&child_pid);
	}
/*	free(newpath);*/
}
