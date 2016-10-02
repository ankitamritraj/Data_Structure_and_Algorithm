#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//srand(time(NULL));

int **maker(int n, int m)
{
	int **arr, i;
	arr = (int **) malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
	{
		arr[i] = (int *) malloc(m*sizeof(int));
	}	
	int j;
   	srand(time(NULL));
   	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			arr[i][j] = rand()%100000;
		}
		// printf("\n");
	}
	return arr;
}

void writer(int **arr, int n, int m, char *filename)
{
	int i,j;
	FILE *fp;
	fp = fopen(filename, "w");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			fprintf(fp, "%d  ", arr[i][j]);
		}
		fprintf(fp,"\n");
	}
}

void printdelete(int **arr, int n, int m, char *filename)
{
	int i = 0,j,value;
	FILE *fp;
	fp = fopen(filename, "r");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%d  ", arr[i][j]);
		}
		printf("\n");
	}
	//free(arr);
}

void main()
{
	int n, m;
	printf("Enter rows : \n");
	scanf("%d",&n);
	printf("Enter coloumn : \n");
	scanf("%d",&m);

	int **arr, i;
	arr = maker(n,m);
	char filename[100];
	printf("Enter file name to write : ");
	char ch;
	ch = getchar();
	fgets(filename, sizeof(filename), stdin);
	writer(arr,n,m,filename);
	printdelete(arr,n,m,filename);
	
}