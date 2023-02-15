#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

/**
  *main - entry point
  *@ac: argument count
  *@argv: arguments list
  *
  *Return: success value
  */

int main(int ac, char **argv, __attribute__((unused)) char **envp)
{
	char *buffer, *buffer2;
	struct stat sb;
	int len = 0;
	int nread;
	char dir[] = "/usr/bin/";
	char *agrv, *line_pos;

	while (1)
	{
		if (fork() == 0)
		{
			nread = getline(&buffer, &len, stdin);
			if (nread == -1)
			{
				fprintf(stderr, "Error reading input\n");
				exit(EXIT_SUCCESS);
			}
			line_pos = strchr(buffer, '\n');
			if (line_pos != NULL)
				*line_pos = '\0';
			strcat(dir, buffer);
		}
		else
		{
			wait(NULL);
			printf("simple_shell$");

		}
	}
}
