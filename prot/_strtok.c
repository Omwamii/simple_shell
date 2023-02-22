#include "shell.h"

/**
 * _strtok - tokenize string
 * @str: string to be tokenized
 * @delim: token delimeter
 *
 * Return: pointer to tokenized string
 */

char *_strtok(char *str, const char *delim)
{
	static char *current_pos;
	char *token;

	if (str != NULL)
	{
		current_pos = str;
	}

	token = current_pos;
	while (*current_pos != '\0')
	{
		if (*current_pos == *delim)
		{
			*current_pos = '\0';
			current_pos++;
			if (token != current_pos)
			{
				return (token);
			}
			else
			{
				token = current_pos;
			}
		}
		else
		{
			current_pos++;
		}
	}

	return (token);
}
