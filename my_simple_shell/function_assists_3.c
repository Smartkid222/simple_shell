#include "shell.h"

/**
 * _strcat - concatenate two string
 * @s1: destination
 * @s2: passed string
 *
 * Return: return pointer of dest string
 */
char *_strcat(char *s1, const char *s2)
{
	int i = 0, len = _strlen(s1);

	while (s2[i] != '\0')
		s1[len++] = s2[i++];
	s1[len] = '\0';

	return (s1);
}
