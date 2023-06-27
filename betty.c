#include "shell.h"

/**
 * print_my_name - a function that prints the user's name
 * Return: void
 */
void print_my_name(void)
{
	char name[] = "Chris Becky";
	int name_len = sizeof(name) - 1;

	write(STDOUT_FILENO, "Name: ", 6);
	write(STDOUT_FILENO, name, name_len);
	write(STDOUT_FILENO, "\n", 1);
}
