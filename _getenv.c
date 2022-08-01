#include "main.h"

/**
*_getenv - get the env members
*@name: the member name
*Return: pointer to member if found
*/
char *_getenv(const char *name)
{
	int i = 0, j = 0, flag;
	char *current_env = NULL;

	while (environ[i] != NULL)
	{
		flag = 0;
		current_env = environ[i];
		while (current_env[j] != '=')
		{
			if (name[j] != current_env[j])
				flag = 1;
			j++;
		}
		if (flag == 0)
			return (environ[i]);
		i++;
	}
	return (NULL);
}
