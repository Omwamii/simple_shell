#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/**
  *main - entry point
  *@ac: argument count
  *@av: string of arguments
  *
  *Return: sucess value
  */

int main(__attribute__((unused)) int ac, __attribute__((unused)) char **av)
{
	char *buffer;
	size_t len = 0;
	int nread;

	printf("$");
	nread = getline(&buffer, &len, stdin);

	if (nread == -1)
	{
		fprintf(stderr, "Error reading input");
		exit(EXIT_FAILURE);
	}

	printf("%s", buffer);
	free(buffer);

	return (0);
}

