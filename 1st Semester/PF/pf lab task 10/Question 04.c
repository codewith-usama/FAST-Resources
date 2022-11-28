#include<stdio.h>
struct employee
{
	int array[10];
};
int main()
{
	struct employee a;
	printf("\nSize of Struct Employee is %d.", sizeof(a));
}
