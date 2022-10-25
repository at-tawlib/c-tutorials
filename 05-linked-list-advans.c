/** Complete implementation of linked list with insertion, traversing and deletion */
#include <stdio.h>
#include <stdlib.h>

/**
 * struct node - singly linked list
 * @data: integer
 * @next: points to next node
 */
struct node
{
	int data;
	struct node *next;
} *p, *tmp, *tmp1;

void insert_end(int);
void insert_beg(int);
void delete_beg(void);
void delete_end(void);
void display(void);

/**
 * main - entry point
 */
int main(void)
{
	int val, n;

	/** initial initializing of list to NULL */
	p = NULL;

	while (1)
	{
		printf("\n******************** MENU ************************");
		printf("\n1. INSERT AT END");
		printf("\n2. INSERT AT BEG");
		printf("\n3. DELETE FROM BEG");
		printf("\n4. DELETE FROM END");
		printf("\n5. DISPLAY");
		printf("\n6. EXIT");
		printf("\nEnter your choice : ");
		scanf("%d", &n);

		switch (n)
		{
			case 1:
				printf("\nEnter the value ");
				scanf("%d", &val);
				insert_end(val);
				break;
			case 2:
				printf("\n Enter the value ");
				scanf("%d", &val);
				insert_beg(val);
				break;
			case 3:
				delete_beg();
				break;
			case 4:
				delete_end();
				break;
			case 5:
				display();
				break;
			case 6:
				exit(0);
				break;
			default:
				printf("\n Wrong Choice!");
				break;
		}
		printf("\nDo you want to cont... ");
	}

	return (0);
}

/**
 * insert_end - insert element at the end
 * @ele: integer to insert
 * Return: void
 */
void insert_end(int ele)
{
	/** assign list (p) to temp */
	tmp = p;
	tmp1 = malloc(sizeof(struct node));
	tmp1->data = ele;
	tmp1->next = NULL; /** set next to NULL */

	/** if list is empty, head(p) points to element */
	if (p == NULL)
		p = tmp1;
	else
	{
		/** else traverse to last element and set its next to new element */
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = tmp1;
	}
}

/**
 * insert_beg - insert element at the beginning
 * @ele: integer data
 * Return: void
 */
void insert_beg(int ele)
{
	tmp = p;
	tmp1 = malloc(sizeof(struct node));
	tmp1->data = ele;
	tmp1->next = p;
	p = tmp1;
}

/**
 * delete_beg - delete element at beginning
 * Return: void
 * Desription - set head to point to next element
 */
void delete_beg(void)
{
	if (p == NULL)
		printf("\nNo element to be deleted!! ");
	else
	{
		printf("\nelement deleted - %d", p->data);
		p = p->next; /** set head to point to next element */
	}
}

/**
 * delete_end - delete element at the end
 * Return: void
 *
 * Description - assigns next of second to last element as NULL
 * if only one element, set head(p) to NULL
 */
void delete_end(void)
{
	tmp = p;
	struct node *pre;

	if (p == NULL)
		printf("\nNo element to be deleted! ");
	else if (p->next == NULL)
	{
		/** if only one element is in list */
		printf("\nElement deleted - %d", p->data);
		p = NULL;
	}
	else
	{
		/** traverse to last element */
		while (tmp->next != NULL)
		{
			pre = tmp;
			tmp = tmp->next;
		}
		pre->next = NULL;
		printf("\nElement deleted - %d", tmp->data);
		free(tmp);
	}
}

/**
 * display - traverse list and output the data
 */
void display(void)
{
	tmp = p;
	while (tmp != NULL)
	{
		printf("\n %d", tmp->data);
		tmp = tmp->next;
	}
}
