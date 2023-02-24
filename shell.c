#include "shell.h"
/**
 *main - entry point
 *@ac: argument count
 *@argv: arguments list
 *
 *Return: success value
 */

int main(__attribute__((unused)) int ac, __attribute__((unused)) char **argv)
{
	char *buffer, *buf2,  **cmds;
	ssize_t nread;
	size_t len = 0;
	static int ret;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 0) /* redirected input(non-interactive mode) */
			return (non_interactive());

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
		{
			if (execute_single(buf2) == -1)/* execute single command */
				ret = -1;
		}
		else
		{
			if (execute_multiple(cmds) == -1) /* multiple commands using ';' */
				ret = -1;
			free_array(cmds);
		}
		free(buf2), free(buffer);
	}
	return (ret);
}

/**
  *free_array - frees array dynamically allocated
  *@arr: array to be freed
  */
void free_array(char **arr)
{
	int i = 0;

	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

/**
  *non_interactive - handles non-interactive mode
  *
  *Return: success value
  */
int non_interactive(void)
{
	char *buffer, *buf2, **cmds;
	size_t len = 0;
	ssize_t nread;
	int i = 0;

	nread = _getline(&buffer, &len, stdin);
	if (nread == -1)
		return (-1);
	buf2 = strdup(buffer);
	cmds = tokenize(buffer, ";");
	if (cmds == NULL)
	{
		if (execute_single(buf2) == -1)
			i = -1;
	}
	else
	{
		if (execute_multiple(cmds) == -1)
			i = -1;
		free_array(cmds);
	}
	free(buf2), free(buffer);
	return (i);
}
