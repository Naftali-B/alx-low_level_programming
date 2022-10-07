#include "main.h"
#include <stdlib.h>

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: memory block to reallocate
 * @old_size: size in bytes of current memory block
 * @new_size: size in bytes of new memory block
 *
 * Return: pointer to new memory block, NULL if it fails
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)

{
	char *m, *c_ptr;
	unsigned int limit;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		if (ptr != NULL)
			free(ptr);

		return (NULL);

	}
	if (new_size == old_size)

		return (ptr);

	m = malloc(new_size);
	if (m == NULL)
		return (NULL);

	limit = old_size;
	if (new_size < old_size)
		limit = new_size;

	c_ptr = ptr;
	while (limit--)
		m[limit] = c_ptr[limit];

	free(ptr);
	return (m);

}
