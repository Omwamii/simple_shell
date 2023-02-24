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
	token = strtok(buffer, delim);
	while (token != NULL) /* end not reached */
	{
		token_count++;
		token = strtok(NULL, delim);
	}

	token_count++;
	args = malloc(sizeof(char *) * (token_count));

	if (args == NULL)
	{
		perror("Error");
		return (NULL);
	}

	token = strtok(buf2, delim);

	for (i = 0; token != NULL; i++)
	{
		args[i] = malloc(sizeof(char) * (strlen(token) + 1));
		strcpy(args[i], token);
		token = strtok(NULL, delim);
	}

	args[i] = NULL;
	free(buf2);
	return (args);

}

/**
 * cmp_chars - compare chars of strings
 * @str: input string.
 * @delim: delimiter.
 *
 * Return: 1 if are equals, 0 if not.
 */
int cmp_chars(char str[], const char *delim)
{
	unsigned int i, j, k;

	for (i = 0, k = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);
	return (0);
}

