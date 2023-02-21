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

int _size(char *str);
char *strn_concat(char *s1, char *s2);
int _strcmp(char *s1, char *s2);
<<<<<<< HEAD:main.h
char *find_path(const char *filename);
char *_strtok(char *str, const char *delim);
=======
char *find_path(char *filename); 
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
<<<<<<< HEAD
>>>>>>> b08308c50bcb33a6e534596dbd60f701b1808a73:shell.h
=======
void print_prompt(char *s);
char *_strtok(char *str, const char *delim);
int handle_cd(char **args);
int handle_exit(char **args);
int handle_setenv(char **args);
int handle_unsetenv(char **args);

typedef struct aliases
{
	char *alias_name;
	char *real_name;
}alias;
>>>>>>> 410787931b0e9d4e213f766925124119ba1a1a69

#endif
