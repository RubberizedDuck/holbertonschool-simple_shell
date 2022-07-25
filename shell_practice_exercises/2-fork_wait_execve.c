#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t father_pid, child_pid;
	int status, count = 0;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	printf("Before Fork\n");
	child_pid = fork();
	while (count != 5)
	{
	if (child_pid == 0)
		/* trying to loop over child processes 5 times */
		/* but can't seem to figure it out */
		/* perhaps you might be able to figure out my madness */
		/* you can compile and execute to see what happens */
	{
		sleep(3);
		printf("Before execve\n");
		father_pid = getpid();
		printf("Father pid is %u\n", father_pid);
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error:");
		}
		printf("After execve\n");
		father_pid = getpid();
		printf("Father pid is %u\n after exec\n", father_pid);
	}
	else if (child_pid != -1)
	{
		printf("After fork\n");
		wait(&status);
		father_pid = getpid();
		printf("Father pid is %u\n", father_pid);
	}
	else
	{
		perror("Error:");
		return (1);
	}
	count++;
	}
	return (0);
}
