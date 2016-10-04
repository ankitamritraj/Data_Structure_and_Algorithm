#include "myLibrary.h"


int main()
{	
	float n , pos;
	// float t = clock();
	printf("Enter value of n : ");
	scanf("%f",&n);
	printf("Enter value of d : ");
	scanf("%f",&pos);
	if((n - (int)(n)) !=0 || (pos -(int)pos) != 0 || n < 1 || pos<1)
	{
		printf("Hello\n");
		printf("Invalid input : Exiting Program\n");
		exit(0);
	}
	Create((int)n);
	printf("\nThe removal secquence is as follows \n");
	// pos = ((int)pos % n == 0) ? pos = n : pos % n;
	pos = optimum((int)n,(int)pos);
	printf("\nHence the person at position %d survives. (WINNER)\n", (int)pos);
	// t = clock() - t;
	// t = t / CLOCKS_PER_SEC;
	// printf("time = %f\n", t);
	return 0;	
}
