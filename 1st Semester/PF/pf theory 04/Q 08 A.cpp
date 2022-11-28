#include<stdio.h>
using namespace std;

void diamond(int x)
{
	if (x<=0) return;
	diamond(x-1);
	for(int i=x; i<=x; i--)
	printf("*");
	printf("endl");
}

int main()
{
	int num;
	
	printf("enter an integer");
	scanf("%d", &num);
	diamond(num);
}
