#include "main.h"

/**
*_getenv - get the env members
*@name: the member name
*Return: pointer to member if found
*
char *_getenv(char * const envp[], const char *name)
{
	int i = 0, j = 0, flag;
	char *current_env = NULL;

	while (envp[i] != NULL)
	{
		flag = 0;
		current_env = envp[i];

		printf("%s\n", envp[i]);
		while (current_env[j] != '=')
		{
			if (name[j] != current_env[j])
				flag = 1;
			j++;
		}
		if (flag == 0)
			return (envp[i]);
		i++;
	}
	return (NULL);
}
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
