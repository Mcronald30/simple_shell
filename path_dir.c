#include "shell.h"
/**
 * add_node_end - adds node to end of list
 * @head: head pointer
 * @dir: string to new node
 * Return: new node, or NULL
 */
void add_node_end(list_t **head, const char *dir)
{
	list_t *last = *head;
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
		*head = new;
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
	list_t *head;

	head = NULL;
	path = _getenv("PATH", env);
	add_node_end(&head, ".");
	dir = strtok(path, ":");
	while (dir != NULL)
	{
		add_node_end(&head, dir);
		dir = strtok(NULL, ":");
	}
	return (head);
}
