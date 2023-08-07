#include<stdio.h>
#include<stdlib.h>
#include<process.h>

struct node{
	int data;
	struct node *next;
};

struct node *first=NULL;
struct node *last=NULL;

void insertAtBeginning(int item)
{
	struct node *newnode=NULL;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=item;
	
	//if there is no any node
	if(first==NULL)
	{
		newnode->next=newnode;
		first=newnode;
		last=newnode;
		printf("\nInserted Successfully!\n");
	}
	else
	{
		newnode->next=first;
		first=newnode;
		last->next=newnode;
		printf("\nInserted Successfully!\n");
	}
	
}

void insertAtLast(int item)
{
	struct node *newnode=NULL;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=item;
	
	//if there is no any node previously
	if(first==NULL)
	{
		newnode->next=newnode;
		first=newnode;
		last=newnode;
		printf("\nInserted Successfully!\n");
	}
	//if there are nodes then
	else
	{
		last->next=newnode;
		last=newnode;
		newnode->next=first;
		printf("\nInserted Successfully!\n");
	}
}

void deleteFirst()
{
	struct node *temp;
	temp=first;
	
	//if the list is empty
	if(first==NULL)
	{
		printf("\nNothing to delete! List is empty.");
	}
	//if there is only one node
	else if(first==last)
	{
		first=last=NULL;
		free(temp);
		printf("\nDeleted Successfully!");
	}
	//if there are more than one node
	else
	{
		first=first->next;
		last->next=first;
		free(temp);
		printf("\nDeleted Successfully!");
	}
}

void deleteLast()
{
	struct node *temp=NULL, *hold=NULL;
	temp=last;
	hold=last;
	if(first==NULL)
	{
		printf("\nNothing to delete! List is empty.");
	}
	else if(first==last)
	{
		first=last=NULL;
		free(temp);
		printf("\nDeleted Successfully!");
	}
	else
	{
		while(temp->next!=last)
		{
			temp=temp->next;
		}
		temp->next=first;
		last=temp;
		free(hold);
		
	}
}

void display()
{
	struct node *temp;
	temp=first;
	
	if(first==NULL)
	{
		printf("\nNothing to display!");
		
	}
	else
	{
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
	
	do
	{
	printf("\n*****-----Circular Linked List-----*****\n");
	printf("1. Insert At Beginning\n2. Insert At Last\n3. Delete First\n4. Delete Last\n5. Display\n\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);
	
	switch(choice)
	{
		case 0:
			exit(0);
			break;
			
		case 1:
			printf("\nEnter element: ");
			scanf("%d", &element);
			insertAtBeginning(element);
			break;
		
		case 2:
			printf("\nEnter element: ");
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
			display();
			break;
			
		default:
			exit(0);		
	}
	}while(choice<6);

}