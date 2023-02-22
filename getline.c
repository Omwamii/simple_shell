#include "shell.h"

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
	static char *buffer;
	static size_t buffer_size, current_pos; /* zero atuomatic */
	size_t chars_read = 0, read_count = 0, i;

	buffer_size = BUFF_SIZE, buffer = malloc(buffer_size);
	while (1)
	{
		if (current_pos == buffer_size) /*buffer is full*/
		{
			buffer_size += BUFF_SIZE;  /*add more mem*/
			buffer = realloc(buffer, buffer_size);
		}
		char read_chunk[CHUNK_SIZE]; /*to read input in chunks*/

		read_count = read(fileno(stream), read_chunk, CHUNK_SIZE);
		if (read_count == -1) /*Read error*/
		{
			perror("Read error");
			return (-1);
		}
		if (read_count == 0) /*EOF only read*/
			return (-1);
		for (i = 0; i < read_count; i++)
		{
			if (read_chunk[i] == '\n')
			{
				buffer[current_pos++] = read_chunk[i];
				buffer[current_pos] = '\0';
				chars_read++;
				*lineptr = buffer, *n = chars_read;
				current_pos = 0; /*reset position to first position*/
				return (chars_read);
			}
			buffer[current_pos] = read_chunk[i];
			current_pos++, chars_read++;
			if (current_pos == buffer_size)
				buffer_size += BUFF_SIZE, buffer = realloc(buffer, buffer_size);
		}
	}
}
