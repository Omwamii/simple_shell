#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

extern char **environ;

int main(int ac, char **av, char **env)
{
	printf("Address of environ: %p\n", environ);
	printf("Address of env: %p\n", env);
}
