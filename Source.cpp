//Delete a node
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct Node
{
	int data;
	struct Node *next;
};

struct Node* push(struct Node *head_ref, int new_data)
{
	struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
	if (new_node == NULL)
		printf("\nStack Overflow");
	else
	{
		new_node->data = new_data;
		new_node->next = head_ref;
		head_ref = new_node;
	}
	return head_ref;
}

struct Node* delete_node(struct Node *head_ref, int position)
{
	int pos = 1;
	struct Node *prev = head_ref, *curr = head_ref;
	if (position == 1)
	{
		head_ref = head_ref->next;
		free(curr);
	}
	else
	{
		while (pos != position && curr != NULL)
		{
			prev = curr;
			curr = curr->next;
			pos++;
		}
		prev->next = curr->next;
		free(curr);
	}

	return head_ref;
}

void printList(struct Node *node)
{
	while (node != NULL)
	{
		printf(" %d ", node->data);
		node = node->next;
	}
}

int main()
{
	struct Node *head = NULL, *del = NULL;
	head = push(head, 9);
	head = push(head, 7);
	head = push(head, 2);
	head = push(head, 1);
	printf("\n Linked list : \n");
	printList(head);
	del = delete_node(head, 3);
	printf("\n After Deletion, Linked list is : \n");
	printList(del);
	del = delete_node(head, 1);
	printf("\n After Deletion, Linked list is : \n");
	printList(del);
	_getch();
}