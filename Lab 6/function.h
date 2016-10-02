#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void printmatrix(float **arr, int n, float *rightmost,float *maindiagonal, float *upperdiagonal, float *lowerdiagonal)
{
	printf("\n---------------Matrix Representation------------\n");
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%.0f  ", arr[i][j]);
		printf("\n");
	}
	printf("-----------------Main Diagonal---------------\n");
	for(i=0;i<n;i++)
		printf("%.0f\n", maindiagonal[i] );
	printf("-----------------Lower Diagonal---------------\n");
	for(i=0;i<n-1;i++)
		printf("%.0f\n",lowerdiagonal[i]);
	printf("----------------Upper Diagonal-----------------\n");
	for(i=0;i<n-1;i++)
		printf("%.0f\n",upperdiagonal[i] );
	printf("-------------RightMost Matrix-----------------\n");
	for(i=0;i<n;i++)
	{
		printf("%.0f\n", rightmost[i]);
	}
}

void printmatrix_thomas(int n, float *rightmost,float *maindiagonal, float *upperdiagonal, float *lowerdiagonal)
{
	int i;
	printf("-----------------Main Diagonal---------------\n");
	for(i=0;i<n;i++)
		printf("%.0f\n", maindiagonal[i] );
	printf("-----------------Lower Diagonal---------------\n");
	for(i=0;i<n-1;i++)
		printf("%.0f\n",lowerdiagonal[i]);
	printf("----------------Upper Diagonal-----------------\n");
	for(i=0;i<n-1;i++)
		printf("%.0f\n",upperdiagonal[i] );
	printf("-------------RightMost Matrix-----------------\n");
	for(i=0;i<n;i++)
	{
		printf("%.0f\n", rightmost[i]);
	}
}

void calctheta(int n, float *theta, float *rightmost, float *upperdiagonal, float *maindiagonal)
{
	int i;
	theta[n-1] = rightmost[n-1] / maindiagonal[n-1];
	for(i=n-2;i>=0;i--)
	{
		theta[i] = (rightmost[i] - (upperdiagonal[i] * theta[i+1])) / maindiagonal[i];
	}
}

void calcthetaexat(const int beta, int n, float *thetaexact)
{
	int i;
	for(i=0;i<n;i++)
	{
		thetaexact[i] = cosh(sqrt(beta)*(1-(i+1)/(float)n)) / cosh(sqrt(beta));
	}
}

float calcerror(int n, float *thetadiff, float *thetaexact, float *theta, float *cummsum, float error)
{
	int i;
	error = 0;
	for(i=0;i<n;i++)
	{
		error += (thetaexact[i] - theta[i]) * (thetaexact[i] - theta[i]);
	}
	error = sqrt(error/n);
	return error;
	// cummsum[0] = thetadiff[0];
	// for(i=1;i<n;i++)
	// {
	// 	cummsum[i] = cummsum[i-1] + thetadiff[i]; 
	// }

	// for(i=0;i<n;i++)
	// {
	// 	error[i] = sqrt(cummsum[i]/(i+1));
	// }
}

void plot_graphy(char *commands1[], char *commands2[], char *commands3[], char *commands4[])
{
	FILE *plot1,*plot2,*plot3,*plot4;
	int i;
	plot1 = popen("gnuplot -persistent", "w");
	plot2 = popen("gnuplot -persistent", "w");
	plot3 = popen("gnuplot -persistent", "w");
	plot4 = popen("gnuplot -persistent", "w");
	for(i=0;i<4;i++)
    {
       	fprintf(plot1, "%s\n", commands1[i]);
       	fprintf(plot2, "%s\n", commands2[i]);
       	fprintf(plot3, "%s\n", commands3[i]);
       	fprintf(plot4, "%s\n", commands4[i]);
    }
   
}
void commands11()
{
	char *commands1[] = {"set title \"N vs theta exact Thomas\"", "set xrange[1:12]", "set yrange[0:0.5]", "plot 'result_thomas.dat' using 1:4 with lines", };
	char *commands2[] = {"set title \"X* vs theta Thomas\"", "set xrange[0.09:1.1]", "set yrange[0:1]", "plot 'result_thomas.dat' using 2:3 with lines , 'result_thomas.dat' using 2:4 with lines"};
	char *commands3[] = {"set title \"N vs error Thomas\"", "set xrange[1:1001]", "set yrange[0:0.5]", "plot 'error_graph.dat' using 1:2 "};
	char *commands4[] = {"set title \"theta vs theta exact Thomas\"", "set xrange[0:1]", "set yrange[0:0.5]", "plot 'thetavsexacttheta_thomas.dat' using 2:1 with lines"};
	plot_graphy(commands1, commands2, commands3, commands4);
}

void commands101()
{
	char *commands1[] = {"set title \"N vs theta exact Thomas\"", "set xrange[1:101]", "set yrange[0:1]", "plot 'result_thomas.dat' using 1:4 with lines", };
	char *commands2[] = {"set title \"X* vs theta Thomas\"", "set xrange[0:1.1]", "set yrange[0:1]", "plot 'result_thomas.dat' using 2:3 with lines , 'result_thomas.dat' using 2:4 with lines"};
	char *commands3[] = {"set title \"N vs error Thomas\"", "set xrange[1:1001]", "set yrange[0.02:0.1]", "plot 'error_graph.dat' using 1:2 "};
	char *commands4[] = {"set title \"theta vs theta exact Thomas\"", "set xrange[0:1]", "set yrange[0:1]", "plot 'thetavsexacttheta_thomas.dat' using 2:1 with lines"};
	plot_graphy(commands1, commands2, commands3, commands4);
}

void commands501()
{
	char *commands1[] = {"set title \"N vs theta exact Thomas\"", "set xrange[1:501]", "set yrange[0:1]", "plot 'result_thomas.dat' using 1:4 with lines", };
	char *commands2[] = {"set title \"X* vs theta Thomas\"", "set xrange[0:1.1]", "set yrange[0:1]", "plot 'result_thomas.dat' using 2:3 with lines , 'result_thomas.dat' using 2:4 with lines"};
	char *commands3[] = {"set title \"N vs error Thomas\"", "set xrange[1:1001]", "set yrange[0:0.018]", "plot 'error_graph.dat' using 1:2 "};
	char *commands4[] = {"set title \"theta vs theta exact Thomas\"", "set xrange[0:1]", "set yrange[0:1]", "plot 'thetavsexacttheta_thomas.dat' using 2:1 with lines"};
	plot_graphy(commands1, commands2, commands3, commands4);
}

void commands1001()
{
	char *commands1[] = {"set title \"N vs theta exact Thomas\"", "set xrange[1:1001]", "set yrange[0:1]", "plot 'result_thomas.dat' using 1:4 with lines", };
	char *commands2[] = {"set title \"X* vs theta Thomas\"", "set xrange[0:1.1]", "set yrange[0:1]", "plot 'result_thomas.dat' using 2:3 with lines , 'result_thomas.dat' using 2:4 with lines"};
	char *commands3[] = {"set title \"N vs error Thomas\"", "set xrange[1:1100]", "set yrange[0:0.009]", "plot 'error_graph.dat' using 1:2 "};
	char *commands4[] = {"set title \"theta vs theta exact Thomas\"", "set xrange[0:1]", "set yrange[0:1]", "plot 'thetavsexacttheta_thomas.dat' using 2:1 with lines"};
	plot_graphy(commands1, commands2, commands3, commands4);
}

void commands111()
{
	char *commands1[] = {"set title \"N vs theta exact Gauss Elemination\"", "set xrange[1:12]", "set yrange[0:0.5]", "plot 'result.dat' using 1:4 with lines", };
	char *commands2[] = {"set title \"X* vs theta Gauss Elemination\"", "set xrange[0.09:1.1]", "set yrange[0:1]", "plot 'result.dat' using 2:3 with lines , 'result.dat' using 2:4 with lines"};
	char *commands3[] = {"set title \"N vs error Gauss Elemination\"", "set xrange[1:1001]", "set yrange[0:0.5]", "plot 'error_graph.dat' using 1:2 "};
	char *commands4[] = {"set title \"theta vs theta exact Gauss Elemination\"", "set xrange[0:1]", "set yrange[0:0.5]", "plot 'thetavsexacttheta.dat' using 2:1 with lines"};
	plot_graphy(commands1, commands2, commands3, commands4);
}

void commands1011()
{
	char *commands1[] = {"set title \"N vs theta exact Gauss Elemination\"", "set xrange[1:101]", "set yrange[0:1]", "plot 'result.dat' using 1:4 with lines", };
	char *commands2[] = {"set title \"X* vs theta Gauss Elemination\"", "set xrange[0:1.1]", "set yrange[0:1]", "plot 'result.dat' using 2:3 with lines , 'result.dat' using 2:4 with lines"};
	char *commands3[] = {"set title \"N vs error Gauss Elemination\"", "set xrange[1:1001]", "set yrange[0.02:0.1]", "plot 'error_graph.dat' using 1:2"};
	char *commands4[] = {"set title \"theta vs theta exact Gauss Elemination\"", "set xrange[0:1]", "set yrange[0:1]", "plot 'thetavsexacttheta.dat' using 2:1 with lines"};
	plot_graphy(commands1, commands2, commands3, commands4);
}

void commands5011()
{
	char *commands1[] = {"set title \"N vs theta exact Gauss Elemination\"", "set xrange[1:501]", "set yrange[0:1]", "plot 'result.dat' using 1:4 with lines", };
	char *commands2[] = {"set title \"X* vs theta Gauss Elemination\"", "set xrange[0:1.1]", "set yrange[0:1]", "plot 'result.dat' using 2:3 with lines , 'result.dat' using 2:4 with lines"};
	char *commands3[] = {"set title \"N vs error Gauss Elemination\"", "set xrange[1:1001]", "set yrange[0:0.018]", "plot 'error_graph.dat' using 1:2"};
	char *commands4[] = {"set title \"theta vs theta exact Gauss Elemination\"", "set xrange[0:1]", "set yrange[0:1]", "plot 'thetavsexacttheta.dat' using 2:1 with lines"};
	plot_graphy(commands1, commands2, commands3, commands4);
}

void commands10011()
{
	char *commands1[] = {"set title \"N vs theta exact Gauss Elemination\"", "set xrange[1:1001]", "set yrange[0:1]", "plot 'result.dat' using 1:4 with lines", };
	char *commands2[] = {"set title \"X* vs theta Gauss Elemination\"", "set xrange[0:1.1]", "set yrange[0:1]", "plot 'result.dat' using 2:3 with lines , 'result.dat' using 2:4 with lines"};
	char *commands3[] = {"set title \"N vs error Gauss Elemination\"", "set xrange[1:1100]", "set yrange[0:0.009]", "plot 'error_graph.dat' using 1:2"};
	char *commands4[] = {"set title \"theta vs theta exact Gauss Elemination\"", "set xrange[0:1]", "set yrange[0:1]", "plot 'thetavsexacttheta.dat' using 2:1 with lines"};
	plot_graphy(commands1, commands2, commands3, commands4);
}