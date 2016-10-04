#include "myLibrary.h"


int main()
{	
	int n , pos;
	printf("Enter value of n : ");
	scanf("%d",&n);;
	printf("Enter value of d : ");
	scanf("%d",&pos);
	Create(n);
	printf("\nThe removal secquence is as follows \n");
	pos = optimum(n,pos);
	printf("\nHence the person at position %d survives. (WINNER)\n", pos);
	return 0;	
}
