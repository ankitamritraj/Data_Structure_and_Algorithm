#include "all_Library.h"
#include "stacky.h"

int main(int argc, char const *argv[])
{
	while(1)
	{
		char ch;
		stack *top1 = NULL;
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
				int count = 0;
				while(ch != '\n')
				{
					top1 = push(top1, ch);
					scanf("%c",&ch);
				}
				while(top1 != NULL)
				{
					if(top1->data == ')')
					{
						count++;
					}
					else if(top1->data == '(')
					{
						count--;
					}
					top1 = top1->next;
					if(count<0)
					{
						break;
					}
				}
				if(count == 0) 
					printf("Paranthesis are balanced \n");
				else
					printf("Paranthesis are not balanced \n");
			}
		}
	}
	return 0;
}