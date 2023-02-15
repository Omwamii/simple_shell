#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char *str;
	struct node *next;
}node;

node *build_list(void)
{
	node *head = NULL;
	node *newnode, *temp;
	char *buffer, *token, *path;
	size_t len;

	path = getenv("PATH");
	token = strtok(path, ":");

	while (token)
	{
		len = strlen(token) + 1;
		buffer = malloc(len);

		if(buffer == NULL)
		{
			fprintf(stderr,"Error: cannot allocate memory");
			exit(EXIT_FAILURE);
		}

		snprintf(buffer, len, "%s", token);

		newnode = malloc(sizeof(node));
		newnode->str = strdup(buffer);
		newnode->next = NULL;

		if (head == NULL)
		{
			head = newnode;
			temp = newnode;
		}
		else
		{
			temp->next = newnode;
			temp = newnode;
		}

		free(buffer);
		token = strtok(NULL, ":");

	}

	return (head);

}

int main(void)
{
	node *current = build_list();

	while(current != NULL)
	{
		printf("%s\n", current->str);
		current = current->next;
	}

	return (0);
}
