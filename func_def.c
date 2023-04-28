#include "shell.h"

/**
 * _strcat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * Return: pointer to new string
 */
char *_strcat(char *s1, char *s2)
{
	char *c;
	int x, y, z;

	for (x = 0; s1 && s1[x]; ++x)
		;
	for (y = 0; s2 && s2[y]; ++y)
		;
	c = (char *)malloc((x + y + 1) * sizeof(char));
	if (c == NULL)
		return (NULL);
	z = 0;
	for (x = 0; s1 && s1[x]; ++x)
	{
		c[z] = s1[x];
		++z;
	}
	for (y = 0; s2 && s2[y]; ++y)
	{
		c[z] = s2[y];
		++z;
	}
	c[z] = '\0';
	return (c);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: string
 * Return: pointer to new string, or NULL
*/

char *_strdup(char *str)
{
	int n, d;
	char *new;

	if (str == NULL)
		return (NULL);
	for (n = 0; str[n]; n++)
		;
	new = (char *)malloc((n + 1) * sizeof(char));
	if (new == NULL)
		return (new);
	for (d = 0; d <= n; ++d)
		new[d] = str[d];
	return (new);
}
/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: difference
*/
int _strcmp(char *s1, char *s2)
{
	while (1)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
}

/**
*_strncpy - concatenates two strings
* @dest: string pointer
* @src: string pointer
* @n: bytes
* Return: pointer to the resulting string dest
*/
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; (i < n) && (*(src + i) != '\0'); i++)
		*(dest + i) = *(src + i);
	for (; i < n; i++)
		*(dest + i) = '\0';
	return (dest);
}

/**
* _strlen - return length of a string
* @s: char type
* Return: length of string
*/

int _strlen(char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
