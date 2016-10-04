#include <stdio.h>
#include <stdlib.h>


struct stack
{
	int data;
	struct stack *next;
};

void push(struct stack **top, int value);

void display(struct stack *top);

void reverse(struct stack **top, int value);

void pop(struct stack **top);

void pushtobottom(struct stack **top, int value);


int main(int argc, char const *argv[])
{
	int choice = 1;
	struct stack *top = NULL;
	while(choice)
	{
		printf("\n1.Push\n2.Display\n3.Reverse\nEnter your choice : ");
		scanf("%d",&choice);
		if(choice == 1)
		{
			int value;
			printf("Enter value : ");
			scanf("%d",&value);
			push(&top, value);
			display(top);
		}
		else if(choice == 2)
		{
			display(top);
		}
		else if(choice == 3)
		{
			reverse(&top, top->data);
			display(top);
		}
		else
		{
			printf("Invalid choice\nExiting the program\n");
			exit(0);
		}

	}
	return 0;
}

void push(struct stack **top, int value)
{
	struct stack *temp;
	temp = (struct stack *) malloc(sizeof(struct stack));
	temp->data = value;
	temp->next = NULL;
	if(*top == NULL)
	{
		*top = temp;
	}
	else
	{
		temp->next = *top;
		(*top) = temp;
	}
}

void display(struct stack *top)
{
	if(top == NULL)
	{
		printf("Empty Stack\n");
	}
	else
	{
		while(top!= NULL)
		{
			printf("%d ->", top->data);
			top = top->next;
		}

	}
}

void pushtobottom(struct stack **top, int value)
{
	if((*top) == NULL)
	{
		push(top,value);
	}
	else
	{
		int item = (*top)->data;
		pop(top);
		pushtobottom(top, value);
		push(top,item);
	}
}


void reverse(struct stack **top, int value)
{
	if(*top != NULL)
	{
		int item = (*top)->data;
		pop(top);
		reverse(top,item);
		pushtobottom(top, item);
	}
}

void pop(struct stack **top)
{
	if(*top!=NULL)
	{
		*top = (*top)->next;
	}
}
