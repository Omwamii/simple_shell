#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    fprintf(stderr, "Usage: %s filename\n", argv[0]);
    return 1;
  }

  char *path = getenv("PATH");
  char *path_copy = strdup(path);

  char *dir = strtok(path_copy, ":");
  while (dir != NULL)
  {
    char file[1024];
    snprintf(file, sizeof(file), "%s/%s", dir, argv[1]);

    struct stat sb;
    if (stat(file, &sb) == 0)
    {
      printf("%s\n", file);
      break;
    }

    dir = strtok(NULL, ":");
  }

  free(path_copy);
  return 0;
}

