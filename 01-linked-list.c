#include <stdio.h>
#include <stdlib.h>

/**
 * example of a linked list
 */

/** a linked list node */
struct Node {
	int data;
	struct Node* next;
};

/**
 * printList - prints contents of linked list starting from the given node (Traverse a list)
 * @n: the given node
 */
void printList(struct Node* n)
{
	while (n != NULL)
	{
		printf(" %d ", n->data);
		n = n->next;
	}
}

int main(void)
{
	struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;

	/** allocate 3 nodes in the heap */
	head = malloc(sizeof(struct Node));
	second = malloc(sizeof(struct Node));
	third = malloc(sizeof(struct Node));

	/**
	 * Three blocks have been allocated dynamically.
	 * We have pointers to these three blocks as head, second and third
	 * Data is random because we haven't assigned anything yet 
	 */
	head->data = 1; /** assign data in first node */
	head->next = second; /** link first node with the second node */

	second->data = 2; /** assign data to second node */
	second->next = third; /** link second node with the third node */

	third->data = 3; /** assign data to third node */
	third->next = NULL; /** next block made NULL to indicate that the list is terminated here */

	/** traverse of a linked list */
	printList(head);


	return (0);
}
