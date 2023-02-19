#include "shell.h"

/**
  *_fgetc - reads a character a time from stream
  *@stream
  *
  *Return: character if read or EOF
  */

int _fgetc(FILE *stream)
{
	char c;
	if (read(fileno(stream), &c, 1) == 1)
		return c;
	else
		return EOF;
}

/**
  *_getline - gets input from user until
  *@blineptr: pointer to buffer to store content
  *@n: length of content to store
  *@stream: file stream
  *
  *Return: number of characters read or -1 if err
  */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t i = 0;
	int c;

	while ((c = _fgetc(stream)) != EOF && c != '\n' &&
			i < (*n - 1))
	{
		**lineptr++ = c;
		i++;
	}

	if (c == '\n')
	{
		**lineptr++ = c;
		i++;
	}

	if (c == 0x05) //EOF ASCII VALUE
		return (-1);

	**lineptr = '\0';

	return (i); // +ve 0, -1
}
