#include<stdio.h>

void bubbleSort(int b[], int n)
{
	int i, j, temp;
	
	for(i=0; i<n-1; i++)
	{
		for(j=0; j<n-1-i; j++)
		{
			if(b[j]>b[j+1])
			{
				temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
			}
		}
	}
	
	printf("\nAfter Sorting the Array using Bubble Sort: \n");
	
	for(i=0; i<n; i++)
	{
		printf(" %d ", b[i]);
	}
	
}
int main()
{
	int num[200];
	int i, n;
	
	printf("Enter no. of elements: ");
	scanf("%d", &n);
	
	printf("Enter elements: ");
	
	for(i=0; i<n; i++)
	{
		printf("\n[%d]: ", i+1);
		scanf("%d", &num[i]);
	}
	
	bubbleSort(num, n);
		
}

/*
Output:
Enter no. of elements: 5
Enter elements: 
 [1]: 20
 [2]: 4
 [3]: 78
 [4]: 32
 [5]: 94
 After Sorting the Array using Bubble Sort: 
 4  20  32  78  94 
*/