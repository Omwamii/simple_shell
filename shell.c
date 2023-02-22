#include "shell.h"
/**
 *main - entry point
 *@ac: argument count
 *@argv: arguments list
 *
 *Return: success value
 */

int main(__attribute__((unused)) int ac,__attribute__((unused)) char **argv)
{
	char *buffer, *buf2,  **cmds;
	ssize_t nread;
	size_t len = 0;

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

		buf2 = strdup(buffer);
		cmds = tokenize(buffer, ";");
		if (cmds == NULL)
			execute_single(buf2); /* execute single command */
		else
			execute_multiple(cmds); /* multiple commands using ';' */

		free(cmds);

	}
	free(buffer);
	free(buf2);
	return (0);
}
