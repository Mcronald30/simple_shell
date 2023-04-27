#include "shell.h"
/**
 * _err - inserts a char to a stderr
 * @c: the char
 * Return: Printed int
 */
int _err(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}

/**
 * print_num - Prints a number with the write function
 * @count: the number of times you have done a command
 */

void print_num(int count)
{
	int len = 1, x = 1, count2;

	count2 = count;

	while (count2 >= 10)
	{
		count2 /= 10;
		x *= 10;
		++len;
	}

	while (len >= 1)
	{
		if ((count / x) < 10)
			_err(count / x + '0');
		else
			_err(((count / x) % 10 + '0'));
		--len;
		x /= 10;
	}
}

/**
 * _error - Prints an error message when command not found
 * @argv: Argument vector
 * @first: first command to print if not found
 * @count: the number of times you have done a command
 * @exit_st: exit status
 */

void _error(char **argv, char *first, int count, int **exit_st)
{
	struct stat st;

	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, ":", 2);
	print_num(count);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, first, _strlen(first));
	write(STDERR_FILENO, ": ", 2);
	if (stat(first, &st) == 0 && S_ISDIR(st.st_mode))
	{
		**exit_st = 126;
		if (_strcmp(first, "..") == 0)
			**exit_st = 127;
		perror("");
	}
	else
	{
		**exit_st = 127;
		write(STDERR_FILENO, "not found\n", 10);
	}
}
