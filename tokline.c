#include "shell.h"
/**
 * tok_line - a function that tokenizes a string
 * @line: sting to be tokenized
 * Return: a pointer to token
 *
 */
char **tok_line(char *line)
{
	int bufsize = 1024;
	int i = 0;
	char **fulltok = malloc(bufsize * sizeof(char *));
	char *token;

	if (!fulltok)
	{
		perror("allocation error : tok_line");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, TOK_DELIM);

	while (token != NULL)
	{
		fulltok[i] = token;
		i++;

		if (i >= bufsize)
		{
			bufsize += bufsize;
			fulltok = realloc(fulltok, bufsize * sizeof(char *));
			if (!fulltok)
			{
				perror("allocation error : tok_line");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOK_DELIM);
	}
	fulltok[i] = NULL;
	return (fulltok);
}
