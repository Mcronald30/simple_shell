#include "shell.h"

/**
 * my_builtin - function used in a program that implements a shell
 * @args: An array of arguments.
 * @prow: a character string.
 * Return: a pointer to a function.
 */
int my_builtin(char **args, char **prow)
{
	builtin_t funcs[] = {
	{ "exit", exit_shell },
	{ "cd", shell_cd },
	{ "help", shell_help },
	{ NULL, NULL }
	};

	for (int i = 0; funcs[i].name != NULL; i++)
	{
	if (_strcmp(funcs[i].name) == 0)
	return (funcs[i].f);
	}
	return (NULL);
}

/**
 * exit_shell - built-in command in a shell
 * program that is used to exit the shell.
 * @args: An array of arguments.
 * @prow: a character string.
 * Return: exits with an integer value.
 */
int exit_shell(char **args, char **prow)
{
	if (!args[0])
	return (-3);

	char *endptr;
	int status = (int)strtol(args[0], &endptr, 10);

	if (*endptr != '\0' || endptr == args[0])
	return (2);

	free_args(args, prow);
	free_env();
	free_alias_list(aliases);
	exit(status);
}

/**
 * shell_cd - Changes the current directory.
 * @args: An array of arguments.
 * @prow: a character string.
 * Return: 0 success
 */
int shell_cd(char **args, char **prow)
{
	char *dir;

	if (args[1] != NULL)
		return (create_error(args, 2));

	if (args[0] == NULL || _strcmp(args[0], "~") == 0)
		dir = _getenv("HOME");

	else if (_strcmp(args[0], "-") == 0)
	{
		dir = _getenv("OLDPWD");
		if (dir == NULL)
			return (create_error(args, 2));
	}
	else
		dir = args[0];

	int ret = chdir(dir);

	if (ret == -1)
		return (create_error(args, 2));

	char cwd[PATH_MAX];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
		return (create_error(args, -1));

	char *pwd[3] = { "OLDPWD", _getenv("PWD"), NULL };

	_setenv(pwd, prow);
	pwd[0] = "PWD";
	pwd[1] = cwd;
	_setenv(pwd, prow);

	return (0);
}

/**
 * shell_help - Changes the cd of the shell process.
 * @args: An array of arguments.
 * @prow: a character string.
 * Return: 0 success if no error
 */
int shell_help(char **args, char **prow)
{
	char *builtin_cmds[] = {"alias", "cd", "exit", "env",
	"setenv", "unsetenv", "help", NULL};

	void (*builtin_help_funcs[])(void) = {help_alias, help_cd, help_exit,
	help_env, help_setenv, help_unsetenv, help_help};

	if (!args[0])
	{
		help_all();
		return (0);
	}
	for (int i = 0; builtin_cmds[i]; i++)
	{
		if (_strcmp(args[0], builtin_cmds[i]) == 0)
		{
			builtin_help_funcs[i]();
			return (0);
		}
	}
	write(STDERR_FILENO, name, _strlen(name));
	return (0);
}
