#include "shell.h"

/**
 * my_strlen - a function to determine the lenght of a string
 * @s: string
 * Return: 0
 */

int my_strlen(const char *s)
{
	int len = 0;

	if (s == NULL)
		return (0);

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

/**
 * my_strcpy - a function that copiesa string
 * @dest: destination string
 * @src: source string
 * Return: string
 */

char *my_strcpy(char *dest, const char *src)
{
	int i = 0;

	if (dest == NULL || src == NULL)
		return (NULL);

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * my_strcmp - a function that compares two strings
 * @str1: string 1
 * @str2: string 2
 * Return: 0
 */

int my_strcmp(char *str1, char *str2)
{
	int a = 0;

	if (str1 == NULL || str2 == NULL)
	{
		if (str1 == str2)
		{
			return (0);
		}
		else if (str1 == NULL)
		{
			return (-1);
		}
		else
		{
			return (1);
		}
	}

	while (str1[a] != '\0' && str2[a] != '\0')
	{
		if (str1[a] != str2[a])
		{
			return (str1[a] - str2[a]);
		}
		a++;
	}
	return (0);
}

/**
 * my_strncat - a function that joins two strings
 * @dest: destination string
 * @src: source string
 * @n: size
 * Return: dest
 */

char *my_strncat(char *dest, const char *src, int n)
{
	int a = 0, b = 0;

	if (dest == NULL || src == NULL)
		return (NULL);

	while (dest[a] != '\0')
	{
		a++;
	}
	while (b < n && src[b] != '\0')
	{
		dest[a] = src[b];
		a++;
		b++;
	}
	dest[a] = '\0';
	return (dest);
}

/**
 * my_strdup - a function to duplicate strings
 * @s: string
 * Return: dupicated string
 */

char *my_strdup(const char *s)
{
	size_t len = my_strlen(s);

	char *dest = malloc((len + 1) * sizeof(char));

	if (dest == NULL)
	{
		return (NULL);
	}

	my_strcpy(dest, s);

	return (dest);
}

