#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* _toa -  pointer to the resulting string */
char *_itoa(int n)
{
	char *str = malloc(sizeof(char) * 12);

	sprintf(str, "%d", n);
	return (str);
}

/* _strlen - character of a string length */
int _strlen(char *str)
{
	return (strlen(str));
}

/* _strcat - character string */
char *_strcat(char *dest, char *src)
{
	return strcat(dest, src);
}

/**
 * err_126 - Prints error for permission denied failures.
 * @args: An array of arguments.
 * Return: error.
 */
char *err_126()
{
	char *his_str;
	int his = 126;

	his_str = _itoa(his);

	char *name = "err";
	int len = _strlen(name) + _strlen(his_str) + _strlen("args[0]") + 24;
	char *err = malloc(sizeof(char) *len);

	sprintf(err, "%s-%s: %s: command not found\n", name, his_str, "args[0]");
	_strcat(err, "Try again with another command.\n");
	return (err);
}

/**
 * err_127 - Print error for command not found failures.
 * @args: An array of arguments.
 * Return: error.
 */
char *err_127(char **args)
{
	char *his_str;
	int his = 127;

	his_str = _itoa(his);
	char *name = "err";
	int len = _strlen(name) + _strlen(his_str) + _strlen(args[0]) + 16;
	char *err = malloc(sizeof(char) *len);

	sprintf(err, "%s-%s: %s: not found\n", name, his_str, args[0]);
	return (err);
}
