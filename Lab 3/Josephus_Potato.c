/***********************************************
Name: Ankit Amrit Raj
Roll: B15107
Purpose: IC250 Assignment 03 - Question 1 - Josephus Potato 
Date: 01/09/2016
***********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node 
{
	int data;
	struct node *next;
	struct node *previos;
};

struct node *front = NULL;
struct node *rear = NULL;

// void Enque();
void Deque();
void Display();
// void Is_Empty();
void Create(int );
int optimum(int , int );
struct node * remove_node( struct node *delete);

int main()
{	
	int n , pos;
	printf("Enter value of n : ");
	scanf("%d",&n);;
	printf("Enter value of d : ");
	scanf("%d",&pos);
	Create(n);
	printf("\nThe removal secquence is as follows \n");
	pos = optimum(n,pos);

	printf("\nHence the person at position %d survives. (WINNER)\n", pos);
	return 0;	
}

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

void Display()
{
	struct node *temp;
	if(front == NULL)
	{
		printf("Queue is Empty\n");
	}
	else
	{
		temp = front;
		printf("%d\n", temp->data);
		temp = temp->next;
		while(temp!=rear->next)
		{
			printf("%d\n", temp->data);
			temp = temp->next;
		}
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

void Deque()
{
	struct node *temp;
	if(front == NULL )
	{
		printf("Nothing to pop from the Queue\n");
	}
	else if(front == rear)
	{
		printf("Number Removed is : %d\n" ,front->data);
		front = NULL;
		rear = NULL;
	}
	else
	{
		printf("Number Removed is : %d", front->data);
		temp = front->next;
		front = temp;
		rear->next = front;
	}
}












