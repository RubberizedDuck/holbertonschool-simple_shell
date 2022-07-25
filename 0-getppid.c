#include <stdio.h>
#include <unistd.h>

/**
 * main - returns the parent process ID
 * Return: will always be successful, returns 0
 */

int main(void)
{
	int p_id;

	p_id = getppid(); /*parent process id*/

	printf("%u\n", p_id);

	return (0);
}
