#include "shell.h"

/**
 * check_builtin - builtin that pais the command in the arg
 * @cmd: command
 *
 * Return: function pointer of the builtin command
 */
int (*check_builtin(char *cmd))(char *file, char **arg)
{
	builtin built_cmds[] = {
		{"env", _printenv},
		{"exit", exit_shell},
		{"setenv", _setenv},
		{NULL, NULL}
	};
	int i;

	for (i = 0; built_cmds[i].builtin_cmd != NULL; i++)
		if (_strcmp(built_cmds[i].builtin_cmd, cmd) == 0)
			break;

	return (built_cmds[i].func);
}


/**
 * exit_shell - exits the shell
 *
 * @argv: data relevant (status and args)
 * @cmd: command
 * Return: 0 on success.
 */
int exit_shell(char *cmd, char **argv)
{
	unsigned int status, i = 0;

	if (argv[1] == NULL)
		return (-1);
	while (argv[1][i])
	{
		if (_isdigit(argv[1][i] == 0))
		{
			write(STDERR_FILENO, cmd, _strlen(cmd));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": Illegal number: ", 19);
			write(STDERR_FILENO, argv[1], _strlen(argv[1]));
			write(STDERR_FILENO, "\n", 2);
			return (1);
		}
		i++;
	}
	status = _atoi(argv[1]);
	free_str(argv);
	exit(status);
}


/**
 * _printenv - prints the evironment variables
 * argv: array of tokens
 *
 * Return: 1 on success.
 */
int _printenv(__attribute__((unused))char *cmd, char **argv)
{
	int i, j;

	if (!argv[0] || argv[1])
	{
		write(STDERR_FILENO, argv[0], _strlen(argv[0]));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, argv[1], _strlen(argv[1]));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, "no such file or directory\n", 26);
		return (1);
	}
	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '\0'; j++)
			;
		write(STDOUT_FILENO, environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}

	return (1);
}
