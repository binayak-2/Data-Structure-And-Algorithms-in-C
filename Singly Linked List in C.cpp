#include<stdio.h>
#include<stdlib.h>
#include<process.h>

//creating a node

struct Node{
	
	int data;
	struct Node *next;
};

struct Node *first=NULL;
struct Node *last=NULL;

void insertAtFirst(int item)
{
	struct Node *NewNode = NULL;
	NewNode=(struct Node *)malloc(sizeof(struct Node));
	NewNode->data=item;
	
	//if there is no any node
	if(first==NULL)
	{
		NewNode->next=NULL;
		first=last=NewNode;	
	}
	else
	{
		NewNode->next=first; //connect to previously first node
		first=NewNode;
	}
		printf("\nInserted Successfully!\n");
}

void insertAtLast(int item)
{
	struct Node *NewNode=NULL;
	NewNode=(struct Node *)malloc(sizeof(struct Node));
	NewNode->data=item;
	NewNode->next=NULL;
	
	if(first==NULL)
	{
		
		first=last=NewNode;
	}
	else
	{
		last->next=NewNode;
		last=NewNode;
	}
	printf("Inserted Successfully!\n");	
}
void insertAtPos(int pos, int item)
{
	int i;
	struct Node *temp=NULL;
	struct Node *NewNode=NULL;
	NewNode=(struct Node *)malloc(sizeof(struct Node));
	NewNode->data=item;
	if(first==NULL)
	{
		first=last=NewNode;
	}
	else
	{
		temp=first;
		for(i=1; i<pos-1; i++)
		{
			temp=temp->next;
		}
		NewNode->next=temp->next;
		temp->next=NewNode;
	}
}
void deleteFirst()
{
	struct Node *temp=NULL;
	if(first==NULL)
	{
		printf("\nNothing to delete\n");
	}
	else
	{
		temp=first;
		first=first->next;
		free(temp);
	}
}
void deleteLast()
{
	struct Node *temp, *hold;
	if(first==NULL)
	{
		printf("\nNothing to delete\n");
	}
	else if(first->next==NULL)
	{
		temp=first;
		first=NULL;
		free(temp);
	}
	else
	{
		temp=first;
		while(temp->next->next!=NULL)
		{
			temp=temp->next;	
		}
		hold=temp->next;
		temp->next=NULL;
		free(hold);
	}
}

void deleteNth(int pos)
{
	struct Node *temp, *hold;
	int i;
	if(first==NULL)
	{
		printf("Nothing to delete!");
	}
	else
	{
		temp=first;
		for(i=1; i<pos-1; i++)
		{
			temp=temp->next;
		}
		hold=temp->next;
		temp->next=hold->next;
		free(hold);
	}
}
void countNode()
{
	int c=0;
	struct Node *temp;
	temp=first;
	while(temp!=NULL)
	{
		c++;
		temp=temp->next;
	}
	printf("No. of nodes: %d",c);
}

void display()
{
	struct Node *temp;
	temp=first; //we should not change first if not then we could loose the nodes
	if(temp==NULL)
	{
		printf("\nEmpty Linked List");
		
	}
	else
	{
		while(temp!=NULL)
		{
			printf(" %d ", temp->data);
			temp=temp->next;
		}	
	}
	
}


int main()
{
	int choice, pos;
	int item;
	do{
		printf("\n*****-----LINKED LIST MENU-----*****\n");
		printf("\n1. Insert At First \n2. Insert At Last \n3. Insert At Specified Position");
		printf("\n4. Delete First \n5. Delete Last \n7. Delete from Specific Position");
		printf("\n8. Count Node \n9. Display");
		printf("\n\nEnter your choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 0:
				exit(0);
				break;
			case 1:
				printf("Enter the element: ");
				scanf("%d",&item);
				insertAtFirst(item);
				break;
			case 2:
				printf("Enter the element: ");
				scanf("%d", &item);
				insertAtLast(item);
				break;
			case 3:
				printf("Enter the Position: ");
				scanf("%d", &pos);
				printf("Enter the element: ");
				scanf("%d", &item);
				insertAtPos(pos, item);
				break;
			case 4:
				deleteFirst();
				break;
			case 5:
				deleteLast();
				break;
			case 7:
				printf("Enter the Position: ");
				scanf("%d", &pos);
				deleteNth(pos);
				break;
			case 8:
				countNode();
				break;
			case 9:
				printf("\n");
				display();
				printf("\n");
				break;
			
			default:
				exit(0);
		}	
		
	}while(choice<10);
}
