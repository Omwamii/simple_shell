#include "main.h"

/**
  *main - entry point
  *@ac: argument count
  *@argv: arguments list
  *
  *Return: success value
  */
extern char **environ;

int main(int ac, char **argv)
{
	char *buffer, **args, *token, *token_buf, *buf2;
	size_t len = 0;
	int k = 0, token_count = 0, i;
	pid_t my_pid;
	char **envp = environ;
	ssize_t nread;
	char *filepath;

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
			return (-1);
		}

		if (nread == 1)
			continue;

		buf2 = strdup(buffer);

		if (buf2 == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}

		token_buf = strtok(buffer, " ");

		while(token_buf != NULL)
		{
			token_count++;
			token_buf = strtok(NULL, " ");
		}

		token_count++;
		args = malloc(sizeof(char *) * token_count);

		if (args == NULL)
		{
			perror("malloc");
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

		if (strcmp(args[0], "env") == 0 && (args[1] == NULL))
		{
			while (envp[k] != NULL)
			{
				printf("%s\n", envp[k++]);
			}
			continue;
		}
		if (strcmp(args[0], "exit") == 0 && (args[1] == NULL))
			break;

		filepath = find_path(args[0]);

		if (filepath == NULL)
		{
			perror(filepath);
			printf(":(\n");
			continue;
		}
		my_pid = fork();
		if (my_pid == 0)
		{
			if (execve(filepath, args, NULL) == -1)
			{
				perror(args[0]);
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
			free(filepath);

		}
	}
	free(buf2);
	free(args);
	free(buffer);

	return (0);
}
