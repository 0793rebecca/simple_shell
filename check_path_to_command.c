#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * check_command_path - handle the path
 * @command: string command
 * Return: a pointer to the command path
 */
char *check_command_path(const char *command)
{
	char *path, *pathcopy, *tok;
	char command_path[MAX_PATH_LEN + MAX_COMMAND_LEN];

	path = getenv("PATH");

	if (path == NULL)
	{
		return (NULL);
	}

	pathcopy = my_strdup(path);

	if (pathcopy == NULL)
	{
		return (NULL);
	}

	tok = strtok(pathcopy, ":");
	if (access(command, X_OK) != -1)
	{
		free(pathcopy);
		return (my_strdup(command));
	}
	while (tok)
	{
		my_strcpy(command_path, tok);
		append_string(command_path, "/",
				sizeof(command_path));
		append_string(command_path, command,
				sizeof(command_path));

		if (access(command_path, X_OK) != -1)
		{
			free(pathcopy);
			return (my_strdup(command_path));
		}
		tok = strtok(NULL, ":");
	}
	free(pathcopy);
	return (NULL);
}
