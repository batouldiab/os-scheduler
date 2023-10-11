#define Nbr 100
#define M 50
#include<stdio.h>
#include<time.h>

typedef int element;
typedef struct 
{
	element data[M]; /* queue content */
	int front, rear;
} queue;

typedef struct process{
	queue q;
	int at;
}process;