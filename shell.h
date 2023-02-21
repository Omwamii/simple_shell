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

int _size(char *str);
char *strn_concat(char *s1, char *s2);
int _strcmp(char *s1, char *s2);
<<<<<<< HEAD:main.h
char *find_path(const char *filename);
char *_strtok(char *str, const char *delim);
=======
char *find_path(char *filename); 
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
>>>>>>> b08308c50bcb33a6e534596dbd60f701b1808a73:shell.h

#endif
