#include "shell.h"

/**
  *print_prompt - prints CL prompt
  *@s: string to print to prompt
  */

void print_prompt(char *s)
{
	write(1, s, strlen(s));
}

/**
  *_strtok - tokenizes a string to individual strings
  *@str: string passed
  *@delim: delimiter string
  *
  *Return: pointer to tokenized string
  */

char *_strtok(char *str, const char *delim)
{
	static int current_pos; /* keep track of token pos */
	char *token;
	int i = 0; /*temporary position */

	if (str != NULL)
	{
		token = str;

		while (str[i] != '\0')
		{
			if (str[i] == *delim)
			{
				str[i] = '\0';
				current_pos++; /*point to the next token*/
				return (str); /* return token? */
			}
			i++;
			current_pos++;
		}

		return (NULL);
	}
	else /* str is null */
	{
		token = str + current_pos; /*str = str + inital -- increment pointer.*/
		i = current_pos;
		while (str[current_pos] != '\0') /*check for '\0'*/
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

/* unused function */
/**
  *_setenv - sets environment variable
  *@name: name of variable
  *@value: value to set
  *@overwrite: overwrite value
  *
  *Return: success value
  */
int _setenv(const char *name, const char *value, int overwrite)
{
	char *newenv, *oldenv;
	int name_len, val_len;

	if (name == NULL || strchr(name, '=') != NULL || name[0] == '\0')
		return (-1);

	oldenv = getenv(name);
	name_len = strlen(name);
	val_len = strlen(value);

	if (!overwrite && newenv != NULL)
	{
		return (0); /*variable exists & overwrite disabled*/
	}

	newenv = malloc(name_len + val_len + 2); /*allocate length for var_name,
						   *value '=' and '\0'
						  */
	if (newenv == NULL)
	{
		perror("memory cannot be allocated");
		exit(EXIT_FAILURE);
	}

	memcpy(newenv, name, name_len);
	newenv[name_len] = '=';
	memcpy(newenv, value, val_len);
	newenv[name_len + val_len + 1] = '\0';

	if (putenv(newenv) != 0)
	{
		free(newenv);
		return (-1);
	}

	return (0);
}

/*unused function */
/**
  *_unsetenv - unsets an environment variable
  *@name: variable to unset
  *
  *Return: success value
  */
int _unsetenv(const char *name)
{
	int index = 0, unset = 0;
	size_t name_len;
	char **envp = environ;

	name_len = strlen(name);
	while (*envp != NULL)
	{
		if (strncmp(*envp, name, name_len) == 0 && (*envp)[name_len] == '=')
		{
			/* variable has been found, remove by shifting array element */
			while (envp[index] != NULL)
			{
				envp[index] = envp[index + 1];
				index++;
			}
			unset = 1;
			return (0);
		}
		index++;
		envp++;
	}
	if (!unset)
		return (-1);
}
