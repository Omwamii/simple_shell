#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

extern char **environ;

int _setenv(const char *name, const char *value, int overwrite)
{
	char **newenv = environ;
	int slen = strlen(getenv(name));
	int name_len = strlen(name);
	int i = 0;
	int j = 0;

	while (newenv[j])
	{
		if (strncmp(newenv[j], name, name_len) == 0 &&
				*(newenv)[name_len] == '=')
		{
			if (overwrite)
			{
				while (value[i])
		 		{
					*(newenv)[name_len + i] = value[i];
					i++;
				}
				return (0);
			}

		}
		j++;
	}

	return (-1);

}
