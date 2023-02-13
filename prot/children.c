#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
	int i = 5;
	pid_t pid;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	while (i--)
	{
		if (fork() == 0)
		{
			printf("%u\n", getpid());
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error");
			}
		}

		else
		{
			wait(NULL);
			printf("Child done!\n");
		}
	}
	return (0);
}
