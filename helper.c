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
	char *newenv;
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

/**
  *handle_cd2 - handles cd without input(helps handle_cd
  *@olddir: path to the old directory before changing
  *@curdir: path to current directory after changing
  */
void handle_cd2(char *curdir, char *olddir)
{
	char *cur_dir = cur_dir, *old_dir = olddir;
	size_t size = 0;

	if (chdir(getenv("HOME")) != 0)
		perror("cd");
	else
	{
		cur_dir = getcwd(NULL, size);
		if (cur_dir == NULL)
			perror("Error"); /* can't get current */
		else
			setenv("OLDPWD", old_dir, 1), setenv("PWD", cur_dir, 1);
	}
}

