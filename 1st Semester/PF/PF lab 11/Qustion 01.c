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
	printf("The value stored in p is :  %d", *(int *)p);
	printf("\nEnter a character: ");
	p = &c;
	scanf(" %c", p);
	printf("\nThe value stored in p is :  %c", *(char *)p);
	printf("\nEnter an float value : ");
	p = &b;
	scanf(" %f", p);
	printf("\nThe value stored in p is :  %.2f", *(float *)p);
	
}
