#include "shell.h"

/**
 * _getenv - Environment variable
 * @name: Name of env variable
 * @env: Environment
 * Return: Variable value
 */
char *_getenv(const char *name, char **env)
{
	int d;
	char *comp = NULL;

	if (env == NULL)
		return (NULL);

	for (d = 0; env[d]; d++)
	{
		comp = strtok(env[d], "=");
		if (strcmp(comp, name) == 0)
		{
			return (strtok(NULL, "\n"));
		}
	}
	return (NULL);
}

/**
 * _unsetenv - function that Remove  environment variables
 * @name: Structure that has  arguments.
 * maintain constant function prototype.
 * @value: the string env var property
 * Return: 1 for delete, 0 otherwise
 */
int _unsetenv(const char *name, char *value)
{
	list_t *node = name->env;
	size_t j = 0;
	char *q;

	if (!node || !value)
		return (0);

	while (node)
	{
		q = starts_with(node->str, value);
		if (q && *q == '=')
		{
			name->env_changed = delete_node_at_index(&(name->env), j);
			j = 0;
			node = name->env;
			continue;
		}
		node = node->next;
		j++;
	}
	return (name->env_changed);
}

/**
 * _setenv - function tht Initialize  new environ var,
 * @name: Structure that has arguments.
 * @line: String environent variable property
 * @value: String environment variable value
 * Return: Always 0
 */
int _setenv(info_t *name, char *line, char *value)
{
	char *buff = NULL;
	list_t *node;
	char *q;

	if (!line || !value)
		return (0);

	buff = malloc(_strlen(line) + _strlen(value) + 2);
	if (!buff)
		return (1);
	_strcpy(buff, var);
	_strcat(buff, "=");
	_strcat(buff, value);
	node = name->env;
	while (node)
	{
		q = starts_with(node->str, line);
		if (q && *q == '=')
		{
			free(node->str);
			node->str = buff;
			name->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buff, 0);
	free(buff);
	name->env_changed = 1;
	return (0);
}
