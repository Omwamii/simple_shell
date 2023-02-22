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
	char *buffer, **args, *token, *buf2, *filepath;
	size_t len = 0;
	int k = 0, token_count = 0, i, exit_status, is_bin;
	pid_t my_pid; /* removed envp = environ */
	ssize_t nread;
	void (*f)(char **) = NULL;

	while (1)
	{
		print_prompt("simple_shell$ ");
		nread = _getline(&buffer, &len, stdin);
		fflush(stdout);

		if (nread == -1)
		{
			printf("\n");
			return (-1);
		}

		if (nread == 1)
			continue;

		if (buffer[nread - 1] == '\n')
			buffer[nread - 1] = '\0';

		/* add function to tokenize? */
		buf2 = strdup(buffer);

		if (buf2 == NULL)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}

		token = strtok(buffer, " ");

		while (token != NULL) /* end not reached */
		{
			token_count++;
			token = strtok(NULL, " ");
		}

		token_count++;
		args = malloc(sizeof(char *) * token_count);

		if (args == NULL)
		{
			perror("Error");
			return (-1);
		}

		token = strtok(buf2, " ");

		for (i = 0; token != NULL; i++)
		{
			args[i] = malloc(sizeof(char) * strlen(token));
			strcpy(args[i], token);
			token = strtok(NULL, " ");
		}

		args[i] = NULL;

		f = check_builtin(args[0]);
		if (f != NULL)
		{
			f(args);
			continue;
		}
		filepath = find_path(args[0]);

		if (filepath == NULL)
		{
			perror(args[0]);
			continue;
		}

		else
		{
			execute(filepath, args); /* Return or just exec? */
			if (strcmp(filepath, args[0]) != 0) /* will exec allow? */
				free(filepath);
		}
	}
	free(buf2);
	free(args);
	free(buffer);
	/* free(filepath); - for the purpose of using filepath in another fn*/

	return (0);
}
