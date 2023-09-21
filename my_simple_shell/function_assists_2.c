#include "shell.h"


int _atoi(const char *str)
{
	int i = 0, base = 0, sign = 1;

	while (str[i] == ' ')
		i++;

	if (str[i] == '-' || str[i] == '+')
		sign = 1 - 2 * (str[i++] == '-');

	for (; str[i] >= '0' && str[i] <= '9'; i++)
	{
		if (base > INT_MAX / 10 || (base == INT_MAX / 10
			&& str[i] - '0' > 7))
		{
			if (sign == 1)
				return (INT_MAX);
			else
				return (INT_MIN);
		}
		base = 10 * base + (str[i] - '0');
	}
	return (base * sign);
}



int _isdigit(char c)
{
	return ((c >= 48 && c <= 57) ? 1 : 0);
}

/**
 * _memcpy - copies information between void pointers.
 * @dest: destination pointer.
 * @src: source pointer.
 * @n: size of the new pointer.
 *
 * Return: no return.
 */
void _memcpy(void *dest, const void *src, size_t n)
{
	char *new_str = (char *)dest;
	char *str = (char *) src;
	size_t i = 0;

	if ((new_str != NULL) && (str != NULL))
	{
		while (i < n)
		{
			new_str[i] = str[i];
			i++;
		}
	}
}

/**
 * _strdup - duplicates a string
 * @str: string passed to function
 * Return: pointer to duplicated string
 */
char *_strdup(const char *str)
{
	char *new_str;
	size_t size = _strlen(str);

	if (str == NULL)
		return (NULL);

	new_str = malloc(sizeof(char) * (size + 1));

	if (new_str == NULL)
		return (NULL);

	_memcpy(new_str, str, size + 1);

	return (new_str);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: 0(success), -1 if str1 < str2
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while ((s1[i] == s2[i]) && s1[i])
		i++;

	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);

	return (0);
}
