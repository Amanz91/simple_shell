#include "shell.h"
/**
 * _strlen - returns the length of a string
 * @c: the string whose length to check
 * Return: length of string
 */
int _strlen(char *c)
{
	int i = 0;

	if (!c)
		return (0);

	while (*c++)
		i++;
	return (i);
}
/**
 * _strcmp - a function to compare of two strings.
 * @s1: the first string
 * @s2: the second string
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}
/**
 * char *_strcpy -  a function that copies the string pointed to src
 * @dest: where to copy to
 * @src: where to copy from
 * Return: string
 */
char *_strcpy(char *dest, char *src)
{
	int a = 0;
	int b = 0;

	while (*(src + a) != '\0')
	{
		a++;
	}
	for (b = 0; b < a; b++)
	{
		dest[b] = src[b];
	}
	dest[a] = '\0';
	return (dest);
}
/**
 * _strcat - a function that concatenates two strings.
 * @dest: destination string
 * @src: source string
 * Return: void
 */
char *_strcat(char *dest, char *src)
{
	int lena, lenb;

	lena = 0;
	while (dest[lena] != '\0')
	{
		lena++;
	}
	lenb = 0;
	while (src[lenb] != '\0')
	{
		dest[lena] = src[lenb];
		lena++;
		lenb++;
	}
	dest[lena] = '\0';
	return (dest);
}
/**
 * _strdup - a function tah duplicates a sting
 * @s: string to be duplicated
 * Return: a pointer to dupicate
 */
char *_strdup(char *s)
{
	char *dup;
	size_t len = 0;


	if (s == NULL)
	{
		return (NULL);
	}
	len = _strlen(s);
	dup = malloc((sizeof(char)) * (len + 1));

	if (dup == NULL)
	{
		return (NULL);
	}
	_strcpy(dup, s);
	return (dup);
}
