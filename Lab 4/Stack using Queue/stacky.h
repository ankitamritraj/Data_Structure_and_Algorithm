#include "all_Library.h"

typedef struct node_stack
{
	char data;
	struct node_stack *next;
}stack;


stack *pop(stack *top)
{
	stack *temp;
	temp = (stack *) malloc(sizeof(stack ));
	temp = top;
	top = top->next;
	return temp;
}

stack *push(stack *top, char data)
{
	stack *temp;
	temp = (stack *) malloc(sizeof(stack));
	temp->data = data;
	temp->next = top;
	top = temp;
	return top ;
}

void display_stack(stack *top)
{
	stack *temp;
	if(top == NULL)
	{
		printf("Stack is Empty\n");
	}
	else
	{
		temp = (stack *) malloc(sizeof(stack));
		temp = top;
		while(temp!=NULL)
		{
			printf("%c",temp->data);
			temp = temp->next;
		}
	}
}
