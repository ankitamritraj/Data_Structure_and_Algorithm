#include "all_Library.h"
#include "stacky.h"
void stack_reversal(stack * , int k);

int p = 0;

int main()
{
	int k = 0 ;
	int choice;
	choice = 1;
	stack *top = NULL, *temp = NULL;
	top = (stack *) malloc(sizeof(stack));
	temp = (stack *) malloc(sizeof(stack));
	top = NULL;
	while(choice == 1)
	{
		int value;
		printf("1.Enter\n2.Reverse\n");
		scanf("%d",&choice);
		if(choice == 1)
		{
			printf("Enter Data : ");
			scanf("%d",&value);
			top = push(top,value);
			display_stack(top);
			printf("\n");
		}
		else
		{
			int da = top->data;
			stack_reversal(top,k);
			printf("%d  ", da);
		}
	}
	return 0;
}

void stack_reversal(stack *top, int k)
{
	if(top->next == NULL)
	{
		// printf("%d\n",top->data);
		return ;
	}
	else
	{
		stack *temp;
		temp = (stack *) malloc(sizeof(stack));
		temp = pop(top);
		top = top->next;
		stack_reversal(top, k);
		printf("%d ", top->data);
	}
	return ;
}