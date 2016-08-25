#include <stdio.h>
#include <glib.h>
#include <stdlib.h>

void iterative_Hanoi(int );
void recursive_Hanoi(int , char, char, char);

int main()
{
	int n, choice;
	printf("Enter number of disks : ");
	scanf("%d", &n);
	if(n < 1)
	{
		printf("Invalid input\nExiting the program\n");
		return 0;
	}
	printf("Enter 1 for recursive and 2 for stack based iterative solution : ");
	scanf("%d", &choice);

	if(choice == 1)
		recursive_Hanoi(n,'A','B','C');
	else if(choice == 2)
		iterative_Hanoi(n);
	else
		printf("Invalid input\nExiting the program\n");
	return 0;
}

void iterative_Hanoi(int n)
{
	int i,steps = (1<<n)-1;
	char aux_pole = 'B' , dest_pole = 'C';
	if(n % 2 == 0)						            // if number of disks are even then interchange aux and destination pole
	{
		aux_pole = 'C';
		dest_pole = 'B';
	}
	GSList *source = NULL , *Aux = NULL , *Dest = NULL;
	Aux = g_slist_prepend(Aux ,0);
	Dest = g_slist_prepend(Dest , 0);
	source = g_slist_prepend(source, 0);
	for(i = 1 ; i <=n ; i++)
		source = g_slist_prepend(source, GINT_TO_POINTER(i)); 	
	for(i = 1; i<=steps;i++)
	{
		source->data;
		if((i % 3)==0)								// if i%3==0 move from aux and destination
		{
			if(Aux->data > Dest->data)
			{
				Dest = g_slist_prepend(Dest, Aux->data);
				Aux = g_slist_remove_link(Aux,Aux);
				printf("Move from peg %c to %c\n",aux_pole,dest_pole);

			}
			else
			{
				Aux = g_slist_prepend(Aux, Dest->data);
				Dest = g_slist_remove_link(Dest,Dest);
				printf("Move form peg %c to %c\n",dest_pole,aux_pole);
			}
		}
		else if(i % 3 == 1)							// if i%3==1 move between source and destination
		{
			if(source->data > Dest->data)
			{
				Dest = g_slist_prepend(Dest, source->data);
				source = g_slist_remove_link(source,source);
				printf("Move from peg A to %c\n",dest_pole);
			}
			else
			{
				source = g_slist_prepend(source, Dest->data);
				Dest = g_slist_remove_link(Dest, Dest);
				printf("Move from peg %c to A\n",dest_pole);
			}
		}
		else 
		{
			if(source->data > Aux->data)			// if i%3 == 2 move between source and aux
			{
				Aux = g_slist_prepend(Aux, source->data);
				source = g_slist_remove_link(source,source);
				printf("Move from peg A to %c\n",aux_pole);
			}
			else
			{
				source = g_slist_prepend(source, Aux->data);
				Aux = g_slist_remove_link(Aux, Aux);
				printf("Move from peg %c to A\n",aux_pole);
			}
		}
	}	
}

void recursive_Hanoi(int n, char source, char aux, char dest)
{
	if(n==1)
	{
		printf("Move from peg %c to %c\n",source, dest);
		return ;
	}
	recursive_Hanoi(n-1, source,dest,aux);
	printf("Move peg from %c to %c\n", source, dest);
	recursive_Hanoi(n-1, aux, source, dest);
}