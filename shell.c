#include "shell.h"
/**
 * exit_command - function to handle exit command
 * Return: Void
 */

void exit_command(void)
{
	exit(EXIT_SUCCESS);
}

/**
 * env_command - function to handle environment variables
 * Return: Void
 */

void env_command(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		write(STDOUT_FILENO, *env, strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}

/**
 * hand_command - function to handle commands entered
 * @command: command entered
 * Return: Void
 */

void hand_command(char *command)
{
	char *args[MAX_COMMAND_LEN], *token, *command_path;
	char error_msg[MAX_COMMAND_LEN + 18] = "Command '";
	int num_args = 0;
	char command_copy[MAX_COMMAND_LEN];

	my_strcpy(command_copy, command);

	token = strtok(command_copy, " ");

	while (token != NULL && num_args < MAX_COMMAND_LEN - 1)
	{
		args[num_args++] = token;
		token = strtok(NULL, " ");
	}

	args[num_args] = NULL;
	if (my_strcmp(args[0], "exit") == 0)
	{
		exit_command();
	}
	if (my_strcmp(args[0], "env") == 0)
	{
		env_command();
	}

	command_path = check_command_path(args[0]);

	if (command_path == NULL)
	{
		append_string(error_msg, args[0], sizeof(error_msg));
		append_string(error_msg, "' not found\n", sizeof(error_msg));
		write(STDOUT_FILENO, error_msg, strlen(error_msg));
	}
	execute_command(command_path, args);
	free(command_path);
}


/**
 * main - command prompt
 *
 * Return: 0
 */
int main(void)
{
	ssize_t chars_read;
	char prompt[] = "simple_shell$ ", command[MAX_COMMAND_LEN];
	int interactive_mode = isatty(fileno(stdin)) && isatty(fileno(stdout));

	if (interactive_mode == 1)
	{
		while (1)
		{
			write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
			chars_read = read(STDIN_FILENO, command, sizeof(command));
				if (chars_read == -1)
				{
					perror("read");
					exit(EXIT_FAILURE);
				}
			if (chars_read == 0)
			{
				write(STDOUT_FILENO, "\n", 1);
				break;
			}
			command[chars_read - 1] = '\0';

			hand_command(command);
		}
	}
	else
	{
		while ((chars_read = read(STDIN_FILENO, command, sizeof(command)
					 )) > 0)
		{
			command[chars_read  - 1] = '\0';
			hand_command(command);
		}
	}
	return (0);
}

