#include <stdio.h>
#include <unistd.h>

/**
 * main - returns the current and parent process ID
 * Return: will always be successful, returns 0
 */

int main(void)
{
	pid_t my_pid, parent_pid;
	unsigned int test;

	parent_pid = getppid(); /* parent process id */
	my_pid = getpid(); /* current process id */
	test = getpid(); /* testing if id can be stored in integer */

	printf("Current pid: %u\n", my_pid);
	printf("Testing pid: %u\n", test);
	printf("Parent pid: %u\n", parent_pid);

	return (0);
}
