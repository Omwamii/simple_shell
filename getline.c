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
<<<<<<< HEAD
  *@lineptr: pointer to buffer to store content
=======
  *@blineptr: pointer to buffer to store content
>>>>>>> b08308c50bcb33a6e534596dbd60f701b1808a73
  *@n: length of content to store
  *@stream: file stream
  *
  *Return: number of characters read or -1 if err
  */

<<<<<<< HEAD

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
  static char *buffer;
  static size_t buffer_size = 0;
  static size_t current_pos = 0;
  size_t chars_read = 0;
  ssize_t read_count;

  buffer_size = BUFF_SIZE;
  buffer = malloc(buffer_size);
  while (1)
  {
	  if (current_pos == buffer_size)
	  {
		  buffer_size += BUFF_SIZE;
		  buffer = realloc(buffer, buffer_size);
	  }
	  char read_chunk[CHUNK_SIZE]; //to read input in chunks
	  read_count = read(fileno(stream), read_chunk, CHUNK_SIZE);
	  if (read_count == -1 || read_count == 0)// READ ERROR OR EOF
		  return (-1);
	  for (int i = 0; i < read_count; i++)
	  {
		  if (read_chunk[i] == '\n')
		  {
			  buffer[current_pos++] = read_chunk[i];
			  buffer[current_pos] = '\0';
			  chars_read++;
			  *lineptr = buffer;
			  *n = chars_read; //confirm whether +1 or +current_pos
			  current_pos = 0;
			  return (*n);
		  }
		  buffer[current_pos] = read_chunk[i];
		  current_pos++, chars_read++;
		  if (current_pos == buffer_size)
		  {
			  buffer_size += BUFF_SIZE;
			  buffer = realloc(buffer, buffer_size);
		  }
	  }
  }
}

=======
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
>>>>>>> b08308c50bcb33a6e534596dbd60f701b1808a73

	return (i); // +ve 0, -1
}
