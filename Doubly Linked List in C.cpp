#include<stdio.h>
#include<stdlib.h>
#include<process.h>

struct node{
	
	int data;
	struct node *prev;
	struct node *next;
	
};

struct node *first = NULL;
struct node *last = NULL;

void insertAtFirst(int item)
{
	struct node *newnode = NULL;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode -> data = item;
	
	if(first==NULL)
	{
		newnode->prev=newnode->next=NULL;
		first=last=newnode;
	}
	else
	{
		newnode->prev=NULL;
		newnode->next=first;
		first->prev=newnode;
		first=newnode;
	}
	
	printf("\n\nInserted Sucessfully!");
}

void insertAtLast(int item)
{
	struct node *newnode=NULL;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=item;
	
	if(first==NULL)
	{
		newnode->prev=newnode->next=NULL;
		first=last=newnode;
	}
	else
	{
		
		newnode->prev=last;
		newnode->next=NULL;
		last->next=newnode;
		last=newnode;
	}
	
	printf("\n\nInserted Sucessfully!");
}

void deleteFirst()
{
	struct node *temp=NULL;
	temp=first;
	
	if(first==NULL)
	{
		printf("\n\nNoting to delete!");
	}
	else if(first==last)
	{
		first=last=NULL;
	printf("\n\nDeleted Successfuly");
		free(temp);		
	}
	else
	{
		first=first->next;
		printf("\n\nDeleted Successfuly");
		free(temp);
		
	}
	
}

void deleteLast()
{
	struct node *temp=NULL, *hold=NULL;
	temp=first;
	
	if(last==NULL)	
	{
		printf("\n\nNoting to delete!");
	}
	else if(first==last)
	{
		first=last=NULL;
		printf("\n\nDeleted Successfuly");
		free(temp);
	}
	else
	{
		temp=first;
		while(temp->next!=last)
		{
			temp=temp->next;
		}
		hold=temp->next;
		temp->next=NULL;
		last=temp;
		printf("\n\nDeleted Successfuly");
		free(hold);
	}
}

void displayReverse()
{
	struct node *temp=NULL;
	temp=last;
	
	if(last==NULL)
	{
		printf("\n\nList is Empty!");
	}
	else
	{
		printf("\n\n");
		while(temp!=first)
		{
			printf(" %d ", temp->data);
			temp=temp->prev;
		}
		printf(" %d ", first->data);
	}

}
void display()
{
	struct node *temp=NULL;
	temp=first;
	
	if(first==NULL)
	{
		printf("\n\nList is Empty!");
	}
	else
	{
		printf("\n\n");
		while(temp!=last)
		{
			printf(" %d ", temp->data);
			temp=temp->next;
		}
		printf(" %d ", last->data);
	}

}

int main()
{
	int choice, element;
	
		printf("\n\n----------Doubly Linked List----------");
	printf("\n1. Insert At First\n2. Insert At Last\n3. Delete First\n4. Delete Last\n5. Reverse\n6. Display\n");
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
			insertAtFirst(element);
			break;
		case 2:
			printf("\n\nEnter element: ");
			scanf("%d", &element);
			insertAtLast(element);
			break;
		case 3:
			deleteFirst();
			break;
		case 4:
			deleteLast();
			break;
		case 5:
			displayReverse();
			break;
		case 6:
			display();
			break;
		default:
			printf("\n\nInvalid Choice!");
			
	}
	}while(choice<7);
	
}

/* 
Output:
----------Doubly Linked List----------
1. Insert At First
2. Insert At Last
3. Delete First
4. Delete Last
5. Reverse
6. Display
Enter your choice: 6
List is Empty!
Enter your choice: 1
Enter element: 10
Inserted Sucessfully!
Enter your choice: 1
Enter element: 05
Inserted Sucessfully!
Enter your choice: 6
 5  10
Enter your choice: 2
Enter element: 15
Inserted Sucessfully!
Enter your choice: 2
Enter element: 20
Inserted Sucessfully!
Enter your choice: 6
 5  10  15  20
Enter your choice: 5
 20  15  10  5
Enter your choice: 6
 5  10  15  20
Enter your choice: 3
Deleted Successfuly
Enter your choice: 6
 10  15  20
Enter your choice: 4
Deleted Successfuly
Enter your choice: 6
 10  15
Enter your choice: 9
Invalid Choice!
--------------------------------
Process exited after 60.89 seconds with return value 0
Press any key to continue . . .
*/