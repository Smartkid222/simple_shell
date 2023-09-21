#include "shell.h"

/**
 * double_alloc - reallocates a memory block of a double pointer.
 * @dp: double pointer to the memory previously allocated.
 * @pre_size: size, in bytes, of the allocated space of ptr.
 * @size: new size, in bytes, of the new memory block.
 *
 * Return: ptr.
 * if size == pre_size, returns ptr without changes.
 * if malloc fails, returns NULL.
 */
char **double_alloc(char **dp, int pre_size, int size)
{
	char **ptr;
	int i;

	if (!dp)
		return (malloc(sizeof(char *) * size));

	if (size == pre_size)
		return (dp);

	ptr = malloc(sizeof(char *) * size);
	if (!ptr)
		return (NULL);

	for (i = 0; i < pre_size; i++)
		ptr[i] = dp[i];

	free(dp);

	return (ptr);
}
