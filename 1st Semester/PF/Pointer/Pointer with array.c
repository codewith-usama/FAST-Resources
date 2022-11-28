#include<stdio.h>
int main()
{
	char ch[]="abcde";
	char *p;
	p=ch;
	
	printf("Address at ch is %d\n",p);
	printf("Value at ch is %c\n",*p);
	
	p+=3;
	*p = 1;
	printf("Address at ch is %d\n",p);
	printf("Value at ch is %c\n",*p);
	
	
	
	
	
	
	
	
	
//	int arr[]={10, 20, 30, 40, 50};
//	int *parr;
//	parr=arr;
//	int i;
//	for(i=0;i<=4;i++)
//	{
//		printf("Address of arr is %d\n", parr);
//		printf("Value of arr is %d\n", *parr);
//		parr++;
//	}
//	printf("Address of arr is %d\n", parr);
//	printf("Value of arr is %d\n", *parr);
//	parr+=10;
//	printf("Address of arr is %d\n", parr);
//	printf("Value of arr is %d\n", *parr);
	
}
