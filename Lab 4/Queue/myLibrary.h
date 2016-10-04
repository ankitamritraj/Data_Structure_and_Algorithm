#include <stdio.h>
#include <stdlib.h>

struct node 
{
	float data;
	struct node *next;
};

void Enque() ; 
void Deque() ;
void Display();
void push(struct node *pushMe) ;
void pop_stackTwo();
