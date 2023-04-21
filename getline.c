#include "shell.h"
#include <stdlib.h>

/**
 * _realloc - Reallocates a memory block.
 * @ptr: A pointer to the block of memory to be reallocated.
 * @old_size: The size of the block of memory to be reallocated, in bytes.
 * @new_size: The new size the block of memory, in bytes.
 * Return: a pointer to the reallocated block of memory.
 */
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	if (new_size == old_size)
		return (ptr);

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	void *new_ptr = malloc(new_size);

	if (!new_ptr)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr)
	{
		size_t copy_size = old_size < new_size ? old_size : new_size;

		memcpy(new_ptr, ptr, copy_size);
		free(ptr);
	}
	return (new_ptr);
}
