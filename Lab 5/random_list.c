#include <stdio.h>
#include <stdlib.h>

struct RandomListNode
{
	int label;
	struct RandomListNode *next;
	struct RandomListNode *random;
};

typedef struct RandomListNode randomlistnode;
randomlistnode *copyRandomList(randomlistnode *A);
int main(int argc, char const *argv[])
{
	randomlistnode *A, *temp, *copy;
	temp = (randomlistnode *) malloc(sizeof(randomlistnode));

	temp->label = 1; temp->next = NULL; temp->random = NULL;
	A = temp;
	temp = (randomlistnode *) malloc(sizeof(randomlistnode));
	
	temp->label = 2; temp->next = NULL; temp->random = NULL;
	A->next = temp; A->random = temp;
	temp = (randomlistnode *) malloc(sizeof(randomlistnode));

	temp->label = 3; temp->next = NULL; temp->random = NULL;
	A->next->next = temp; A->random = temp; A->next->random = temp; A->next->next->random = A;
	temp = (randomlistnode *) malloc(sizeof(randomlistnode));
	
	temp->label = 4; temp->next = NULL; temp->random = NULL;
	A->next->next->next = temp; A->random = temp; A->next->next->next->random = A->next;

	copy = copyRandomList(A);

	return 0;
}

randomlistnode *copyRandomList(randomlistnode *A)
{
	randomlistnode *temp, *traverse = A, *copy, *head;
	printf("%d to %d \n", A->label, A->random->label);
	printf("%d to %d \n", A->next->label, A->next->random->label);
	printf("%d to %d \n", A->next->next->label, A->next->next->random->label);
	printf("%d to %d \n", A->next->next->next->label, A->next->next->next->random->label);
	while(traverse!=NULL)
	{
		temp = (randomlistnode *) (malloc(sizeof(randomlistnode)));
		temp->label = traverse->label;

		printf("temp = %d\n", temp->label);
		temp->next = traverse->next;
		traverse->next = temp;
		traverse = traverse->next->next;
	}


	traverse = A;
	while(traverse != NULL)
	{
		traverse->next->random = traverse->random->next;
		traverse = traverse->next->next;
	}
	traverse = A;
	while(traverse!=NULL)
	{
		// printf("%d to %d\n", traverse->label, traverse->random->label);
		traverse = traverse->next;
	}
	traverse = A->next;
	// printf("\n-------------------------------------------\n");
	head = copy = A->next;
	while(copy->next!= NULL && copy!=NULL)
	{
		// printf("%d to %d \n", copy->label, copy->random->label);
		if(copy->next == NULL) 
		{
			// printf("Hello\n");
			break;
		}
		copy->next = copy->next->next;
		copy = copy->next->next;
		// printf("changed copy to %d to %d \n", copy->label, copy->random->label);
	}
	traverse = head;
	while(traverse->next!=NULL)
	{
		if(traverse->next->next == NULL) 
			traverse->next = NULL;
		else
			traverse = traverse->next;
	}
	traverse = head;
	while(traverse!=NULL)
	{
		printf("%d to %d \n", traverse->label, traverse->random->label);
		traverse = traverse->next;
	}
	return head;
}