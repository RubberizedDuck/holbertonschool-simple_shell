#include "main.h"

/**
 * _stat - checks directories for the presence of a string
 * @args: strings typed in by the user
 * @dirs: the relevant directories
 * Return: a pointer to the identified directory, if a match is identified, or
 * argv[0] if no match found
 */

char *_stat(char *args[], char *dirs[])
{
	int i, lcommand, lpath;
	char *newpath;
	struct stat st;

	lcommand = _strlen(args[0]);
	i = 0;
	while (dirs[i] != NULL)
	{
		lpath =  _strlen(dirs[i]);
		newpath = malloc(sizeof(*newpath) * (lcommand + lpath + 2));
		if (newpath == NULL)
		{
			return (NULL);
		}
		_strcpy(newpath, dirs[i]);
		_strcat(newpath, "/");
		_strcat(newpath, args[0]);
		if (stat(newpath, &st) == 0)
		{
			if (access(newpath, F_OK | X_OK) == 0)
			{
				return (newpath);
			}
			else
			{
				free(newpath);
		}
		}
		i = i + 1;
	}
	return (NULL);
}
