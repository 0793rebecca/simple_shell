#include "shell.h"
#define BUFFER_SIZE 1024
/**
 * custom_getline - write custom function
 * @line: line
 * Return: -1
 */
ssize_t custom_getline(char **line)
{
	int gl = 0;
	int buffer_capacity = BUFFER_SIZE;
	*line = malloc(buffer_capacity);

	if (*line == NULL)
	{
		return (-1);
	}

	while (1)
	{
		char c = getchar();

		if (c == EOF)
		{
			(*line)[gl] = '\0';
			return (gl);
		}
		else if (c == '\n')
		{
			(*line)[gl] = '\0';
			return (gl + 1);
		}
		else
		{
			(*line)[gl] = c;
			gl++;
		}
		if (gl == buffer_capacity - 1)
		{
			buffer_capacity *= 2;
			if (line == NULL)
			{
				(*line)[gl] = '\0';
				return (1);
			}
		}
	}
}
