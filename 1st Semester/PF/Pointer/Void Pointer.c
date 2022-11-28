#include<stdio.h>
main()
{
	int ivar=10;
	//int iivar=11;
	float fvar=12.23;
	char a='z';
	void *p;
	//void *k;
	//k=&iivar;
	
	p=&ivar;
	//p=&a;
	printf("Address of ivar is %d\n",(int *)p);
	p=&fvar;
	printf("Address of ivar is %d",(int *)p);
//	printf("\nAddress of i var is %c",(char *)p);
	//printf("Address of ivar is %d\n",(int *)k);
}
