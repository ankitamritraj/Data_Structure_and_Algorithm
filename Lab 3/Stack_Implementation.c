#include <stdio.h>
#include <stdlib.h>
struct node {
	int value;
	struct node *ptr;
};

struct node *stack = NULL;
struct node *top = NULL;

void push();
void pop();
void display();
int topmost();
int empty();
void destroy();
void exit();

int main()
{
	while(1)
	{
		int choice;
		printf("1.Push\n2.Pop\n3.Display\n4.Top\n5.Destroy\n6.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : push();
					 break;
		
			case 2 : pop();
					 break;

			case 3 : display();
					 break;
		
			// case 4 : destroy();
			// 		 break;

			case 5 : exit(0);
					 break;

			default: printf("Invalid input\n");
		}
	}
	return 0;	
}

void push()
{
	int n;
	scanf("%d",&n);
	struct node *temp = NULL;
	temp = (struct node *) malloc( 1 * sizeof(struct node));
	temp->value = n;
	temp->ptr = top;
	top = temp;
}

void display()
{
	struct node *temp;
	temp = top;
	while(temp != NULL)
	{
		printf("%d\n", temp->value);
		temp = temp->ptr;
	}
}

void pop()
{
	if(top == NULL)
	{
		printf("Stack is Empty\n");
	}
	else
	{
		struct node *temp = NULL;
		temp = (struct node *) malloc (1 * sizeof(struct node));
		temp = top->ptr;
		free(top);
		top = temp;
	}
}
