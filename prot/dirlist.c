#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char *str;
	struct node *next;
}node;

int lists()
{
	node *head = NULL;
	node *newnode, temp;
	char *buffer, token, path;
	size_t len;

	path = getenv("PATH");
	token = strdup(path);

	while(token)
	{
		len = sizeof(token) + 1;
		buffer = malloc(len);
		snprintf(buffer, len, "%s", token);

		newnode = malloc(sizeof(node));
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

		strncpy(temp->str, buffer, len);

	}

}
