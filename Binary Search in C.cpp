#include<stdio.h>

void BinarySearch(int list[], int n, int key)
{
	int low = 0, high = n-1, mid;	
	while(low<=high)
	{
		mid = (low+high)/2;
		if(list[mid] == key){
			printf("Search successful. Key found at index %d.", mid);
			break;
		} else if(key>list[mid]){
			low = mid+1;
		} else{
			high = mid-1;
		}
	}
	if(low>high){
		printf("Search unsuccessful. Key not found in list");
	}
}
int main()
{
	int n, a[100], i, key;
	printf("Enter the no. of data items: ");
	scanf("%d", &n);
	printf("Enter the data items in sorted form:\n ");
	
	for(i=0; i<n; i++)
	{
		printf("[%d]: ",i);
		scanf("%d", &a[i]);
	}
	
	printf("Enter searched item: ");
	scanf("%d", &key);
	
	BinarySearch(a, n, key);
	
}