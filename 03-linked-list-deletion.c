/** Implementation to delete a node form the list at some point **/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int number;
	struct Node *next;
} Node;

void push(Node **head, int A)
{
	Node *n = malloc(sizeof(Node));
	n->number = A;
	n->next = *head;
	*head = n;
}

void deleteN(Node **head, int position)
{
	Node *temp;
	Node *prev;
	temp = *head;
	prev = *head;
	/** traverse to the position */
	for (int i = 0; i < position; i++)
	{
		/** if first position */
		if (i == 0 && position == 1)
		{
			*head = (*head)->next;
			free(temp);
		}
		else
		{
			if (i == position - 1 && temp)
			{
				prev->next = temp->next;
				free(temp);
			}
			else
			{
				prev = temp;

				/** if position greater than number of nodes */
				if (prev == NULL)
					break;
				temp = temp->next;
			}
		}
	}
}

/**
 * printList - prints the data, address and next of node
 * @head: head of node to start from
 */
void printList(Node *head)
{
	while (head)
	{
		printf("[%i] [%p]->%p\n", head->number, head, head->next);
		head = head->next;
	}
	printf("\n\n");
}

int main(void)
{
	Node *list = malloc(sizeof(Node));
	list->next = NULL;

	push(&list, 1);
	push(&list, 2);
	push(&list, 3);
	printList(list);

	/** delete from list */
	deleteN(&list, 1);
	printList(list);
	return (0);
}
