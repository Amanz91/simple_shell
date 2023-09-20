#include "shell.h"
/**
 * main - entry point of simple shell
 * @ac: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int ac, char **argv)
{
	char *line;
	char **args;
	int status = -1;

	if (ac > 1)
	{
		argv[1] = NULL;
	}
	do {
		if (isatty(STDIN_FILENO) == 1)
		{
		_puts("($) ");
		line = read_line();
		args = tok_line(line);
		status = execute(args);
		free(line);
		free(args);
		if (status == 0)
			exit(status);
		}
		else
		{line = read_line();
                args = tok_line(line);
                status = execute(args);
                free(line);
                free(args);
		if (status >= 0)
			exit(status);		
		}
	} while (status == -1);

	return (0);
}
