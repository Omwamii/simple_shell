#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t ppid;
	pid_t pid;

	pid = getpid();
	ppid = getppid();
	printf("Parent ID: %u\n", ppid);
	printf("Child ID: %u\n", pid);

	return (0);
}
