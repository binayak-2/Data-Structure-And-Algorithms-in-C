#include<stdio.h>
void InsertionSort(int a[], int n)
{
  int i, j, temp=0;
  for(i=1; i<n; i++)
  {
    temp=a[i];
    j=i-1;
    while(j>=0 && a[j]>temp)
    {
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=temp;
  }

printf("\nAfter Sorting the Array using Insertion Sort: \n");
	
	for(i=0; i<n; i++)
	{
		printf(" %d ", a[i]);
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
	
	InsertionSort(num, n);
		
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