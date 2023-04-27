#include "shell.h"
#include <unistd.h>
#include <stdbool.h>

/**
 * interactive - returns true if shell is interactive mode.
 * @info: as an argument.
 * Return: 1 if interactive mode, 0 otherwise.
 */
bool interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is delimeter
 * @c: is a delimiter character
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, const char *delim)
{
	for (int i = 0; delim[i] != '\0'; i++)
	{
		if (c == delim[i])
		{
			return (1);
		}
	}
	return (0);
}

/**
 * _isalpha - checks for alphabetic character
 * @c: character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */
int _isalpha(int c)
{
	return (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) ? 1 : 0);
}

/**
 * _atoi - a function that convert a string to an integer.
 * @s: string to be converted
 * Return: the int converted from the string
 */
int _atoi(char *s)
{
	int i, d, n, len, f, digit;

	i = 0;

	d = 0;
	n = 0;
	len = 0;
	f = 0;
	digit = 0;

	while (s[len] != '\0')
		len++;

	while (i < len && f == 0)
	{
		if (s[i] == '-')
			++d;

		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			if (d % 2)
				digit = -digit;
			n = n * 10 + digit;
			f = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			f = 0;
		}
		i++;
	}
	if (f == 0)
		return (0);

	return (n);
}
