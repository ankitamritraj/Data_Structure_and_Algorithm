#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


struct node 
{
	int data;
	struct node *next;
	struct node *previos;
};

void Create(int );
int optimum(int , int );
struct node *remove_node( struct node *delete);



