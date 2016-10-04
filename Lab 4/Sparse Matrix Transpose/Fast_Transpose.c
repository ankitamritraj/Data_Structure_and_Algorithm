#include "all_Library.h"

int main(int argc, char const *argv[])
{
	int n, m, i, j, l=1;
	printf("Enter number of rows : ");
	scanf("%d",&n);
	printf("\nEnter number of columns : ");
	scanf("%d",&m);

	int *arr[n+1] , count = 0;
	for(i=0;i<= m;i++)
	{
		arr[i] = (int *) malloc((m+1) * sizeof(int));
	}

	for(i = 1; i <= n; i++)
	{
		for(j=1;j <= m;j++)
		{
			scanf("%d",&arr[i][j]);
			if(arr[i][j]) count++;
			// printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	int *x, *y, *value, *freq, *c_freq, *check, *x_transpose, *y_transpose, *value_transpose;
	x = (int *) malloc ((count+1) * sizeof(int));
	y = (int *) malloc ((count+1) * sizeof(int));
	x_transpose = (int *) malloc ((count+1) * sizeof(int));
	y_transpose = (int *) malloc ((count+1) * sizeof(int));
	value = (int *) malloc ((count+1) * sizeof(int));
	value_transpose = (int *) malloc ((count+1) * sizeof(int));
	freq = (int *) malloc ((m+1) * sizeof(int));
	c_freq = (int *) malloc ((m+1) * sizeof(int));
	check = (int *) malloc ((m+1) * sizeof(int));

	memset(freq,0,count+1 * sizeof(int));
	memset(check, 0 , count+1 * sizeof(int));

	for(i = 1; i <= n; i++)
	{
		for(j=1 ;j <= m;j++)
		{
			if(arr[i][j])
			{
				x[l] = i;
				y[l] = j;
				value[l++] = arr[i][j];
				freq[j]++;
			}
		}
	}

	c_freq[0] = 0;
	for(i = 1; i <= m; i++)
	{
		c_freq[i] = c_freq[i-1] + freq[i]; 
	}


	for(i=1;i<=count;i++)
	{
		check[y[i]]++;
		y_transpose[c_freq[y[i]-1] + check[y[i]]] = x[i];
		x_transpose[c_freq[y[i]-1] + check[y[i]]] = y[i];
		value_transpose[c_freq[y[i]-1] + check[y[i]]] = value[i];
	}

	printf("Transposed Matrix is : \n");

	for(i=1;i<=count;i++)
	{
		printf("%d      %d      %d\n", x_transpose[i], y_transpose[i], value_transpose[i]);
	}


	return 0;
}
