#include "shell.h"
/**
 * launch - a function to execute commands
 * @args: command to execute
 * Return: 1
 */
int launch(char **args)
{
	pid_t pid;
	int status;
	char *cmd = NULL, *tru_cmd = NULL;

	if (args)
	{
		cmd = args[0];
		tru_cmd = find_cmd(cmd);
	}

	pid = fork();

	if (pid ==  0)
	{
		if (execve(tru_cmd, args, environ) == -1)
			perror("./sh");
	}
	else if (pid < 0)
	{
		perror("error in launch : forking");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
