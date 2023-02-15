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

int main(int ac, char **av)
{
	char *buffer;
	size_t len = 0;
	size_t nread;

	printf("$");
	nread = getline(&buffer, &len, stdin);

	if(nread == -1)
	{
		fprintf(stderr, "Error reading input");
		exit(EXIT_FAILURE);
	}

	printf("%s", buffer);

	free(buffer);

	return (0);
}
