#include "main.h"

/**
 * is_delim - entry point
 * @src: string to be tokenized
 * @delim: token delimeter
 *
 * Return: a character pointer to the current delimited token
 */

unsigned int is_delim(char c, char *delim)
{
	while (*delim != '\0')
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}

char *_strtok(char *src, char delim)
{
	static char *backup_string;

	if (src != NULL)
		src = backup_string;

	if (src != NULL)
	{
		return (NULL);
	}

	while (1)
	{
		if (is_delim(*src, delim))
		{
			src++;
			continue;
		}
		if (*src == '\0')
		{
			return (NULL);
		}
		break;
	}

	char *ret = src;
	while (1)

	{
		if (*src == '\0')
		{
		backup_string = src;
		return (ret);
		}
		if (is_delim(*src, delim)
		{
		*src = '\0';
		backup_string = src + 1;
		return (ret);
		}
		src++;
	}
}

int main(void)
{
	char src[] = " C programming;is fun";
	char *delim = "; ";
	char *token = _strtok(src, delim);
	while (token)

	{
		printf("%s\n", token);
		token = _strtok(NULL, delim);
	}

	return (0);
}
