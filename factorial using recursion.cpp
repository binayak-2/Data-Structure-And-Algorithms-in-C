#include<stdio.h>

int factorial(int n)
{
	if(n==1)
	{
		return 1;
	}
	else
	{
		return n*factorial(n-1);
	}
}
int main()
{
	int n, r;
	
	printf("Enter number: ");
	scanf("%d", &n);
	
	r=factorial(n);
	printf("The factorial of %d is: %d! = %d", n, n, r);
}