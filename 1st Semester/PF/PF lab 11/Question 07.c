#include <stdio.h>

int main()
{

	
	void *p;
	int a;
	float b;
	char c;
	printf("Enter an integer value : ");
	p = &a;
	scanf(" %d", p);
	printf("The value stored in p is :  %d\nThe address is : %.2p\n", *(int *)p, p);
	printf("\nEnter a character: ");
	p = &c;
	scanf(" %c", p);
	printf("\nThe value stored in p is :  %c\nThe address is : %.2p\n", *(char *)p, p);
	printf("\nEnter an float value : ");
	p = &b;
	scanf(" %f", p);
	printf("\nThe value stored in p is :  %f\nThe address is : %.2p\n", *(float *)p, p);
	
}
