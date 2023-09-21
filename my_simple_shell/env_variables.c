#include "shell.h"



int compare_env(const char *env, const char *name)
{
	int i;

	for (i = 0; env[i] != '='; i++)
	{
		if (env[i] != name[i])
			return (0);
	}
	return (i + 1);
}


char *_getenv(const char *name)
{
	int i, check = 0;
	char *str;

	for (i = 0; environ[i] != NULL; i++)
	{
		check = compare_env(environ[i], name);
		if (check)
		{
			str = environ[i];
			break;
		}
	}
	return (str + check);
}

/**
 * over_write - copies info to create
 * a new env or alias
 * @name: name (env or alias)
 * @val: value (env or alias)
 *
 * Return: new env or alias.
 */
char *over_write(char *name, const char *val)
{
	int nlen = _strlen(name);
	int vlen = _strlen(val), len = nlen + vlen + 2;
	char *var = malloc(sizeof(char) * (len));

	_strcpy(var, name);
	_strcat(var, "=");
	_strcat(var, val);
	_strcat(var, "\0");

	return (var);
}
	
/**
 * set_env - sets an environment variable
 *
 * @name: name of the environment variable
 * @val: value of the environment variable
 *
 * Return: no return
 */
void set_env(char *name, const char *val)
{
	char *nenv, *venv;
	int i;

	for (i = 0; environ[i]; i++)
	{
		venv = _strdup(environ[i]);
		nenv = _strtok(venv, "=");
		if (_strcmp(nenv, name) == 0)
		{
			free(environ[i]);
			environ[i] = over_write(nenv, val);
			free(venv);
			return;
		}
		free(venv);
	}
	environ = double_alloc(environ, i, sizeof(char *) * (i + 2));
	environ[i] = over_write(name, val);
	environ[i + 1] = NULL;
}

/**
 * _setenv - compares env variables names
 * with the name passed.
 * argv: data relevant (env name and env value)
 * cmd: unused
 *
 * Return: 1 on success.
 */
int _setenv(char *cmd, char **argv)
{
	(void)cmd;

	if (argv[1] == NULL || argv[2] == NULL)
		return (1);
	set_env(argv[1], argv[2]);

	return (1);
}
