#include "shell.h"
/**
 * read_line - a function to read input
 * Return: Pointer to red line
 */
char *read_line(void)
{
	char *l_ptr = NULL;
	size_t b_size = 0;
	ssize_t num_ch;

	num_ch = getline(&l_ptr, &b_size, stdin);

	if (num_ch == -1)
	{
		if (feof(stdin))
		{
			free(l_ptr);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(l_ptr);
			exit(EXIT_FAILURE);
		}
	}
	return (l_ptr);
}
