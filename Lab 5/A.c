#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swapPointers(int *a, int *b);
void printPointerValue(int *a);
int Compare_num(int *m, int *n);
int compareStrings(char *s, char *s2);
int countTillThisNum(int *n);

void main()
{
	int choice=1;
	while(1)
	{
		printf("1.Swap Pointers\n2.Print Pointer value\n3.Compare_num\n4.Compare Strings\n5.Count till n\nEnter Choice : ");
		scanf("%d",&choice);
		if(choice == 1)
		{
			int a,b;
			printf("Enter 1st number : ");
			scanf("%d",&a);
			printf("Enter 2nd number : ");
			scanf("%d",&b);
			swapPointers(&a,&b);
		}
		else if(choice == 2)
		{
			int a=3;
			printPointerValue(&a);
		}
		else if(choice == 3)
		{
			int a,b,value;
			printf("Enter 1st number : ");
			scanf("%d",&a);
			printf("Enter 2nd number : ");
			scanf("%d",&b);
			value = Compare_num(&a,&b);
			printf("Value returned by the function : %d\n", value);
			printf("Larger value is : %d \n", value==0?b:a);
		}
		else if(choice == 4)
		{
			char str1[100], str2[100];
			char ch;
			printf("Enter String 1 : ");
			ch = getc(stdin);
			fgets(str1,sizeof(str1),stdin);
			printf("Enter String 2 : ");
			fgets(str2,sizeof(str2),stdin);
			int value;
			value = compareStrings(str1,str2);
			printf("Returned value is : %d \n",value );
			printf("Lexicographically greater string is : %s \n", value==0?str2:str1);
			
		}
		else if(choice == 5)
		{
			int num;
			printf("Enter number till which to count : ");
			scanf("%d",&num);
			countTillThisNum(&num);
			printf("\n");
		}
		else
		{
			printf("Invalid Input \nExiting the program\n");
			exit(0);
		}
	}
}
void swapPointers(int *a, int *b)
{
	printf("Before Swapping : A = %d and B = %d \n", *a, *b);
	*a = *a+*b;
	*b = *a-*b;
	*a=*a-*b;
	printf("After Swapping : A = %d  and B = %d \n",*a,*b );
}

void printPointerValue(int *a)
{
	printf("Pointer's value is : %d \n",*a );
}

int Compare_num(int *a, int *b)
{
	return (*a > *b ?1:0);
}

int compareStrings(char *s1, char *s2)
{
	int value = 0, i = 0, flag = 0;
	while(s1[i] != '\n' && s2[i] != '\n')
	{
		if(s1[i] > s2[i])
		{
			flag =1;
			value = 1;
			break;
		}
		i++;
	}

	if(flag!=1)
	{
		if(s1[i] != '\n') value = 1;
		else if(s2[i] != '\n') value = 0;
	}
	return value;
}

int countTillThisNum(int *num)
{
	if(*num == 1)
	{
		printf("%d  ",*num);
	}
	else
	{
		(*num)--;
		countTillThisNum(num);
		(*num)++;
		printf("%d  ",*num);
	}
}