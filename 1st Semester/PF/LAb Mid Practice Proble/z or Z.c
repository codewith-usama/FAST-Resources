#include<stdio.h>
main()
{
	char ch;
	int count=0;
	do
	{
		
		printf("Enter a character: ");
		scanf(" %c", &ch);
		count++;	
	}
	while(ch!='z' && ch!='Z');
	{
		printf("Sum of entered character is %d", count-1);
		return 0;
	}
}
