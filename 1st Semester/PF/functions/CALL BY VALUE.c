#include <stdio.h>
main()
{
	int x=10;
	int y=20;
	//before function call
	printf("Value of x = %d\nValue of y = %d\n",x,y);
	printf("\n\nValue of of Y = %d\n\n",func(&x,&y));
	//AFTER function call
	printf("Value of x = %d\nValue of y = %d\n",x,y);

}
int func(int *x,int *y)
{
	*x = *x +10;
	*y = *y +10;
	*y =99;
	return *y;
}
