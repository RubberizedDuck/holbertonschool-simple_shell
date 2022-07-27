#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork & wait example
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t child_pid, father_pid;
	int status, i;
	char *av[] = {"/bin/ls", "-l", "/tmp", NULL};

	father_pid = getpid();
	printf("Before we begin, your father's pid is: %u\n", father_pid);
	i = 0;
	while (i < 5)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			printf("Wait for me, wait for me! I've lost my pid!\n");
			if (execve(av[0], av, NULL) == -1)
			{
				perror("Error:");
			}
			sleep(3);
		}
		else
		{
			wait(&status);
			printf("Oh, it's all better now! I've found it: %u\n", child_pid);
		}
		i = i + 1;
	}
	printf("Don't forget, your father's pid is: %u\n", father_pid);
	return (0);
}
