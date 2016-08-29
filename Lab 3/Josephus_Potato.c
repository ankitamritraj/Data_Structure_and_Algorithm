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
// int optimum(int , int );
void remove_node( struct node *delete);

int main()
{	
	int n , pos;
	printf("Enter value of n : ");
	scanf("%d",&n);;
	printf("Enter value of d : ");
	scanf("%d",&pos);
	Create(n);
	Display();
	pos = optimum(n,pos);
	printf("Best position is = %d\n", pos);
	return 0;	
}

void Create(int n)
{
	int i;
	// printf("Enter value of n :");
	// scanf("%d",&n);
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
	printf("%d\n", rear->data);
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
	
		printf("%d\n", rear->data);
		for(i=3;i<=n;i++)
		{
			temp = (struct node *) malloc(sizeof(struct node));
			temp->data = i;
			rear->next = temp;
			temp->next = front;
			temp->previos = rear;
			rear = temp;
			// rear = temp;
			printf("%d\n", rear->data);
		}
		printf("Rear data =  %d \n", rear->data);
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
		// printf("%d\n", front->data );
		temp = front;
		printf("%d\n", temp->data);
		// printf("rear data = %d \n", rear->data);
		temp = temp->next;
		// printf("Temp data = %d \n", temp->data);
		while(temp!=rear->next)
		{
			// temp = front;
			printf("%d\n", temp->data);
			temp = temp->next;
		}
	}
}

int optimum(int n, int pos)
{
	struct node *temp;
	int i , count = 0;
	temp = front;
	while(cnt != n-1)
	{
		for(i = 0 ;i < pos; i++)
		{
			temp = temp->next;
		}
		remove_node(temp);
	}
	return 0;
}

// void remove_node(strct node *delete)
// {

// }

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
		// free(temp);
	}
}












