/** Delete the first node in a linked list where data == key */
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

/** inserts new node to the front of the list */
void push(struct Node **head_ref, int new_data)
{
	struct Node *new_node = malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

/**
 * deleteNode - deletes first occurance of key in linked list
 */
void deleteNode(struct Node **head_ref, int key)
{
	/** store head node */
	struct Node *temp = *head_ref, *prev;

	/** if head node itself holds the key to be deleted */
	if (temp != NULL && temp->data == key)
	{
		*head_ref = temp->next; /** change head */
		free(temp); /** free old head */
		return;
	}

	/** search for key to be deleted and keep track of previous node */
	while (temp != NULL && temp->data != key)
	{
		prev = temp;
		temp = temp->next;
	}

	/** if key not present return */
	if (temp == NULL)
		return;

	/** unlink the node from linked list */
	prev->next = temp->next;
	free(temp);
}

void printList(struct Node *node)
{
    while (node != NULL)
	{
        printf(" %d ", node->data);
        node = node->next;
    }
}

int main(void)
{
	struct Node *head = NULL;

	push(&head, 7);
	push(&head, 1);
	push(&head, 3);
	push(&head, 2);
	push(&head, 7);

	puts("Created Linked List: ");
	printList(head);
	deleteNode(&head, 1);
	puts("\nLinked List after Deletion of 1: ");
	printList(head);

	return (0);
}
