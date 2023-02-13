#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	char *buffer;
	size_t len = 0;

	printf("$");
	getline(&buffer, &len, stdin);
	printf("%s", buffer);

	return (0);
}
