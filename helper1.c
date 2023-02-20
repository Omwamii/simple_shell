#include "shell.h"

/**
  *print_prompt - prints CL prompt
  *@s: string to print to prompt
  */

void print_prompt(char *s) //"simple_shell$ "
{
	write(1, s, strlen(s));
}

/**
  *_strtok - tokenizes a string to individual strings
  *@str: string passed
  *@delim
  *
  *Return: pointer to tokenized string
  */

char *_strtok(char *str, const char *delim)
{
	static int current_pos = 0; //initial position    "i\0am ian "
	char *token;
	int i = 0; //position

	if (str != NULL)
	{
		token = str;

		while (str[i] != '\0')
		{
			if (str[i] == *delim)
			{
				str[i] = '\0';
				current_pos++; //point to the next token
				return (str); // return token?
			}
			i++;
			current_pos++;
		}

		return (NULL);
	}
	else //str is null
	{
		token = str + current_pos; // str = str + inital -- increment pointer.
		i = current_pos;
		while (str[current_pos] != '\0') //check for '\0'
		{
			if (str[current_pos] == *delim)
			{
				str[current_pos] = '\0';
				current_pos++;
				return (token);
			}
			current_pos++;
		}
		return (NULL);
	}
}

