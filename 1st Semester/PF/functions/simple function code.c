#include<stdio.h>
add()
{
	int a, b, c;
	printf("Enter to number:");
	scanf("%d\n%d", &a, &b);
	c=a+b;
	printf("\nSum of number is %d\n",c);
}
subs()
{
	int a, b, d;
	printf("Enter to number:");
	scanf("%d\n%d", &a, &b);
	d=a-b;
	printf("\nSubtraction of number is %d\n",d);
}
mul()
{
	int a, b, e;
	printf("Enter to number:");
	scanf("%d\n%d", &a, &b);
	e=a*b;
	printf("\nMul of number is %d\n",e);
}
div()
{
	int a, b, f;
	printf("Enter to number:");
	scanf("%d\n%d", &a, &b);
	f=a/b;
	printf("\nDiv of number is %d\n",f);
}
main()
{
	add();
	subs();
	mul();
	div();
}
