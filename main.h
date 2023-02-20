#ifndef MAIN_H
#define MAIN_H

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
char *find_path(const char *filename);
unsigned int is_delim(char c, char *delim);
char *_strtok(char *s, char d);

#endif
