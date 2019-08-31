
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	struct node* next;
	char word[100];
	int value;

} Node;

void printList(Node * head);
void push(Node * head, char * str, int val);

int pop(Node ** head);
int removeNode(Node * head, int n);

int main(int argc, char **argv){

	Node head;
	Node * iterator = &head;
	FILE *fp;

	int len=0, maxLen=0,i=0, j=0;
	char str[999];
	char * charP = str;

	if(argc<2){											
		// ERROR: No enough arguments
		printf("Usage: %s <input-file>\n", argv[0]);
		return -1;
	}
	
	fp = fopen(argv[1], "r");

	if(fp==NULL){
		// ERROR: can't open the file	
		printf("Error: Can't access the file\n");									
		return -1;
	}

	// Creating a valid head node for obtaining words
	head.value = 0;
	head.next = NULL;
	strcpy(head.word,"");

	/*** Read values from the file *******************************************************************/

	while (fscanf(fp, "%s", str)!=EOF){
		len = strlen(str);

		// detect and remove '.' from words
		if(str[len-1] == '.') str[len-1] = '\0';

		if(len !=0){
			maxLen = (maxLen > len) ? maxLen : len;
			push(&head, charP, len);
		}
	}

	printf("Print each word again:\n");
	printList(&head);
	printf("\n\n");

	/*** Sort - largest first *******************************************************************/

	// Creating a valid head node for sorted list words
	Node sorted;
	sorted.value = 0;
	strcpy(sorted.word,"");
	sorted.next = NULL;

	iterator = &head;

	for(i=maxLen;i>0;i--){	
		iterator = &head;
		j=0;
		while(iterator != NULL){
			charP = iterator->word;
			if(iterator->value == i){
				// add this node to sorted list
				push(&sorted, charP, iterator->value);
			}

        	iterator = iterator->next;
			j++;
    	}
	}

	printf("Sorted list:\n");
	printList(&sorted);
	return 0;
}

void printList(Node * head){
    
   Node * current = head->next;
    
   while(current != NULL){
   	//printf("%d %s\n", current->value, current->word);
		printf("%s\n", current->word);
      current = current->next;  
   }
	return;
}

void push(Node * head, char * str, int val){

	Node * current = head;
    
   while(current->next != NULL){
     current = current->next;
   }
	
	// Adding the new variable
	current->next = malloc(sizeof(Node));
	current->next->value = val;
	strcpy(current->next->word,str);
	current->next->next = NULL;
	return;
}


int pop(Node ** head){
	
	int ret = -1;
	Node * nextNode = NULL;

	if (*head ==NULL){
		return -1;
	}

	nextNode = (*head)->next;
	ret = (*head)->value;
	free(*head);
	*head = nextNode;
	return 0;
}

int removeNode(Node * head, int n){

	if (n==0){
		//pop(head);	//not required in this problem

	}else{
	
		Node * current = head;
		Node * tempNode = head;
		int counter = 0;

		// remove the 'n'th index node

		while(current->next != NULL){

			if(counter == n-1){
				// Remove the next node
				tempNode = current->next;
				current->next = tempNode->next;
				printf(">> remove %s\n", tempNode->word);
				free(tempNode);
				return 0;
			}
			current  = current->next;
			counter++;
		}
		return -1;
	}
}
