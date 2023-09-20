#include "shell.h"
/**
 * find_path - a function to find path of an executable
 * @path: path of command
 * @cmd: command
 * Return: a pointer or null
 */
char *find_path(char *path, char *cmd)
{
	char *path_cpy, *path_tok, *f_path;
	int cmd_len, dir_len;
	struct stat buf;

	path_cpy = _strdup(path);
	cmd_len = _strlen(cmd);
	path_tok = strtok(path_cpy, ":");

	while (path_tok != NULL)
	{
		dir_len = _strlen(path_tok);
		f_path = malloc(cmd_len + dir_len + 2);
		_strcpy(f_path, path_tok);
		_strcat(f_path, "/");
		_strcat(f_path, cmd);
		_strcat(f_path, "\0");

		if (stat(f_path, &buf) == 0)
		{
			free(path_cpy);
			return (f_path);
		}
		else
		{
			free(f_path);
			path_tok = strtok(NULL, ":");
		}
	}
	free(path_cpy);
	return (NULL);
}
/**
 * find_cmd - a function to find command
 * @cmd: command to be found
 * Return: pointer or null
 */
char *find_cmd(char *cmd)
{
	char *path, *result;
	struct stat buf;

	path = getenv("PATH");

	if (path)
	{
		result = find_path(path, cmd);

		if (result != NULL)
		{
			return (result);
		}
		else
		{
			if (stat(cmd, &buf) == 0)
			{
				return (cmd);
			}
		}
		return (NULL);
	}
	return (NULL);
}
