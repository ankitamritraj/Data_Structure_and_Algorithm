#include <stdio.h>
#include <glib.h>
#include <math.h>

int main()
{
	int n;
	printf("Enter value of n : ");
	scanf("%d",&n);
	int steps = pow(2,n) - 1;
	int i;
	GSList *source = NULL , *Aux = NULL , *Dest = NULL;
	Aux = g_slist_prepend(Aux , 0);
	Dest = g_slist_prepend(Dest , 0);

	for(i = 1 ; i <= steps ; i++)
	{
		source = g_slist_prepend(source, GINT_TO_POINTER(i));
	}
	int a,b,c;
	while(source!=NULL)
	{
		if(source->data % 3 == 0)
		{
			if(Aux->data > Dest->data)
			{
				Dest = g_slist_prepend(Dest, Aux->data);
				Aux = g_slist_remove_link(Aux,Aux);
				printf("Move from peg B to C\n");

			}
			else
			{
				Aux = g_slist_prepend(Aux, Dest->data);
				Dest = g_slist_remove_link(Dest,Dest);
				printf("Move form peg C to B\n");
			}
		}
		else if(source->data % GINT_TO_POINTER(3) == 1)
		{
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
		else(source->data % 3 == 2)
		{
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
		source = source -> next;
	}
	return 0;	
}
