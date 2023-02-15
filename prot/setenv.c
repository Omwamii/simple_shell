#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char **environ;

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
		return (0); //variable exists & overwrite disabled
	}

	newenv = malloc(name_len + val_len + 2); //allocate length for var_name, value '=' and '\0'
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
