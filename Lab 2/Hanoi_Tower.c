/**********************************************************
Name: Ankit Amrit Raj
Roll: B15107
Purpose: IC250 Assignment 01 - Question 1 - Tower Of Hanoi  
Date: 25/08/2016
**********************************************************/
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
	printf("Total number of steps required to solve this problem are %d\n", (1<<n)-1);
	return 0;
}

void iterative_Hanoi(int n)
{
	int i,steps = (1<<n)-1;
	char aux_pole = 'B' , dest_pole = 'C';
	if(n % 2 == 0)						    					// if number of disks are even then interchange aux and destination pole
	{
		aux_pole = 'C';
		dest_pole = 'B';
	}
	GSList *source = NULL , *Aux = NULL , *Dest = NULL;
	Aux = g_slist_prepend(Aux ,GINT_TO_POINTER(0));
	Dest = g_slist_prepend(Dest , GINT_TO_POINTER(0) );
	source = g_slist_prepend(source, GINT_TO_POINTER(0) );
	for(i = n ; i >=1 ; i--)
		source = g_slist_prepend(source, GINT_TO_POINTER(i));
	for(i = 1; i<=steps;i++)
	{
		if((i % 3)==0)							                           // if i%3==0 move from aux to destination
		{
			if((GPOINTER_TO_INT(Aux->data) < GPOINTER_TO_INT(Dest->data) && Aux->next != NULL) || Dest->next == NULL)
			{
				printf("Move from peg %c to %c \n",aux_pole,dest_pole);
				Dest = g_slist_prepend(Dest, Aux->data);
				Aux = g_slist_remove_link(Aux,Aux);
			}
			else
			{
				printf("Move from peg %c to %c\n",dest_pole,aux_pole);
				Aux = g_slist_prepend(Aux, Dest->data);
				Dest = g_slist_remove_link(Dest,Dest);
			}
		}
		else if(i % 3 == 1)	                      							// if i%3==1 move from source to destination
		{
			if((GPOINTER_TO_INT(source->data) < GPOINTER_TO_INT(Dest->data) && source->next != NULL) || Dest->next == NULL)
			{
				printf("Move from peg A to %c\n",dest_pole);
				Dest = g_slist_prepend(Dest, source->data);
				source = g_slist_remove_link(source,source);
			}
			else
			{
				printf("Move from peg %c to A\n",dest_pole);
				source = g_slist_prepend(source, Dest->data);
				Dest = g_slist_remove_link(Dest, Dest);
			}
		}
		else if (i%3 == 2)  										// if i%3 == 2 move from source to aux
		{
			if((GPOINTER_TO_INT(source->data) < GPOINTER_TO_INT(Aux->data) && source->next != NULL) || Aux->next == NULL )			
			{
				printf("Move from peg A to %c\n",aux_pole);
				Aux = g_slist_prepend(Aux, source->data);
				source = g_slist_remove_link(source,source);
			}
			else
			{
				printf("Move from peg %c to A\n",aux_pole);
				source = g_slist_prepend(source, Aux->data);
				Aux = g_slist_remove_link(Aux, Aux);
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
	printf("Move from peg %c to %c\n", source, dest);
	recursive_Hanoi(n-1, aux, source, dest);
}
