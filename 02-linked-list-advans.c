#include <stdio.h>
#include <stdlib.h>

/**
 * example of a linked list
 */

/** a linked list node */
struct Node 
{
	int data;
	struct Node *next;
};

/**
 * append - appends new node at the end
 * @head_ref: reference of the head of the list
 * @new_data: data to assign
 */
void append(struct Node **head_ref, int new_data)
{
	/** 1. allocate node */
	struct Node *new_node = malloc(sizeof(struct Node));

	struct Node *last = *head_ref; /** used in step 5 */

	/** 2. put in the data */
	new_node->data = new_data;

	/** 3. This new node is going to be the last node, so it is NULL **/
	new_node->next = NULL;

	/** 4. If the linked list is empty, then make the new node as head */
	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}

	/** 5. else traverse till last node */
	while (last->next != NULL)
		last = last->next;

	/** 6. Change the next of last node */
	last->next = new_node;
}

/**
 * printList - traverse linked list starting from the given node
 * @node: the given node
 */
void printList(struct Node *node)
{
	while (node != NULL)
	{
		printf(" %d ", node->data);
		node = node->next;
	}
}

/**
 * pushAtFront - inserts new node at front of list
 * @head_ref: ref (pointer to pointer) to the head the list
 * @new_data: new data passed
 */
void pushAtFront(struct Node **head_ref, int new_data)
{
	/** 1. Allocate node */
	struct Node *new_node = malloc(sizeof(struct Node));

	/** 2. Put in the data */
	new_node->data = new_data;

	/** 3. Make next of new node as head */
	new_node->next = (*head_ref);

	/** 4. move the head to point to the new node */
	(*head_ref) = new_node;
}

/**
 * main - entry point
 * Return: always 0
 */
int main(void)
{
	/** Start with the empty list */
	struct Node *head = NULL;

	/** Insert 6, so list becomes 6->NULL */
	append(&head, 6);
	printf("Append list is: ");
	printList(head);

	/** 7 at the beginning. So list becomes 7->6->NULL */
	pushAtFront(&head, 7);
	printf("\nPush 7 at front. List is now : ");
	printList(head);

	printf("\n");
	return (0);
}
