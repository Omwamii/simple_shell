#include "shell.h"

/**
  *find_path - finds if file is in $PATH
  *@filename: file to search
  *
  *Return: pointer to file string
  */

char *find_path(char *filename)
{
	char *path, file_copy;
	char *path_copy, *dir;
	char *file;

	if (filename == NULL)
	{
		perror(filename);
		return (NULL);
	}

	if (access(filename, F_OK) == 0) /*complete path was given*/
		return (filename);

	path = getenv("PATH");
	path_copy = strdup(path);
	dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		file = malloc(strlen(filename) + strlen(dir) + 2);
		sprintf(file, "%s/%s", dir, filename);

		if (access(file, F_OK) == 0)
		{
			free(path_copy);
			return (file);
		}
		free(file);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
