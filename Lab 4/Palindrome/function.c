#include "all_Library.h"
#include "stack.h"

void getString(stack *top)
{
	char ch;
	while(ch != '\n')
	{
		top = push(top, ch);
		scanf("%c",&ch);
	}
}