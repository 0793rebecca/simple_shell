#include "shell.h"

/**
 * append_string - interpreter
 * @dest: destination string
 * @src: source string
 * @size: size of appendend string
 * Return: 0
 */
void append_string(char *dest, const char *src, size_t size)
{
	size_t dest_len = my_strlen(dest);
	size_t src_len = my_strlen(src);

	if (dest_len + src_len < size)
	{
		my_strncat(dest, src, size - dest_len - 1);
	}
}
