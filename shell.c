#include "main.h"

/**
  *main - entry point
  *@ac: argument count
  *@argv: arguments list
  *
  *Return: success value
  */

int main(__attribute__((unused)) int ac, char **argv, __attribute__((unused)) char **envp)
{
	char *buffer, *args[80], *token;
	size_t len = 0;
	int nread, argc = 0;
	pid_t my_pid;

	while (1)
	{
		printf("simple_shell$ ");
		nread = getline(&buffer, &len, stdin);
		fflush(stdout);

		if (buffer[nread - 1] == '\n')
		{
			buffer[nread - 1] = '\0';
		}

		if (nread == -1)
		{
			printf("\n");
			break;
		}

		token = strtok(buffer, " ");

		while(token != NULL)
		{
			args[argc++] = token;
			token = strtok(NULL, " ");
		}

		args[argc] = NULL;

		if (_strcmp(argv[0], "exit") == 0 && (argv[1] == NULL))
		{
			printf("\n");
			break;
		}

		my_pid = fork();

		if (my_pid == 0)
		{
			if (nread == 1)
				exit(0);

			if (access(buffer, X_OK) == 0)
			{
				if (execve(args[0], args, NULL) == -1)
				{
					perror(args[0]);
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				perror(buffer);
				exit(EXIT_FAILURE);
			}

		}

		else if (my_pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);

		}
	}
	free(buffer);

	return (0);
}
