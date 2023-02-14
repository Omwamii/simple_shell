#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_path_directories(void) {
    char *path = getenv("PATH");
    if (path == NULL) {
        fprintf(stderr, "Error: PATH environment variable not set\n");
        exit(EXIT_FAILURE);
    }

    char *start = path;
    char *end;
    while (*start != '\0') {
        end = start;
        while (*end != ':' && *end != '\0') {
            end++;
        }

        char *dir = strndup(start, end - start);
        if (dir == NULL) {
            fprintf(stderr, "Error: cannot allocate memory for directory\n");
            exit(EXIT_FAILURE);
        }

        printf("%s\n", dir);

        free(dir);

        if (*end == ':') {
            start = end + 1;
        } else {
            break;
        }
    }
}

int main(void)
{
	print_path_directories();
}
