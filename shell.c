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

			buf2 = strtok(buffer, "\n");

			if (access(buf2, X_OK) == 0)
			{
				free(buffer);
				execve(argv[0], argv, NULL);
			}
			else
			{
				perror("access");
				return (-1);
			}

		}
		else
		{
			wait(NULL);

		}
	}
}
