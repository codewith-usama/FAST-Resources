#include<stdio.h>
int add()
{
	int a,b,c;
	printf("Enter two numbers: ");
	scanf("%d %d",&a,&b);
	c=a+b;
	return(c);
}
void main()
{
	int d; 
	d=add();
	printf("Sum is %d",d);
}
