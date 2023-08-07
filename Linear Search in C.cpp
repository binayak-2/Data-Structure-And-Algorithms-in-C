#include<stdio.h>
int main()
{
	int arr[100], n, i;
	int search, flag=0;
	
	printf("Enter the size of array: ");
	scanf("%d", &n);
	printf("Enter the elements of array: \n");
	for(i=0; i<n; i++)
	{
		printf("[%d]: ",i);
		scanf("%d", &arr[i]);
	}
	printf("\nEnter the element to search: ");
	scanf("%d", &search);
	
	for(i=0; i<n; i++)
	{
		if(arr[i]==search)
		{
			flag=1;
			break;
		}
		else
		{
			flag=0;
		}
	}
	
	if(flag==1)
	{
		printf("%d found at index %d", search, i);
	}
	else
	{
		printf("Element %d not found!", search);
	}
	
}