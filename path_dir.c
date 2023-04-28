#include "shell.h"

/**
 * add_node_end - adds node to end of list
 * @h: head pointer
 * @dir: string to new node
 * Return: new node, or NULL
 */
void add_node_end(list_t **h, const char *dir)
{
	list_t *last = *h;
	list_t *new = malloc(sizeof(list_t));

	new->next = NULL;
	new->dir = _strdup((char *)dir);
	if (last)
	{
		while (last->next)
		last = last->next;
		last->next = new;
	}
	else
		*h = new;
}
/**
 *list_path - Linked list to PATH directories
 *@env: Env variables
 *Return: head of the linked list
 */
list_t *list_path(char **env)
{
	char *dir;
	char *path;
	list_t *h;

	h = NULL;
	path = _getenv("PATH", env);
	add_node_end(&h, ".");
	dir = strtok(path, ":");
	while (dir != NULL)
	{
		add_node_end(&h, dir);
		dir = strtok(NULL, ":");
	}
	return (h);
}
