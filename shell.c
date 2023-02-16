#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/wait.h>
#include <string.h>

/**
  *main - entry point
  *@ac: argument count
  *@argv: arguments list
  *
  *Return: success value
  */

int main(__attribute__((unused)) int ac, char **argv, __attribute__((unused)) char **envp)
{
	char *buffer, *args[100], *token;
	size_t len = 0;
	int nread, argc = 0;

	while (1)
	{
		printf("simple_shell$ ");
		nread = getline(&buffer, &len, stdin);

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

		if (fork() == 0)
		{
			if (nread == 1)
				exit(0);

			if (access(buffer, X_OK) == 0)
			{
				if (execve(args[0], args, NULL) == -1)
				{
					perror("execve");
					exit(EXIT_FAILURE);
				}
				exit(0);
			}
			else
			{
				perror(buffer);
				exit(EXIT_FAILURE);
			}

		}
		else
		{
			wait(NULL);

		}
	}
	free(buffer);

	return (0);
}
