#include "shell.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/**
 * num_pos - Checks if a string is positive
 * @str: string to check
 * Return: 0 on success and -1 if is negative or is not a number
 */
int num_pos(char *str)
{
	int n = 0;

	if (str[0] == '-')
		return (-1);
	for (n = 0; str[n]; n++)
	{
		if (str[n] < 48 || str[n] > 57)
			return (-1);
	}
	return (0);
}

/**
 * shell_exit - Implements builtin exit
 * @buf: Buffer
 * @commands: Arguments
 * @ext_stat: Exit status
 * @count: count of lines
 */
void shell_exit(char *buf, char **commands, int *ext_stat, int count)
{
	int num = 0;

	if (commands[1])
	{
		if (num_pos(commands[1]) == 0)
		{
			num = _atoi(commands[1]);
			*ext_stat = num;
		}
		else
		{
			write(1, "./hsh: ", 7);
			print_num(count);
			write(1, ": ", 2);
			write(1, "exit: Illegal number: ", 22);
			write(1, commands[1], _strlen(commands[1]));
			write(1, "\n", 1);
			*ext_stat = 2;
			free_loop(commands);
			return;
		}
	}
	free_loop(commands);
	free(buf);
	exit(*ext_stat);
}

/**
 * shell_env - Built-in environment
 * @commands: Arguments
 * @env: the environment
 * @ext_stat: Exit status
 */
void shell_env(char **commands, char **env, int *ext_stat)
{
	char **aux = env;

	while (*aux != NULL)
	{
		write(1, *aux, _strlen(*aux));
		write(1, "\n", 1);
		aux++;
	}
	*ext_stat = 0;
	free_loop(commands);
}
