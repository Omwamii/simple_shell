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
	char *buffer, *buf2;
	size_t len = 0;
	int nread;

	while (1)
	{
		printf("simple_shell$ ");

		if (fork() == 0)
		{
			nread = getline(&buffer, &len, stdin);
			if (nread == -1)
			{
				perror("getline");
				exit(EXIT_FAILURE);
			}

			if (buffer[nread - 1] == '\n')
				buffer[nread - 1] = '\0';

			if (access(buffer, X_OK) == 0)
			{
				char *args[] = {buffer, NULL};
				execv(args[0], args);
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
}
