#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/wait.h>

/**
  *main - entry point
  *@ac: argument count
  *@argv: arguments list
  *
  *Return: success value
  */

int main(__attribute__((unused)) int ac, char **argv, __attribute__((unused)) char **envp)
{
	char *buffer;
	size_t len = 0;
	int nread;

	while (1)
	{
		if (fork() == 0)
		{
			nread = getline(&buffer, &len, stdin);
			if (nread == -1)
			{
				perror("getline");
				exit(EXIT_FAILURE);
			}

			if (access(buffer, X_OK) == 0)
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
			printf("simple_shell$");

		}
	}
}
