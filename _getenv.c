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
