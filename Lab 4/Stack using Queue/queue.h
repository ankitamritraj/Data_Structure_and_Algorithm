#include <stdlib.h>

typedef struct node_queue 
{
	int data;
	struct node_queue *next;
}queue;


queue * enque(queue *top, int val)
{
	queue *temp;
	temp = (queue *) malloc(sizeof(queue));
	temp->data = val;
	temp->next = NULL;
	if(top == NULL)
	{
		top = temp;
		top->next = NULL;
	}
	else
	{
		top->next = temp;
		top = temp;
	}
	return top;
}

queue *deque(queue *front)
{
	if(front == NULL)
	{
		printf("Queue is Empty\n");
		return 0;
	}
	queue *temp;
	temp = (queue *) malloc(sizeof(queue));
	temp = front ;
	front = front->next;
	return front;
}

void display_queue(queue *front)
{
	queue *temp;
	temp = (queue *) malloc(sizeof(queue));
	if(front == NULL)
	{
		printf("Queue is Empty\n");
	}
	else
	{
		printf("Numbers in the stack are : \n");
		temp = front;
		while(temp != NULL)
		{
			printf("%d  ", temp->data);
			temp = temp->next;
		}
	}
}
