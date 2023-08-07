#include<stdio.h>
#include<stdlib.h>
#define size 5
int top=-1;
int stack[size];

void display()
{
	int i;
	if(top==-1)
	{
		printf("\n\nThere is nothing to display in Stack!");
		
	}
	else
	{
	printf("\n\n[ ");
	for(i=0; i<top+1; i++)
	{
		printf(" %d ", stack[i]);
	}
	printf("] ");	
	}
	
}
void Push(int a)
{
	if(top==size-1)
	printf("\n\nCannot push %d in stack because it is full!\n", a);
	else
	{
		top++;
		stack[top]=a;
		
	}
}
int Pop()
{
	int b;
	if(top==-1)
	{
		printf("\n\nCannot pop in stack because it is already empty!\n");
		return -1;	
	}
	
	else
	{
		b=stack[top];
		top--;
		stack[top];
		return b;
	}
}

int main()
{
	int choice, n, r;
	printf("-----STACK IMPLEMENTATION FROM ARRAY-----\n");
	printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
	
	
	do
	{
		
	printf("\n\nEnter your choice: ");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:
			printf("\n\nEnter element to push in Stack: ");
			scanf("%d", &n);
			Push(n);
			printf("\n\n%d pushed in Stack! ", n);
			break;
			
		case 2:
			r=Pop();
			printf("\n\n%d popped out from Stack! ", r);
			break;
			
		case 3:
			printf("\n\nThe current Stack is: ");
			display();
			break;
		
		default:
			exit(0);
			break;
	}
}while(choice!=4);
	
}