#include<stdio.h>
#include<stdlib.h>
#include<process.h>

struct node{
	
	int data;
	struct node *next;
	
};

struct node *top=NULL;
struct node *head=NULL;


void push(int item)
{
	struct node *newnode=NULL;
	newnode=(struct node *)malloc(sizeof(struct node));
	
	newnode->data=item;
	
	if(head==NULL)
	{
		head=top=newnode;
		newnode->next=NULL;	
		printf("\n\n%d pushed onto stack!",item);
	}
	else
	{
		top->next=newnode;
		newnode->next=NULL;
		top=newnode;
		printf("\n\n%d pushed onto stack!",item);
	}
}

void pop()
{
	struct node *temp=NULL, *hold=NULL;
	temp=head;
	
	if(head==NULL)
	{
		printf("\n\nNothing to pop!");
	}
	
	else if(head==top)
	{
		printf("\n\n%d is popped out from stack!",head->data);
		head=top=NULL;
		free(temp);	
	}
	else
	{
		temp=head;
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
		hold=temp->next;
		temp->next=NULL;
		top=temp;
		printf("\n\n%d is popped out from stack!",hold->data);
		free(hold);
	} 
}
void display()
{
	struct node *temp=NULL;
	temp=head;
	
	if(head==NULL)
	{
		printf(" Nothing to display! ");
	}
	else
	{
		temp=head;
		while(temp!=NULL)
		{
			printf(" %d ", temp->data);
			temp=temp->next;
		}
		
		
	} 
}

int main()
{
	int choice, element;
	
	printf("\n\n----------Stack Implementation From Singly Linked List----------");
	printf("\n1. Push\n2. Pop\n3. Display\n");
	do
	{
	printf("\n\nEnter your choice: ");
	scanf("%d", &choice);
	
	switch(choice)
	{
		case 0:
			exit(0);
			break;
		case 1:
			printf("\n\nEnter element: ");
			scanf("%d", &element);
			push(element);
			break;
		case 2:
			pop();
			break;
		case 3:
			printf("\n[ ");
			display();
			printf(" ] ");
			break;
		default:
			printf("\n\nInvalid Choice!");
			
	}
	}while(choice<4);
	
}


/* 
Output:
----------Stack Implementation From Singly Linked List----------
1. Push
2. Pop
3. Display
Enter your choice: 1
Enter element: 25
25 pushed onto stack!
Enter your choice: 1
Enter element: 50
50 pushed onto stack!
Enter your choice: 1
Enter element: 75
75 pushed onto stack!
Enter your choice: 1
Enter element: 100
100 pushed onto stack!
Enter your choice: 3
[  25  50  75  100  ]
Enter your choice: 2
100 is popped out from stack!
Enter your choice: 2
75 is popped out from stack!
Enter your choice: 2
50 is popped out from stack!
Enter your choice: 3
[  25  ]
Enter your choice: 2
25 is popped out from stack!
Enter your choice: 2
Nothing to pop!
Enter your choice: 3
[  Nothing to display!  ]
Enter your choice: 0
--------------------------------
Process exited after 42.23 seconds with return value 0
Press any key to continue . . .
*/