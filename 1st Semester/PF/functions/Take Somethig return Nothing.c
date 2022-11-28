#include<stdio.h>
void main()
{
	int x,y,z;
	void add(int,int,int);
	printf("Entr three number: ");
	scanf("%d %d %d",&x,&y,&z);
	add(x,y,z); //Actual Arguments
}
void add(int a,int b,int c) //Formal Arguments
{
	int d;
	d=a+b+c;
	printf("Sum is %d",d);
}
