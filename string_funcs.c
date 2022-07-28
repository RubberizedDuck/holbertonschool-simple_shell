#include "main.h"

/**
 * _strlen - is a function that returns the length of a string.
 * @s: is the character being passed.
 * Return: len is the string length.
 */

int _strlen(char *s)
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
	dupe = malloc(strLen * sizeof(char) + 1);

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
 * _strcmp - Function to print the difference between strings
 * @s1: First string
 * @s2: Second string
 * Return: ret, which equals the difference of s1 & s2.
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int ret = 0;

	/* loops if string 1 is equal to string 2 */
	while (s1[i] == s2[i])
	{
		/* if string 1 equals to NULL, loop breaks */
		if (s1[i] == '\0')
		{
			break;
		}
		/* if string 2 equals to NULL, loop breaks */
		if (s2[i] == '\0')
		{
			break;
		}
		/* else increment i */
		else
		i = i + 1;
	}
	/* prints the difference of string 1 and string 2 */
	ret = s1[i] - s2[i];
	return (ret);
}
