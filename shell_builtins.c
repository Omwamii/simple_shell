#include "shell.h"

/**
  *handle_cd - handles cd builtin
  *@args: argument string
  *
  *Return: success value
  */
void handle_cd(char **args)
{
	char *old_dir, *cur_dir;
	int size = 0;

	old_dir = getcwd(NULL, size);
	if (args[1] == NULL)
	{
		if (chdir(getenv("HOME")) != 0)
		{
			perror("Cannot change to /home");
			free(old_dir);
		}
		cur_dir = getcwd(NULL, size);
		if (cur_dir == NULL)
		{
			perror("Can't get current directory");
			free(old_dir);
		}
		setenv("OLDPWD", old_dir, 1), setenv("PWD", cur_dir, 1);
	}

	else
	{
		if (strcmp(args[1], "-") == 0)
		{
			if (chdir(getenv("OLDPWD")) != 0)
			{
				perror("Cannot change to previous dir");
				free(old_dir);
			}
			cur_dir = getcwd(NULL, size);
			if (cur_dir == NULL)
			{
				perror("Cannot get current dir");
				free(old_dir);
			}
			setenv("OLDPWD", old_dir, 1), setenv("PWD", cur_dir, 1);
			printf("%s\n", cur_dir);
		}

		else
		{
			if (chdir(args[1]) != 0)
			{
				perror("Unable to change directory");
				free(old_dir); /* should exit? */
			}

			cur_dir = getcwd(NULL, size);
			if (cur_dir == NULL)
			{
				perror("Cannot get current directory");
				free(old_dir);
			}
			setenv("OLDPWD", old_dir, 1), setenv("PWD", cur_dir, 1);
		}
	}
	free(old_dir), free(cur_dir);
}

/**
  *handle_exit - handles exit builtin
  *@args: argument string
  *
  *Return: succes value
  */
void handle_exit(char **args)
{
	int exit_status;

	fflush(stdout);
	fflush(stderr);

	if (args[1] == NULL) /* no arguments passed */
		exit(0); /* normal */
	else
	{
		exit_status = atoi(args[1]);
		exit(exit_status); /* set status */
	}
}

/**
  *handle_setenv - handles setenv builtin
  *@args: argument string
  *
  *Return: success value
  */
void handle_setenv(char **args)
{
	if (setenv(args[1], args[2], 1) == -1)
		perror("Unable to set variable");
	else
		printf("Variable set\n");
}

/**
  *handle_unsetenv - handles unsetenv builtin
  *@args: argument string
  *
  *Return: success value
  */
void handle_unsetenv(char **args)
{
	if (unsetenv(args[1]) != 0)
		perror("variable not found");
	else
		printf("Variable unset\n");

} /* need to check if variable set */

/**
  *handle_env - prints environment variables
  *@args: arguments string
  *
  *Return: success value
  */
void handle_env(char **args)
{
	int k = 0, found = 0;

	if (args[1] == NULL)
	{
		found = 1;
		while (environ[k] != NULL)
		{
			printf("%s\n", environ[k++]);
		}
	}

	if (!found)
		perror("Too many arguments");
	/*return (-1); Return value? */
}
