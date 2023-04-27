#include "shell.h"
/**
*_which - Searches for files in the current path
*@commands: Aarguments
*@env: Env variables
*Return: PATH, or NULL
*/
char *_which(char **commands, char **env)
{
	list_t *head;
	list_t *aux;
	char *part_one = NULL;
	char *init_path = NULL;
	char *final_path = NULL;
	struct stat st;

	head = list_path(env);
	aux = head;
	while (aux)
	{
		part_one = _strcat(aux->dir, "/");
		init_path = _strcat(part_one, commands[0]);
		free(part_one);
		if (stat(init_path, &st) == 0)
		{
			final_path = init_path;
			break;
		}
		free(init_path);
		aux = aux->next;
	}
	free_list(head);
	return (final_path);
}
