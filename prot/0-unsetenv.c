#include <stdlib.h>
#include <string.h>

int _unsetenv(const char *name) {
    // Find the index of the variable in the environment
    size_t namelen = strlen(name);
    char **envp = environ;
    int index = 0;
    while (*envp != NULL) {
        if (strncmp(*envp, name, namelen) == 0 && (*envp)[namelen] == '=') {
            // Found the variable, remove it by shifting the array
            while (envp[index] != NULL) {
                envp[index] = envp[index + 1];
                index++;
            }
            return 0;
        }
        envp++;
        index++;
    }
    return -1;  // Variable not found
}

