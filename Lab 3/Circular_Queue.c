/***********************************************
Name: Ankit Amrit Raj
Roll: B15107
Purpose: IC250 Assignment 03 - Question 1 - Josephus Potato 
Date: 01/09/2016
***********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// void Enque();
void Deque();
void Display();
// void Is_Empty();
void Create();

struct node 
{
	int data;
	struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

int main()
{	
	while(1)
	{
		int choice;
		printf("1.Create\n2.Enque\n3.Deque\n4.Display\n5.Is_Empty\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : Create();
					 break;

			// case 2 : Enque();
					 // break ;
		
			case 3 : Deque();
					 break ;

			case 4 : Display();
					 break ;

			// case 5 : Is_Empty();
					 // break ;
			default : exit(0);
					  break ;
		}
	}
	return 0;	
}

void Create()
{
	int n,i;
	printf("Enter value of n :");
	scanf("%d",&n);
	struct node *temp = NULL;
	temp = (struct node *) malloc(sizeof(struct node));
	temp->data = 1;
	temp->next = NULL;
	front = temp;
	printf("%d\n", front->data);
	rear = temp;
	for(i=2;i<=n;i++)
	{
		temp = (struct node *) malloc(sizeof(struct node));
		temp->data = i;
		temp->next = NULL;
		rear->next = temp;
		rear = temp;
		printf("%d\n", rear->data);
	}
	printf("Rear data =  %d \n", rear->data);
	rear->next = front;
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
		temp = temp->next;
		while(temp!=rear->next)
		{
			// temp = front;
			printf("%d\n", temp->data);
			temp = temp->next;
		}
	}
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
		// free(temp);
	}
}












