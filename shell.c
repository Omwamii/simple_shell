#include "shell.h"
/**
 *main - entry point
 *@ac: argument count
 *@argv: arguments list
 *
 *Return: success value
 */

int main(int ac, char **argv)
{
	char *buffer, **args, *filepath;
	ssize_t nread, len = 0;
	void (*f)(char **) = NULL;

	while (1)
	{
		print_prompt("simple_shell$ ");
		nread = _getline(&buffer, &len, stdin);
		if (nread == -1)
		{
			printf("\n");
			return (-1);
		}
		if (nread == 1)
			continue;
		args = tokenize(buffer, " \n");
		if (args == NULL)
		{
			perror("unable to tokenize");
			continue;
		}
		f = check_builtin(args[0]);
		if (f != NULL)
		{
			f(args);
			continue;
		}
		filepath = find_path(args[0]);
		if (filepath == NULL) /* command is not found */
		{
			perror(args[0]);
			continue;
		}
		execute(filepath, args); /* Execute the command */
		if (strcmp(filepath, args[0]) != 0)
			free(filepath);
	}
	free(args), free(buffer);
	return (0);
}
