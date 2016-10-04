#include <stdlib.h>

struct node_queue 
{
	int data;
	struct node *next;
};

typedef struct node_queue queue;

void enque(queue *Q, queue *top, int val)
{
	queue *temp;
	temp = (queue *) malloc(sizeof(queue));
	temp->data = val;
	temp->next = NULL;
	top->next = temp;
	top = temp;
}

struct node * deque(queue *Q, queue *front)
{
	queue temp;
	temp = (queue *) malloc(sizeof(queue));
	temp = front ;
	fornt = fornt->next;
	return temp;
}

void display_queue(queue *Q, queue *front)
{
	queue temp;
	temp = (queue *) malloc(sizeof(queue));
	if(front == NULL)
	{
		printf("Queue is Empty\n");
	}
	else
	{
		temp = front;
		while(temp != NULL)
		{
			printf("%d  ", temp->data);
			temp = temp->next;
		}
	}
}
