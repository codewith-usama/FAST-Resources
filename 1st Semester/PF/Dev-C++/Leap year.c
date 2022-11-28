#include <stdio.h>
int main()
{
	int dd, mm, yy, count=0;
	char ch='c';
	while(ch!='N' && ch!='n')
	{
		printf("Enter date (DD/MM/YYYY format:) ");
        scanf("%d/%d/%d",&dd,&mm,&yy);
	}
}
