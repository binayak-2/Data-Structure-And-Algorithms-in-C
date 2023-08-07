#include<stdio.h>
#include<stdlib.h>
struct Queue{
	
	int front;
	int rear;
	int size;
	int *Qarray; //array
};

void create( struct Queue *q /* variable for accessing structure item */, int size )
{
	q->size = size;
	q->front = q->rear = -1;
	q-> Qarray = (int *)malloc(q->size*sizeof(int)); //creating array dynamically
	printf("\nQueue Created!\n");
}

void enqueue(struct Queue *q, int element)
{
	if(q->rear == q->size-1)
		printf("\nQueue is full!\n");
	else
	{
		q->rear++;
		q->Qarray[q->rear]=element;
		printf("\n%d enqueued!\n", element);
	}
}

int dequeue(struct Queue *q)
{
	printf("\n\n--------------------");
	int delItem=-1;
	if(q->front==q->rear)
		printf("\nQueue is empty!\n");
	else
	{
		q->front++;
		delItem = q->Qarray[q->front];
		printf("\n%d dequeued!\n", delItem);
	}
	printf("--------------------\n");
	return delItem;

}

void printQueue(struct Queue *q)
{
	printf("\nThe Queue is:\n [");
	for(int i=q->front+1; i<=q->rear; i++)
	{
		printf(" %d ", q->Qarray[i]);
	}
	printf("]\n\n");
}

int main()
{
	struct Queue q; //structure variable
	
	create(&q, 5); //calling create function with array size
	enqueue(&q, 20);
	enqueue(&q, 30);
	enqueue(&q, 40);
	printQueue(&q);
	dequeue(&q);
	printQueue(&q);
	dequeue(&q);
	printQueue(&q);
	dequeue(&q);
	printQueue(&q);
	dequeue(&q);
	printQueue(&q);
	
}