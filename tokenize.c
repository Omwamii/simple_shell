#include "shell.h"

/**
  *tokenize - tokenizes argument string to tokens
  *@buffer: buffer passed
  *@delim: delimiter to use to separate tokens
  *
  *Return: array of tokens or NULL if fails
  */

char **tokenize(char *buffer, const char *delim)
{
	char *token, **args, *buf2;
	int token_count = 0, i;

	buf2 = strdup(buffer);
	if (buf2 == NULL)
	{
		perror("Error");
		return (NULL);
	}
	token = _strtok(buffer, delim);
	while (token != NULL) /* end not reached */
	{
		token_count++;
		token = _strtok(NULL, delim);
	}

	token_count++;
	args = malloc(sizeof(char *) * token_count);

	if (args == NULL)
	{
		perror("Error");
		return (NULL);
	}

	token = _strtok(buf2, delim);

	for (i = 0; token != NULL; i++)
	{
		args[i] = malloc(sizeof(char) * strlen(token));
		strcpy(args[i], token);
		token = _strtok(NULL, delim);
	}

	args[i] = NULL;
	free(buf2);
	return (args);

}
