#include "shell.h"
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * _execute - function that executes in the main shell
 * @argv: argument char-pointers array
 * @cmds: split arguments
 * @c: c of commands that were run
 * @env: the environment
 * @exit_st: exit status
 * @line: buffer of getline
 */
void execute_line(char **argv, char **cmds, int c,
		char **env, int *exit_st, char *line)
{
	pid_t pid;
	int status;
	char *full_path = NULL;
	(void)line;
	pid = fork();
	if (pid < 0)
		perror("Error:");
	if (pid == 0)
	{
		full_path = cmds[0];
		if (**cmds != '/' && _strcmp(cmds[0], "..") != 0)
			full_path = _which(cmds, env);
		if (full_path)
		{
			if (access(full_path, X_OK) == 0)
				execve(full_path, cmds, env);
		}
		_error(argv, cmds[0], c, &exit_st);
		free_loop(cmds);
		free(line);
		exit(*exit_st);
	}
	else
	{
		wait(&status);
		free_loop(cmds);
		*exit_st = WEXITSTATUS(status);
	}
}
