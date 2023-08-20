#include<stdio.h>
int c=0;
void TOH(int, char, char, char);

int main()
{
	int n;
	printf("Enter number of disk: ");
	scanf("%d", &n);
	TOH(n, 'S', 'I', 'D');
	printf("\n%d\n", c);
}
void TOH(int n, char A, char B, char C)
{
	if(n>0)
	{
		TOH(n-1, A, C, B);
		printf("Move disk %d from %c to %c \n", n, A, B);
		c++;
		TOH(n-1, C, B, A);
	}

}