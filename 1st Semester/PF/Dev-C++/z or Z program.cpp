#include<stdio.h>
main()
{
	int count=0;
	char c;
	do
	{
		printf("Enter any character:");
	    scanf(" %c", &c);
	    count++;
	}
	while(c!='z' && c!='Z');
		printf("The number of character entered are:%d", count);
	return 0;
}
