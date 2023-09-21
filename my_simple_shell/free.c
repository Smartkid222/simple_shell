#include "shell.h"

/**
 * free_str - free malloc memory allocated
 * @str: argument stored on the heep by malloc
 *
 * Return: return void
 */
void free_str(char **str)
{
	int i, count;

	while (str[count])
		count++;

	for (i = 0; i < count; i++)
		free(str[i]);
	free(str);
}
