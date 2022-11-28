#include <stdio.h>
int main()
{
	int var = 50;
	int *p = &var;
	int ** pp = &p;
	int ***ppp = &pp; 
	
	printf("Address of var is %d\n", var);
	printf("Address of p is %d\n", *p);
	printf("Address of pp is %d\n", **pp);
	printf("Value stored in p is %d\n", ***ppp);
	
}
