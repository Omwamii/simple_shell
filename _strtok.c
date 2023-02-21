#include "shell.h"

/**
 * _strtok - tokenize string
 * @str: string to be tokenized
 * @delim: token delimeter
 *
 * Return: pointer to tokenized string
 */

char *_strtok(char *str, constant char *delim)
{
	static int current_pos;
	char *token;

	if (str != NULL)
	{
		token  = str;

		while (str[i] != '\0')
		{
			if (str[i] == *delim)
			{
				str[i] = '\0';
				current_pos++;
				return (str);
			}
			i++
			current_pos++;
		}
	}
	else
	{
		token = str + current_pos;
		i = current_pos;
		while (str[current_pos] != '\0')
		{
			if (str[current_pos] == *delim)
			{
				str[current_pos] = '\0';
				current_pos++;
				return (token);
			}
			current_pos++;
		}
	}
}
