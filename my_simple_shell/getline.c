#include "shell.h"


ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static char line[BUFSIZE];
	char *buf;
	size_t len;

	if (lineptr == NULL || n == NULL)
		return (-1);
	if (ferror(stream))
		return (-1);
	if (feof(stream))
		return (-1);

	buf = fgets(line, BUFSIZE, stream);

	buf = _strchr(line, '\n');
	if (buf)
		*buf = '\0';

	len = _strlen(line);

	if ((len + 1) < BUFSIZE)
	{
		buf = realloc(*lineptr, BUFSIZE);
		if (buf == NULL)
			return (-1);
		*lineptr = buf;
		*n = BUFSIZE;
	}
	_strcpy(*lineptr, line);

	return (len);
}
