#include "myLibrary.h"

int main()
{
	while(1)
	{
		printf("\n1.Enque\n2.Deque\n3.Display\n4.Exit\n");
		float choice;
		scanf("%f",&choice);
		if(choice!= (int)(choice))
			choice = 10;
		switch((int)choice)
		{
			case 1 : Enque();
					 break;
		
			case 2 : Deque();
					 break;

			case 3 : Display();
					 break;

			case 4 : exit(0);
					 break;
			default: printf("Invalid Input\n");
		}
	}
	return 0;	
}