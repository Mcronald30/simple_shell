#include "shell.h"
/**
*free_loop - free double pointer array of pointers
*@arr: double pointer array of pointers
*/
void free_loop(char **arr)
{
	int len;

	for (len = 0; arr[len]; len++)
		free(arr[len]);
	free(arr);
}

/**
 *free_list - frees a listint_t list
 *@h: head of a listint_t list
 */
void free_list(list_t *h)
{
	list_t *prev;

	while (h)
	{
		free(h->dir);
		prev = h;
		h = h->next;
		free(prev);
	}
}
