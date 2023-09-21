#include "shell.h"


char *_strchr(const char *str, int ch)
{
	if (str == NULL)
		return (NULL);

	for (; *str != '\0' && *str != ch; ++str)
		;

	return (*str == ch ? (char *)str : NULL);
}


int _strlen(const char *str)
{
	int len = 0;

	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;

	return (len);
}


char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';

	return (dest);
}


int cmp_str(char str[], const char *delim)
{
	int i, j, k;

	for (i = 0, k = 0; str[i] != '\0'; i++)
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (str[i] == delim[i])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);

	return (0);
}

char *_strtok(char str[], const char *delim)
{
	static char *split, *l_addr = NULL;
	char *ptr;
	unsigned int i, flag;

	if (str != NULL)
	{
		if (cmp_str(str, delim))
			return (NULL);
		split = str;
		i = _strlen(str);
		l_addr = &str[i];
	}
	ptr = split;

	if (ptr == l_addr)
		return (NULL);
	
	flag = 0;
	while (*split)
	{
		if (split != ptr)
			if (*split && *(split - 1) == '\0')
				break;

		for (i = 0; delim[i]; i++)
		{
			if (*split == delim[i])
			{
				*split = '\0';
				if (split == ptr)
					ptr++;
				break;
			}
		}
		if (flag == 0 && *split)
			flag = 1;
		split++;
	}
	if (flag == 0)
		return (NULL);

	return (ptr);
}
