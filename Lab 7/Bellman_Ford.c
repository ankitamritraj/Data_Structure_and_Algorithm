#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

#define new(n) (graph *) malloc( n * sizeof(graph))
#define newArray(n) (int *) malloc(n * sizeof(int))


void bellman_ford(graph *adjacencylist, int startnode, int *visited, int *distance, int n ,int edges)
{
	int i, j;
	struct List *temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n;j++)
		{
			temp = adjacencylist[j].next;
			while(temp != NULL)
			{
				if(distance[temp->data] > distance[j] + temp->weight)
				{
					distance[temp->data] = distance[j] + temp->weight;	
				}
				temp = temp->next;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int n;
	int edges;
	int i, j, a, b, weight;
	int *distance, *visited;
	scanf("%d",&n);

	distance = newArray(n);
	visited = newArray(n);
	initialize_array(visited, distance, n);
	
	scanf("%d",&edges);
	graph *adjacencylist , temp;
	adjacencylist = new(n);
	
	Point_To_Null(adjacencylist, n);	
	for(i=0;i<edges;i++)
	{
		scanf("%d %d %d",&a, &b, &weight);
		Add_Edge(adjacencylist, a, b,weight, n);	
	}

	distance[0] = 0;
	bellman_ford(adjacencylist,0,visited,distance,n,edges);

	for(i=0;i<n;i++)
	{
		printf("1 to %d = %d \n", i+1 , distance[i]);
	}
	return 0;
}