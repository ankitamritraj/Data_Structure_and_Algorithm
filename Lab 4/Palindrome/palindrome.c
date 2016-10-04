#include "stacky.h"
#include "all_Library.h"

int main()
{
	while(1)
	{
		char ch;
		stack *top1 = NULL, *top2 = NULL , *temp = NULL;
		int flag = 0;
		printf("Enter a string (0 to exit) : ");
		scanf("%c",&ch);
		if(ch == '0')
		{
			printf("Exiting the program \n");
			exit(0);
		}
		else
		{
			{
				while(ch != '\n')
				{
					top1 = push(top1, ch);
					scanf("%c",&ch);
				}
				temp = top1;
				while(temp != NULL)
				{
					temp = pop(temp);
					top2 = push(top2,temp->data);
					temp = temp->next;
				}
				while(top2!=NULL)
				{
					if(top2->data != top1->data)
					{
						flag = 1 ;
						break;
					}
					top1 = top1->next;
					top2 = top2->next;
				}
				if(flag)
					printf("string is not palindrome \n");
				else
					printf("string is palindrome \n");
			}
		}
	}
}