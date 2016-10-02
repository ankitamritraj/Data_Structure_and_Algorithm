#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "function.h"
const float beta = 100;

float **initialize(float **a, int n);
void GaussElemation(float **arr, int n, float *rightmost);

void main()
{
	int n, i, j, size, b;
	double time = clock();
	printf("Enter value of N : ");
	scanf("%d",&n);
	printf("Enter the value of beta(fixed) : ");
	scanf("%d",&b);
	float *lowerdiagonal, *upperdiagonal, *maindiagonal, *rightmost, **arr;
	maindiagonal = (float *) malloc(n*sizeof(float));
	lowerdiagonal = (float *) malloc((n-1)*sizeof(float));
	upperdiagonal = (float *) malloc((n-1)*sizeof(float));
	rightmost = (float *) malloc(n*sizeof(float));
	arr = initialize(arr, n);
	arr[0][0] = maindiagonal[0] = 1;
	arr[0][1] = upperdiagonal[0] = 0;
	for(i=2;i<n;i++)
		arr[0][i] = 0;
	for(i=1;i<n-1;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
				arr[i][j] = maindiagonal[i] = -(2*((n-1)*(n-1)) + beta);		
			else if(j==i+1 || j+1 == i)
				arr[i][j] = upperdiagonal[i] = lowerdiagonal[i-1] = (n-1)*(n-1);  
		}
	}
	for(i=0;i<n-2;i++)
		arr[n-1][i] = 0;
	arr[n-1][n-1] = maindiagonal[n-1] = 1;
	arr[n-1][n-2] = lowerdiagonal[n-2] = -1;

	for(i=0;i<n;i++)
	{
		rightmost[i] = (i==0)?1:0;
	}
	printmatrix(arr, n, rightmost,maindiagonal, upperdiagonal, lowerdiagonal);
	printf("Writing the out in the result files\n");
	GaussElemation(arr,n,rightmost);
	int space = sizeof(arr) * n *n + sizeof(maindiagonal) * 4 * n;
	time = clock() - time;
	time = time/CLOCKS_PER_SEC;
	printf("Time taken is %f sec\n", time);
	printf("Amount of space used is %d bytes\n", space);
	printf("Plotting the required Graphs\n");
}

float **initialize(float **a, int n)
{
	int i;
	a = (float **) malloc(n * sizeof(float *));
	for(i=0;i<n;i++)
	{
		a[i] = (float *) malloc(n * sizeof(float));
	}
	return a;
}

void GaussElemation(float **arr, int n, float *rightmost)
{
	int i,j,k;
	float temp, b, c;
	for(i=1;i<n;i++)
	{
		temp = arr[i-1][i-1];
		b = arr[i][i-1];
		rightmost[i] = rightmost[i] - (rightmost[i-1] * b)/temp;
		for(j=i;j<n;j++)
		{
			c = arr[i][i-1];
			for(k=0;k<n;k++)
			{
				arr[j][k] = arr[j][k] - (arr[i-1][k] * c) / temp;
			}
		}
	}

	float *theta, ans;
	theta = (float *) malloc(n * sizeof(float));

	for(i=n-1;i>=0;i--)
	{
		ans = 0;
		for(j = n-1; j>i ; j--)
		{
			ans += theta[j] * arr[i][j];
		}
		theta[i] = (rightmost[i] - ans) / arr[i][i];
	}

	FILE *fp, *fp1, *fp2;
	fp2 = fopen("error_graph.dat","w");
	fp = fopen("thetavsexacttheta.dat", "w");
	fp1 = fopen("result.dat","w");
	float *thetaexact;
	thetaexact = (float *) malloc(n * sizeof(float));
	
	calcthetaexat(beta, n, thetaexact);

	for(i=0;i<n;i++)
	{
		fprintf(fp, "%.20f  %.23f\n", thetaexact[i], theta[i]);
	}

	float *cummsum = (float *) malloc(n * (sizeof(float)));
	float *thetadiff = (float *) malloc(n * (sizeof(float)));
	// float *error = (float *) malloc(n * (sizeof(float)));
	float error = 0;
	error = calcerror(n, thetadiff, thetaexact, theta, cummsum, error);

	for(i=0;i<n;i++)
	{
		fprintf(fp1, "%d   %.13f   %.13f  %.13f  \n",i+1, (i+1)/(float)(n), theta[i], thetaexact[i]);
	}
	fprintf(fp2, "%d  %.13f\n",n, error );
	if(n == 11)
 		commands111();
 	else if (n == 101)
 		commands1011();
 	else if (n == 501)
 		commands5011();
 	else if( n == 1001)
 		commands10011();
}