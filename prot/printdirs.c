#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void print_dirs(const char *path)
{
	const char *start = path;
	const char *end;
	int len;
	char *buffer;

	while (*start != '\0')
	{
		end = start;

		while(*end != ':' && *end != '\0')
		{
			end++;
		}

		len = end - start;
		buffer = malloc(len + 1);
		if (buffer == NULL)
		{
			fprintf(stderr, "Error: cannot allocate buffer memory\n");
			exit(EXIT_FAILURE);
		}

		strncpy(buffer, start, len);
		buffer[len] = '\0';

		printf("%s\n", buffer);

		free(buffer);

		start = end + 1;
	}

}

int main(void)
{
	char *path = getenv("PATH");

	printf("%s\n\n\n", path);
	print_dirs(path);

	return (0);
}
