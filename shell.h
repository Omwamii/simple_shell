#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

#define BUFF_SIZE 1024
#define CHUNK_SIZE 256
extern char **environ;

int _size(char *str);
char *strn_concat(char *s1, char *s2);
int _strcmp(char *s1, char *s2);
char *find_path(char *filename);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void print_prompt(char *s);
char *_strtok(char *str, const char *delim);

/**
  *struct builtins - has builtins and handlers
  *@name: name of the builtin
  *@handler: handler fn
  */
typedef struct builtins
{
	char *name;
	void (*handler)(char **);
} builtins;

void handle_cd(char **args);
void handle_cd2(char *curdir, char *olddir);
void handle_exit(char **args);
void handle_setenv(char **args);
void handle_unsetenv(char **args);
void handle_env(char **args);
void execute(char *filename, char **args);
void (*check_builtin(char *command))(char **args);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
/**
  *struct aliases - a struct of aliases
  *@alias_name: name of alias
  *@real_name: real cmd name
  */
typedef struct aliases
{
	char *alias_name;
	char *real_name;
} alias;
#endif
