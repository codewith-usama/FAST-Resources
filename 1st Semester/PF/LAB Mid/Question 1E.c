#include<stdio.h>
main()
{
	char s[]="Get organised! lean=rn C!!";
	printf("\n%s", &s[2]);
	printf("\n%s", s);
	printf("\n%s", &s);
	printf("\n%c", s[2]);
}
