#include "main.h"

/**
 * _strncmp - compares two strings
 * @s1: string one
 * @s2: string two
 * @n: specified number of bytes
 * Return: 0 if the strings match for the specified number of bytes
 * -1, otherwise
 */

int _strncmp(const char *s1, const char *s2, int n)
{
	int i;

	if (n == 0)
	{
		return (-1);
	}

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (i == n)
		{
			return (0);
		}

		if (s1[i] != s2[i])
		{
			return (-1);
		}
		i = i + 1;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
	{
		return (0);
	}
	return (-1);
}

/**
 * _strlen - is a function that returns the length of a string.
 * @s: is the character being passed.
 * Return: len is the string length.
 */

int _strlen(const char *s)
{
	int len;

	len = 0;
	while (s != NULL && s[len] != '\0')
	{
		len = len + 1;
	}
	return (len);
}

/**
 * _strdup - duplicates an array and stores it in a memory allocation
 * @str: pointer to the string array
 * Return: The duplicated array stored in new pointer
 */

char *_strdup(char *str)
{
	char *dupe;
	int strLen, array;

	if (str == NULL)
	{
		return (NULL);
	}
	strLen = _strlen(str);
	dupe = malloc(strLen * sizeof(*dupe) + 1);

	if (dupe == NULL)
	{
		return (NULL);
	}
	array = 0;
	while (str[array] != '\0')
	{
		dupe[array] = str[array];
		array = array + 1;
	}
	dupe[array] = '\0';
	return (dupe);
}

/**
 * *_strcat - concatenates two strings
 * @src: string to appended
 * @dest: string to append to
 * Return: pointer to dest
 */

char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	while (dest[i] != '\0')
	{
		i = i + 1;
	}

	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j = j + 1;
		i = i + 1;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * *_strcpy - copies a string to a buffer
 * @dest: points to buffer location
 * @src: points to string location
 * Return: pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int i, length;

	length = 0;
	while (src[length] != '\0')
	{
		length = length + 1;
	}

	i = 0;
	while (i <= length)
	{
		dest[i] = src[i];
		i = i + 1;
	}
	return (dest);
}
