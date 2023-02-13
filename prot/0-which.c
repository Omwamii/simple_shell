#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s filename ...\n", argv[0]);
    return 1;
  }

  char* path = getenv("PATH");
  char* path_copy = strdup(path);

  char* token = strtok(path_copy, ":");
  while (token) {
    for (int i = 1; i < argc; i++) {
      char buffer[1024];
      sprintf(buffer, "%s/%s", token, argv[i]);

      if (access(buffer, X_OK) == 0) {
        printf("%s\n", buffer);
        break;
      }
    }
    token = strtok(NULL, ":");
  }

  free(path_copy);
  return 0;
}

