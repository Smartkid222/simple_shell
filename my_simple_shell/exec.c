#include "shell.h"


/**
 * _which - locates a command
 *
 * @cmd: command name
 * Return: location of the command.
 */
char *_which(char *cmd)
{
	char *file_path, *path_tok, *delim = ":";
	int cmd_len, dir_len;
	char *path, *path_cpy;
	struct stat buf;

	if (cmd)
	{
		path = _getenv("PATH");
		if (path)
		{
			path_cpy = _strdup(path);
			cmd_len = _strlen(cmd);
			path_tok = _strtok(path_cpy, delim);
			while (path_tok)
			{
				dir_len = _strlen(path_tok);
				file_path = malloc(cmd_len + dir_len + 2);
				_strcpy(file_path, path_tok);
				_strcat(file_path, "/");
				_strcat(file_path, cmd);
				_strcat(file_path, "\0");

				if (stat(file_path, &buf) == 0)
				{
					free(path_cpy);
					return (file_path);
				}
				else
				{
					free(file_path);
					path_tok = _strtok(NULL, delim);
				}
			}
			free(path_cpy);

			if (stat(cmd, &buf) == 0)
				return (cmd);
			return (NULL);
		}

		if (cmd[0] == '/')
			if (stat(cmd, &buf) == 0)
				return (cmd);
	}
	return (NULL);
}


/**
 * exec - execute the command given to the shell
 * @token: tokens
 *
 * Return: return 0 on success and -1 otherwise
 */
int exec(char **token)
{
	char *cmd, *ac_cmd;
	int var, (*builtin)(char *cmd, char **arg);
	pid_t c_pid;

	cmd = token[0];
	builtin = check_builtin(cmd);
	if (builtin)
		return (builtin(*token, token));
	ac_cmd = _which(cmd);

	if (!ac_cmd)
		return (1);

	c_pid = fork();

	if (c_pid == -1)
	{
		perror("Error");
		return (1);
	}
	if (c_pid == 0)
	{
		var = execve(ac_cmd, token, environ);
		if (var == -1)
			perror("Error");
	}
	else
		wait(NULL);

	return (0);
}
