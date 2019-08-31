// Fix the bugs

#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int value;
	struct node * next;
};

typedef struct node Node;

int main()
{
	Node head;
	head.value = 0; // Added, otherwise it is a garbage value

	Node* iterator = &head;	// Create a liked list with 10 elements | REM: is it 'linked list' ??

	int i = 0;

	for(i = 0; i<10 ; i ++)
	{
		Node* newNodep = (Node*) malloc(sizeof(Node)); // Updated
		iterator->next = newNodep;
		newNodep->value = i; 				// Pointer isn't pointing to any address, solution : give an address using malloc
		iterator = newNodep;
	}
	
	// Printing the values 
	iterator = &head;

	while(iterator->next != NULL)
	{
		iterator = iterator->next;			// Print all iterators after head
		printf("Value %d\n", iterator->value);
	}
	
	return 0;		// Added missing 'return 0' line, not compulsary, but better to have
}
