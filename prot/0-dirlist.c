#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* value;
    struct Node* next;
} Node;

Node* build_path_list() {
    char* path = getenv("PATH");
    Node* head = NULL;
    Node* tail = NULL;
    char* dir = strtok(path, ":");

    while (dir != NULL) {
        Node* node = malloc(sizeof(Node));
        node->value = strdup(dir);
        node->next = NULL;

        if (head == NULL) {
            head = node;
        } else {
            tail->next = node;
        }

        tail = node;
        dir = strtok(NULL, ":");
    }

    return head;
}

int main(void)
{
	Node *current = build_path_list();

	while (current != NULL)
	{
		printf("%s\n", current->value);
		current = current->next;
	}

	return (0);
}

