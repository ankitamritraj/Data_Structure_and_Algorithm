#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "function.h"
const float beta = 100;

void Thomas(int n, float *rightmost,float *maindiagonal, float *upperdiagonal, float *lowerdiagonal);

void main()
{
	int n, i, j, size, b;
	double time = clock();
	printf("Enter value of N : ");
	scanf("%d",&n);
	printf("Enter the value of beta(fixed) : ");
	scanf("%d",&b);float *lowerdiagonal, *upperdiagonal, *maindiagonal, *rightmost;
	maindiagonal = (float *) malloc(n*sizeof(float));
	lowerdiagonal = (float *) malloc((n-1)*sizeof(float));
	upperdiagonal = (float *) malloc((n-1)*sizeof(float));
	rightmost = (float *) malloc(n*sizeof(float));
	maindiagonal[0] = 1;
	upperdiagonal[0] = 0;
	for(i=1;i<n-1;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
				{
					maindiagonal[i] = -(2*((n-1)*(n-1)) + beta);		
					printf("%.0f  ", maindiagonal[i]);
				}
			else if(j==i+1 || j+1 == i)
			{
				upperdiagonal[i] = lowerdiagonal[i-1] = (n-1)*(n-1);  
				if(j==i+1)	printf("%.0f  ", upperdiagonal[i]);
				else printf("%.0f", lowerdiagonal[i-1]);
			}
			else printf("0  ");
		}
		printf("\n");
	}
	maindiagonal[n-1] = 1;
	lowerdiagonal[n-2] = -1;
	for(i=0;i<n;i++)
	{
		rightmost[i] = (i==0)?1:0;
	}
	printmatrix_thomas(n, rightmost,maindiagonal, upperdiagonal, lowerdiagonal);
	printf("Writing the output in the result files...\n");
	Thomas(n,rightmost, maindiagonal, upperdiagonal, lowerdiagonal);
	time = clock() - time;
	time = time/CLOCKS_PER_SEC;
	int space = sizeof(maindiagonal) * n * 4;
	// printf("Space = %d\n", space);
	printf("Time taken is %f sec\n", time);
	printf("Amount of space used is %d bytes\n", space);
	printf("Plotting the required Graphs\n");
}

void Thomas(int n, float *rightmost, float *maindiagonal, float *upperdiagonal, float *lowerdiagonal)
{
	
	int i,j;
	for(i=1;i<n;i++)
	{
		rightmost[i] = rightmost[i] - (rightmost[i-1] * lowerdiagonal[i-1]) / maindiagonal[i-1]; 
		maindiagonal[i] = maindiagonal[i] - (upperdiagonal[i-1] * lowerdiagonal[i-1]) / maindiagonal[i-1];
		lowerdiagonal[i-1] = 0;
	}
	
	float *theta, ans;
	theta = (float *) malloc(n * sizeof(float));

	calctheta(n, theta, rightmost, upperdiagonal, maindiagonal);
	
	FILE *fp, *fp1, *fp2;
	fp2= fopen("error_graph.dat", "w");
	fp = fopen("thetavsexacttheta_thomas.dat", "w");
	fp1 = fopen("result_thomas.dat","w");
	float *thetaexact;
	thetaexact = (float *) malloc(n * sizeof(float));
	
	calcthetaexat(beta, n, thetaexact);

	for(i=0;i<n;i++)
	{
		fprintf(fp, "%.20f  %.23f\n", thetaexact[i], theta[i]);
	}

	float *cummsum = (float *) malloc(n * (sizeof(float)));
	float *thetadiff = (float *) malloc(n * (sizeof(float)));
	float error = 0;
	error = calcerror(n, thetadiff, thetaexact, theta, cummsum, error);


	for(i=0;i<n;i++)
	{
		fprintf(fp1, "%d   %.13f   %.13f  %.13f\n",i+1, (i+1)/(float)(n), theta[i], thetaexact[i]);
	}

	fprintf(fp2, "%d  %.15f\n", n, error);

	if(n == 11)
 		commands11();
 	else if (n == 101)
 		commands101();
 	else if (n == 501)
 		commands501();
 	else if( n == 1001)
 		commands1001();
}