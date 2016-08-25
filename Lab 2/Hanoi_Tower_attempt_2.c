#include <stdio.h>
#include <glib.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int n;
	printf("Enter value of n : ");
	scanf("%d",&n);
	int steps = pow(2,n) - 1;
	printf("%d\n", steps);
	int i;
	GSList *source = NULL , *Aux = NULL , *Dest = NULL;
	int x = 0;
	Aux = g_slist_prepend(Aux ,GINT_TO_POINTER(x));
	Dest = g_slist_prepend(Dest , GINT_TO_POINTER(x));
	source = g_slist_prepend(source, GINT_TO_POINTER(x));
	// int *da;
	// da = Aux->data;
	// printf("%d\n", * da);
	for(i = 1 ; i <=n ; i++)
	{
		source = g_slist_prepend(source, GINT_TO_POINTER(i));
	}
	int *a;
	int value;
	for(i = 1; i<=steps;i++)
	{
		source->data;
		// printf("%d\n", *a);
		// value = *a; 
		if((i % 3)==0)
		// {
		// }
		{
			printf("hello1  %d \n",i);
			if(Aux->data > Dest->data)
			{
				Dest = g_slist_prepend(Dest, Aux->data);
				Aux = g_slist_remove(Aux,Aux->data);
				printf("Move from peg B to C\n");

			}
			else
			{
				Aux = g_slist_prepend(Aux, Dest->data);
				Dest = g_slist_remove_link(Dest,Dest);
				printf("Move form peg C to B\n");
			}
		}
		else if(i % 3 == 1)
		{
			printf("hello2  %d \n",i);
			if(source->data > Dest->data)
			{
				Dest = g_slist_prepend(Dest, source->data);
				source = g_slist_remove_link(source,source);
				printf("Move from peg A to C\n");
			}
			else
			{
				source = g_slist_prepend(source, Dest->data);
				Dest = g_slist_remove_link(Dest, Dest);
				printf("Move from peg C to A\n");
			}
		}
		else 
		{
			printf("hello3  %d \n",i);
			if(source->data > Aux->data)
			{
				Aux = g_slist_prepend(Aux, source->data);
				source = g_slist_remove_link(source,source);
				printf("Move from peg A to B\n");
			}
			else
			{
				source = g_slist_prepend(source, Aux->data);
				Aux = g_slist_remove_link(Aux, Aux);
				printf("Move from peg B to A\n");
			}
		}

		// free(source);
		// free(Dest);
		// free(Aux);
		// source = source -> next;
	}
	return 0;	
}
