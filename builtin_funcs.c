#include "main.h"

int exec_env(void)
{
	return (1);
}

int exec_exit(void)
{
	return (-1);
}

int _builtin(char *argv[])
{
	builtin_t builtins[] = {
		{"exit", exec_exit},
		{"env", exec_env},
		{NULL, NULL}
	};
	int count = 0;

	while (builtins[count].name != NULL)
	{
		if (_strcmp(argv[0], builtins[count].name) == 0)
		{
			return (builtins[count].f());
		}
		count++;
	}

	return (0);
}
