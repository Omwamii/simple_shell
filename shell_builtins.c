#include "shell.h"

char *built_ins[] = {
	"cd",
	"exit",
	"setenv",
	"unsetenv"};

int (*builtin_func[]) (char **) = {
	&handle_cd,
	&handle_exit
	&handle_setenv,
	&handle_unsetenv
};

int handle_cd(char **args)
{
	if (args[1] == NULL)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	if (chdir(args[1]) != 0)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}

	return (1);
}

int handle_exit(char **args)
{
	int exit_status;

	if (args[1] == NULL) //no arguments passed
		exit(0); //normal
	else
	{
		exit_status = atoi(args[1]);
		exit(exit_status); //set status
	}
}

int handle_setenv(char **args)
{

}

