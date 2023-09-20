#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define TOK_DELIM " \n"
extern char **environ;

char *read_line(void);
char **tok_line(char *line);
int my_cd(char **args);
int my_env(char **args);
int my_help(char **args);
int my_exit(char **args);
int execute(char **args);
int launch(char **args);
int _strlen(char *c);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(char *s);
int _putchar(char c);
void _puts(char *str);
char *find_path(char *path, char *cmd);
char *find_cmd(char *cmd);
#endif
