#include <stdio.h>

int main()
{
	GSlist *stack_a = NULL , stack_b = NULL, *last_a = NULL, *last_b = NULL;
	printf("Enter n : ");
	scanf("%d",&n);
	if(n < 1)
	{
		printf("Invalid input\n");
	}
	else if(n == 1)
	{
		printf(" A to C\n");
	}
	else
	{
		stack_a = g_slist_append(stack_a , "ACB"); last_a = stack_a->next;
		stack_a = g_slist_append(stack_a , "ABC"); last_a = stack_a->next;
		stack_a = g_slist_append(stack_a , "BAC"); 

		stack_b = g_slist_append(stack_b , n-1); last_b = stack_b->next;
		stack_b = g_slist_append(stack_b , 1);   last_b = stack_b->next;
		stack_b = g_slist_append(stack_b , n-1); 

		while(stack_a != NULL)
		{
			char *temp;
			temp = stack_a->data;
			if(n==1)
			{
				printf("%c -> %c", temp[0], temp[2]);
			}
			else
			{
				if(temp[0] ==  'A' && temp[2] == 'C')
				{
					g_slist_append
				}
				else if(temp[0] ==  'A' && temp[2] == 'B')
				{
					
				}
				else if(temp[0] ==  'B' && temp[2] == 'C')
				{
					
				}
				else if(temp[0] ==  'B' && temp[2] == 'A')
				{
					
				}
				else if(temp[0] ==  'C' && temp[2] == 'A')
				{
					
				}
				else if(temp[0] ==  'C' && temp[2] == 'B')
				{
					
				}
			}
		}
	}
	return 0;	
}
