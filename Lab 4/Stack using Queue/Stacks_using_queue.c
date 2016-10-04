#include "all_Library.h"
#include "queue.h"

int main()
{
	queue *front1, *top1 = NULL, *front2 = NULL, *top2 = NULL;
	front1 = (queue *) malloc(sizeof(queue));
	front1 = NULL;
	int choice ,val;

	while(1)
	{
		queue *temp;
		temp = (queue *) malloc(sizeof(queue));
		printf("\n1.Enque\n2.Deque\n3.Display\n4.Exit\n");
		scanf("%d",&choice);
		if(choice == 1)
		{
			scanf("%d",&val);
			while(front1!=NULL)
			{
				if(front2 == NULL)
				{
					top2 = enque(top2, front1->data);
					front2 = top2;
				}
				else if (front2->next == NULL)
				{
					top2 = enque(top2,front1->data);
					front2->next = top2;
				}
				else
				{
					top2 = enque(top2, front1->data);
				}
				front1 = deque(front1);
				if(front1 == NULL) 	top1 == NULL;	
			}
			temp->data = val;
			temp->next = NULL;
			front1 = top1 =temp;

			while(front2!=NULL)
			{
				if(front1 == NULL)
				{
					top1 = enque(top1, front2->data);
					front1 = top1;
				}
				else if (front1->next == NULL)
				{
					top1 = enque(top1,front2->data);
					front1->next = top1;
				}
				else
				{
					top1 = enque(top1, front2->data);
				}
				front2 = deque(front2);
				if(front2 == NULL) 	top2 == NULL;	
			}
		}
		else if(choice == 2)
		{
			if(front1 != NULL)
				printf("Number Deleted is : %d \n", front1->data);
			front1 = deque(front1);
			if(front1 == NULL)
				top1 == NULL;
		}
		else if(choice == 3)
		{
			display_queue(front1);
		}
		else if(choice == 4)
		{
			printf("Exiting the program\n");
			exit(0);
		}
	}
	return 0;
}