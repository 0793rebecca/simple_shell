#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#include <sys/wait.h>
#include <stddef.h>

#define MAX_COMMAND_LEN 100
#define MAX_PATH_LEN 100
#define BUFFER_SIZE 1024

/*my string functions*/
int my_strcmp(char *str1, char *str2);
int my_strlen(const char *s);
char *my_strcpy(char *dest, const char *src);
char *my_strncat(char *dest, const char *src, int n);
char *my_strdup(const char *s);

/*task 0*/
void print_my_name(void);

/*task 1 and 2*/
int main(void);
void append_string(char *dest, const char *src, size_t size);
void execute_command(const char *command_path, char *const args[]);
void hand_command(char *command);

/*task 3*/
char *check_command_path(const char *command);

/*task 4*/
void exit_command(void);

/*task 5*/
extern char **environ;
void env_command(void);

/*task 6*/
ssize_t custom_getline(char **line);

#endif
