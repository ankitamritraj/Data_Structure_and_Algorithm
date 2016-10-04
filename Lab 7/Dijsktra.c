#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

#define new(n) (graph *) malloc( n * sizeof(graph))
#define newArray(n) (int *) malloc(n * sizeof(int))

int main(int argc, char const *argv[])
{
	int n;
	int edges;
	int i, j, a, b, weight, currenthostel, totalhostel, *hostelnumber;
	int *distance, *visited, *originaldistance;
	scanf("%d",&n);

	distance = newArray(n);
	visited = newArray(n);
	originaldistance = newArray(n);
	initialize(visited, distance, originaldistance, n);
	
	scanf("%d",&edges);
	graph *adjacencylist , temp;
	adjacencylist = new(n);
	
	Point_To_Null(adjacencylist, n);	
	for(i=0;i<edges;i++)
	{
		scanf("%d %d %d",&a, &b, &weight);
		Add_Edge(adjacencylist, a, b,weight, n);	
	}

	scanf("%d%d",&currenthostel, &totalhostel);
	hostelnumber = newArray(totalhostel);
	
	for(i=0;i<totalhostel;i++)
	{
		scanf("%d",&hostelnumber[i]);
		hostelnumber[i];
	}
	
	distance[currenthostel-1] = originaldistance[currenthostel-1] = 0;

	dijsktra(currenthostel, adjacencylist, distance, visited, n, originaldistance);

	for(i=0;i<totalhostel;i++)
	{
		if(originaldistance[hostelnumber[i]-1] == INF) 
			printf("%d Not Reachable\n", hostelnumber[i]);
		else
			printf("%d %d \n",hostelnumber[i], originaldistance[hostelnumber[i]-1] );
	}
	return 0;
}