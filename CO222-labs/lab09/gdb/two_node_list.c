// Warning This code is wrong though sometimes it may not give a segmentation fault

#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
	struct node* next;
	int value;
} Node;

Node* CreateTwoNodeList()
{
	Node* head = (Node*) malloc(sizeof(Node));
	Node* tail = (Node*) malloc(sizeof(Node));
	head->next = tail;
	head->value = 0;
	tail->value = 0;
	return head;
}

void FreeTwoNodeList(Node* head)
{
	free(head->next);
	free(head);
}

int main()
{
	// Create a 2 node list
	Node *head = CreateTwoNodeList();

	// Add some values
	head->value = 10;
	head->next->value = 20;

	// Delete the list
	//FreeTwoNodeList(head);

	// This will release the memory addresses which are used to store the values head, head->next
	// After delete memory allocations, those address can or cannot accessible  

	// Add some values		
	head->value = 50;			// This isn't working if 'FreeTwoNodeList(head);' was executed
	head->next->value = 80;		// This isn't working if 'FreeTwoNodeList(head);' was executed

	printf("%d %d\n", head->value , head->next->value);
}



