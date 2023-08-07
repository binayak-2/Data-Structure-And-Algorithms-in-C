#include<stdio.h>
#include<stdlib.h>
#include<process.h>

struct node
{
	int data;
	struct node *next;
};

struct node *front=NULL;
struct node *rear=NULL;

void enqueue(int item)
{
	struct node *newnode=NULL;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=item;
	
	if(front==NULL)
	{
		newnode->next=NULL;
		front=rear=newnode;	
		printf("\n\n%d enqueued onto queue!",item);
	}
	else
	{
		rear->next=newnode;
		newnode->next=NULL;
		rear=newnode;
		printf("\n\n%d enqueued onto queue!",item);
	}
}
void dequeue()
{
	struct node *temp=NULL;
	temp=front;
	if(front==NULL)
	{
		printf("\n\nNothing to dequeue! ");
	}
	else if(front==rear)
	{
		front=rear=NULL;
		printf("\n\n%d dequeued from queue!",temp->data);
		free(temp);
	}
	else
	{
		temp=front;
		front=temp->next;
		temp->next=NULL;
		printf("\n\n%d dequeued from queue!",temp->data);
		free(temp);
	}
}

void display()
{
	struct node *temp=NULL;
	temp=front;
	if(front==NULL)
	{
		printf(" Nothing to display! ");
	}
	else
	{
		while(temp!=rear)
		{
			printf(" %d ",temp->data);
			temp=temp->next;
		}
		printf(" %d ",rear->data);
	}
}
int main()
{
	int choice, element;
	
	printf("\n\n----------Queue Implementation From Doubly Linked List----------");
	printf("\n1. Enqueue\n2. Dequeue\n3. Display\n");
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
			enqueue(element);
			break;
		case 2:
			dequeue();
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
----------Queue Implementation From Doubly Linked List----------
1. Enqueue
2. Dequeue
3. Display
Enter your choice: 1
Enter element: 20
20 enqueued onto queue!
Enter your choice: 1
Enter element: 30
30 enqueued onto queue!
Enter your choice: 1
Enter element: 40
40 enqueued onto queue!
Enter your choice: 1
Enter element: 50
50 enqueued onto queue!
Enter your choice: 3
[  20  30  40  50  ]
Enter your choice: 2
20 dequeued from queue!
Enter your choice: 3
[  30  40  50  ]
Enter your choice: 2
30 dequeued from queue!
Enter your choice: 3
[  40  50  ]
Enter your choice: 0
--------------------------------
Process exited after 40.11 seconds with return value 0
Press any key to continue . . .
*/