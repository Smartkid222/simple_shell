#include "shell.h"

/**
 * main - runs loop and displays shell prompt.
 * argc: argcument count.
 * @argv: arguments passed to kernel
 *
 * Return: integer value
 **/
int main(__attribute__((unused))int argc, char **argv)
{
	char *ptr = {"cisfun$ "}, *lineptr = NULL, *token, *delim = " \n";
	char *line_copy = NULL;
	ssize_t nbytes, exit_status;
	int num = 0, i;
	size_t size = 0;

	do {
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, ptr, 9);
		nbytes = getline(&lineptr, &size, stdin);

		if (nbytes == -1)
		{
			free(lineptr);
			write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}

		line_copy = malloc(sizeof(char) * nbytes);

		if (!line_copy)
			perror("Error");

		_strcpy(line_copy, lineptr);
		token = _strtok(lineptr, delim);

		while (token)
		{
			num++;
			token = _strtok(NULL, delim);
		}
		num++;
		argv = malloc(sizeof(char *) * num);
		token = _strtok(line_copy, delim);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * _strlen(token));
			_strcpy(argv[i], token);
			token = _strtok(NULL, delim);
		}
		argv[i] = NULL;
		exit_status = exec(argv);

	} while (exit_status != -1);

	free(line_copy);
	free(lineptr);

	exit(EXIT_SUCCESS);
}
