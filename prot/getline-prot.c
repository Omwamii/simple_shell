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
  *@lineptr: pointer to buffer to store content
  *@n: length of content to store
  *@stream: file stream
  *
  *Return: number of characters read or -1 if err
  */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static size_t pos = 0;
	char c;
	char *newbuf;

	//chack if lineptr is null;
	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;
		*lineptr = malloc(*n);
	}

	if (*lineptr == NULL) /* failed mem allocation */
	{
		perror("Error");
		return (-1);
	}

	//get input
	while (c = _fgetc(stream) != EOF)
	{
		if (pos >= *n)
		{
			*n += 1;
			newbuf = realloc(*lineptr, *n);
			if (newbuf == NULL)
			{
				perror("Error");
				return (-1);
			}
			*lineptr = newbuf;
		}

		(*lineptr)[pos++] = (char)c;
		if (c == '\n')
			break;

	}
	(*lineptr)[pos] = '\0';
	if (pos == 0)
		return (-1);

	return (pos);

}
