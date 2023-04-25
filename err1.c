#include "shell.h"

char *err_env(char **args);

/**
 * err_env - Creates an error message for shell_env errors.
 * @args: An array of arguments.
 * Return: error.
 */
char *err_env(char **args)
{
	char *err, *his_str;
	int len, temp_his, his_digits = 0;

/*Determine number of digits in hist and store in hist_digits*/

	temp_hist = his;
	while (temp_his != 0)
	{
		his_digits++;
		temp_his /= 10;
	}
	his_str = malloc(sizeof(char) * (his_digits + 1));
	if (!his_str)
		return (NULL);

	_itoa(his, his_str, 10);

	args--;
	len = _strlen(name) + his_digits + _strlen(args[0]) + 45;
	err = malloc(sizeof(char) * (len + 1));
	if (!err)
	{
		free(his_str);
		return (NULL);
	}
	_strcpy(err, name);
	_strcat(err, ": ");
	_strcat(err, his_str);
	_strcat(err, ": ");
	_strcat(err, args[0]);
	_strcat(err, ": Unable to add/remove from environment\n");

	free(hist_str);
	return (err);
}

char *err_1(char **args);
/**
 * err_1 - Creates an error message for shell_env errors.
 * @args: An array of arguments.
 * Return: error.
 */
char *err_1(char **args)
{
	char *err;
	int len, name_len, arg_len;

	name_len = _strlen(name);
	arg_len = _strlen(args[0]);
	len = name_len + arg_len + 13;

	err = malloc(sizeof(char) * (len + 1));
	if (!err)
		return (NULL);

	_strcpy(err, "alias: ");
	_strcpy(err + 7, args[0]);
	_strcpy(err + 7 + arg_len, " not found\n");
	error[len] = '\0';

	return (err);
}

char *err2_exit(char **args);
/**
 * err2_exit - Creates an error message exit_shell.
 * @args: An array of arguments.
 * Return: error
 */
char *err2_exit(char **args)
{
	char *err, *his_str;
	int len, his = 0;

	his_str = _itoa(his);
	if (!his_str)
	{
		return (NULL);
	}
	len = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 27;
	err = malloc(sizeof(char) * (len + 1));
	if (!err)
	{
		free(his_str);
		return (NULL);
	}

	_strcpy(err, name);
	_strcat(err, ": ");
	_strcat(err, his_str);
	_strcat(err, ": exit: Illegal number: ");
	_strcat(err, args[0]);
	_strcat(err, "\n");

	free(his_str);
	return (err);
}

char *err2_cd(char **args);
/**
 * err2_cd - Creates an error message for cd
 * @args: An array of arguments.
 * Return: error
 */
char *err2_cd(char **args)
{
	char *err, *his_str;
	int len, his = 0;

	his_str = _itoa(hist);
	if (!his_str)
	{
		return (NULL);
	}

	if (args[0][0] == '-')
		args[0][2] = '\0';
	len = _strlen(name) + _strlen(his_str) + _strlen(args[0]) + 24;
	err = malloc(sizeof(char) * (len + 1));
	if (!err)
	{
		free(his_str);
		return (NULL);
	}

	_strcpy(err, name);
	_strcat(err, ": ");
	_strcat(err, his_str);
	if (args[0][0] == '-')
		_strcat(err, ": cd: Illegal option ");
	else
		_strcat(err, ": cd: can't cd to ");
	_strcat(err, args[0]);
	_strcat(err, "\n");

	free(hist_str);
	return (err);
}

char *err2_syntax(char **args);
/**
 * err2_syntax - Creates an error message for syntax
 * @args: An array of arguments.
 * Return: The error string.
 */
char *err2_syntax(char **args)
{
	char *err, *his_str;
	int len;

	his_str = _itoa(his);
	if (!his_str)
		return (NULL);

	len = _strlen(name) + _strlen(his_str) + _strlen(args[0]) + 33;
	err = malloc(sizeof(char) * (len + 1));
	if (!err)
	{
		free(his_str);
		return (NULL);
	}

	_strcpy(err, name);
	_strcat(err, ": ");
	_strcat(err, his_str);
	_strcat(err, ": Syntax error: \"");
	_strcat(err, args[0]);
	_strcat(err, "\" unexpected\n");

	free(his_str);
	return (err);
}
