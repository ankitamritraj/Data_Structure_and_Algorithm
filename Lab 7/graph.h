#include <stdio.h>
#include <stdlib.h>

#define INF 100000000

// 0 indexing 

struct List {
	int data;
	int weight;
	struct List *next;
};

struct Graph {
	struct List *next;
};

typedef struct Graph graph;

void Point_To_Null(graph *adjacencylist, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		(adjacencylist[i]).next = NULL;
	}
}

void Show_Graph(graph *adjacencylist, int n)
{
	int i;
	struct List *temp;
	for(i=0;i<n;i++)
	{
		if(adjacencylist[i].next != NULL)
		{
			temp = adjacencylist[i].next;
			printf("Node %d : ",i+1);
			while(temp!= NULL)
			{
				printf("%d ", (temp)->data + 1);
				temp = (temp)->next;
			}
			printf("\n");
		}
	}	
}

void Add_Edge( graph *adjacencylist, int a, int b, int weight, int n)
{
	struct List *temp;
	temp = (struct List *) malloc(sizeof(struct List));
	temp->data = b-1;
	temp->weight = weight;
	temp->next = (adjacencylist[a-1]).next;
	(adjacencylist[a-1]).next = temp;
}

int Extract_Min(int *distance, int n, int *originaldistance)
{
	int i, min = INF + 1, pos = -1;
	for(i=0;i<n;i++)
	{
		if(distance[i] < min)
		{
			pos = i;
			min = distance[i];
		}
	}
	if (min!=INF + 1)
	{
		originaldistance[pos] = distance[pos];
		distance[pos] = INF + 2;
	}
	return pos;
}

void dijsktra(int node, graph *adjacencylist,  int *distance, int *visited, int n, int *originaldistance)
{
	int i, pos = 0;
	struct List *temp;
	// printf("hello\n");
	while(pos != -1)
	{
		pos = Extract_Min(distance, n, originaldistance);
		if(pos == -1) break;
		visited[pos] = 1;
		if(adjacencylist[pos].next != NULL)
		{
			temp = adjacencylist[pos].next;
			while(temp != NULL)
			{
				if(visited[temp->data] != 1)
				{
					if(originaldistance[temp->data] > originaldistance[pos] + temp->weight)
					{
						originaldistance[temp->data] = originaldistance[pos] + temp->weight;
						distance[temp->data] = originaldistance[temp->data];
					}
				}
				temp = temp->next;
			}
		}
	}
}

void initialize(int *visited, int *distance, int *originaldistance, int n)
{
	int i; 
	for(i=0;i<n;i++)
	{
		visited[i] = 0;
		distance[i] = INF;
		originaldistance[i] = INF;
	}
}

void initialize_array(int *visited, int *distance, int n)
{
	int i; 
	for(i=0;i<n;i++)
	{
		visited[i] = 0;
		distance[i] = INF;
	}
}