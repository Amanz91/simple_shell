#include "shell.h"
/**
 * my_exit - a function to exit shell
 * @args: arguments
 * Return: 0
 */
int my_exit(char **args)
{
	if (args)
	{
		return (0);
	}
	return (0);
}
/**
 * execute - a function to check in built and execute
 * @args: arguments
 * Return: -1 or 0
 */
int execute(char **args)
{
	char *builtin_list[] = {
		"exit"};
	int (*builtin_fun[])(char **) = {
		&my_exit};
	unsigned long int i = 0;

	if (args[0] == NULL)
		return (-1);
	for (i = 0; i < sizeof(builtin_list) / sizeof(char *); i++)
	{
		if (_strcmp(args[0], builtin_list[i]) == 0)
		{
			return (builtin_fun[i](args));
		}
	}
	return (launch(args));
}
