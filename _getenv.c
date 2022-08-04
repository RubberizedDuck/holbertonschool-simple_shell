#include "main.h"

/**
 * _getenv - isolate a particular section of the environment
 * @envp: the environmental array
 * @name: a string to compare with envp
 * Return: pointer to the relevant section if found
 * NULL otherwise
 *
 */

char *_getenv(char * const envp[], const char *name)
{
	int i, len;

	len = _strlen(name);
	i = 0;
	while (envp[i] != NULL)
	{
		if (_strncmp(envp[i], name, len) == 0)
		{
			return (envp[i]);
		}
		i = i + 1;
	}
	return (NULL);
}
