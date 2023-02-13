#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char* get_env_var(const char* name) {
  extern char** environ;

  char** env = environ;
  size_t name_len = strlen(name);

  while (*env) {
    if (strncmp(name, *env, name_len) == 0)
    {
	    if (*(env)[name_len] == '=')
		    return (*(env) + name_len + 1);
	    continue;
    }
    env++;
  }

  return NULL;
}

int main(void)
{
	char *env = get_env_var("PATH");
	printf("%s\n", env);
}
