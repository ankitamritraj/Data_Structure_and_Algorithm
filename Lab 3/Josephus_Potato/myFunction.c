#include "myLibrary.h"

struct node *front = NULL;
struct node *rear = NULL;

void Create(int n)
{
	int i;
	struct node *temp = NULL;
	temp = (struct node *) malloc(sizeof(struct node));
	temp->data = 1;
	temp->next = NULL;
	front = temp;
	front->next = front;
	front->previos = front;
	rear = temp;
	rear->next = front ;
	rear->previos = front ;
	if(n>1)
	{
		temp = (struct node *) malloc(sizeof(struct node));
		temp->data =2;
		front->next = temp;
		front->previos = temp;
		rear->next = temp;
		temp->previos = rear;
		temp->next = front;
		rear = temp;
	
		for(i=3;i<=n;i++)
		{
			temp = (struct node *) malloc(sizeof(struct node));
			temp->data = i;
			rear->next = temp;
			temp->next = front;
			temp->previos = rear;
			rear = temp;
		}
		rear->next = front;
	}
} 

int optimum(int n, int pos)
{
	struct node *temp , *next_node = front;
	int i , count = 0;
	temp = front;
	while(count != n-1)
	{
		for(i = 0 ;i < pos-1; i++)
		{
			temp = temp->next;
		}
		if(count == 0)
		{
			printf("[%d] Firstly, the person at position %d is removed. \n",count+1 , temp->data);
		} 
		else if(count == n-2)
		{
			printf("[%d] Finally, the person at position %d is removed.\n",count+1, temp->data );
		}
		else
		{
			printf("[%d] Then person at position %d is removed.\n", count+1, temp->data);
		}
		next_node = remove_node(temp);
		temp = next_node;
		count++;
	}
	return temp->data;
}

struct node * remove_node(struct node *delete)
{
	struct node *smaller, *larger;
	if(front == rear)
	{
		front = rear = NULL;
		smaller = NULL;
		larger = NULL;
		free(front);
	}
	else if(delete == front)
	{
		smaller = front->previos;
		larger = front->next;
		front = larger;
		rear->next = front;
	}
	else
	{
		smaller = delete->previos;
		larger = delete->next;
		smaller->next = larger;
		larger->previos = smaller;
		free(delete);
	}
	return larger;
}
