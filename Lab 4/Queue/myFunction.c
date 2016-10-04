#include "myLibrary.h"

struct node *rear_1 = NULL;
struct node *rear_2 = NULL;

void Enque()
{
	struct node *temp;
	float n;
	temp = (struct node *) malloc(sizeof(struct node));
	printf("Enter number : ");
	scanf("%f",&n);
	temp->next = NULL;
	temp->data = n;
	if(rear_1 == NULL)
	{
		rear_1 = temp;
	}
	else
	{
		temp->next = rear_1;
		rear_1 = temp;
	}
}

void Deque()
{
	struct node *temp;
	if(rear_2 == NULL  && rear_1!=NULL)
	{
		while(rear_1!=NULL)
		{
			temp = (struct node *) malloc(sizeof(struct node));
			temp = rear_1;
			rear_1 = rear_1->next ;
			push(temp);
		}
	}
	printf("Number removed from the Queue is : ");
	pop_stackTwo();	
	printf("\n");
}
void push(struct node *pushMe)            // Push to stack 2
{
	if(rear_2 == NULL)
	{
		rear_2 = pushMe;
		pushMe->next = NULL;
	}
	else
	{
		pushMe->next = rear_2;
		rear_2 = pushMe;
	}
}

void pop_stackTwo()
{
	if(rear_2 == NULL)
	{
		printf("Queue is Empty\n");
	}
	else
	{
		printf("%.3f ",rear_2->data);
		rear_2 = rear_2->next;
	
	}	
}

void Display()
{
	printf("Contents of the Queue are : \n");
	float count = 0;
	struct node *temp,*pushMe;
	if(rear_2 == NULL && rear_1 == NULL)
	{
		printf("Queue is Empty\n");
	}
	else
	{
		temp = (struct node *) malloc(sizeof(struct node));
		temp = rear_2;
		while(temp!=NULL && rear_2!=NULL)
		{
			printf("%.3f  ", temp->data);
			temp = temp->next;
		}
		temp = (struct node *) malloc(sizeof(struct node));
		temp = rear_1;
		while(temp!=NULL)
		{
			pushMe = (struct node *) malloc(sizeof(struct node));
			pushMe->data = temp->data;
			pushMe->next = rear_2;
			rear_2 = pushMe;
			temp = temp->next;
			count++;
		}
		while(count--)
		{
			pop_stackTwo();
		}
	}
}
