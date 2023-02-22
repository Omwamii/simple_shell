#include "shell.h"
/**
  *check_builtin - checks if arg is a builtin
  *@command: command to be checked
  *
  *Return: pointer to handler fn or null
  */
void (*check_builtin(char *command))(char **args)
{
	int i;

	builtins b_in[] = {
		{"cd", &handle_cd},
		{"exit", &handle_exit},
		{"setenv", &handle_setenv},
		{"unsetenv", &handle_unsetenv},
		{"env", &handle_env},
		{NULL, NULL}
	};

	for (i = 0; b_in[i].name != NULL; i++)
	{
		if (strcmp(command, b_in[i].name) == 0)
			return (b_in[i].handler);
	}

	return (NULL);
}

/**
  *execute - execute command
  *@filepath: filepath passed
  *@args: arguments string
  *
  *Return: success value
  */
void execute(char *filepath, char **args)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		if (execve(filepath, args, NULL) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
		perror("fork");
	else
	{
		wait(NULL);

	}
}

/**
  *execute_single - execute when single command is passed
  *@buffer: arguments string for single cmd
  */
void execute_single(char *buffer)
{
	char *filepath, **args;
	void (*f)(char **);

	args = tokenize(buffer, " \n");
	if (args == NULL)
		perror("unable to tokenize");
	else
	{
		f = check_builtin(args[0]);
		if (f != NULL)
			f(args);
		else
		{
			filepath = find_path(args[0]);
			if (filepath == NULL) /* command is not found */
				perror(args[0]);
			else
			{
				execute(filepath, args); /* Execute the command */
				if (strcmp(filepath, args[0]) != 0)
					free(filepath);
			}
		}

		free(args);
	}

}

/**
  *execute_multiple - execute multiple commands sequentially
  *@cmds: array of multiple commands
  */
void execute_multiple(char **cmds)
{
	char **cmd = cmds;
	int i = 0;

	while (cmd[i] != NULL) //ls -l ; echo "me")
	{
		execute_single(cmd[i]);
		i++;
	}

}
