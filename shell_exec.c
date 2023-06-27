#include "shell.h"
/**
 * execute_command - function to execute a command entered
 * @command_path: path to command entered
 * @args: array of arguments
 * Return: Void
 */

void execute_command(const char *command_path, char *const args[])
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (execve(command_path, args, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);

		}
	}
	else
	{
		wait(&status);
	}
}

