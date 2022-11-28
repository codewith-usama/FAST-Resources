#include<stdio.h>
main()
{
	int i=4, j=2;
	junk(&i,j);
	printf("\n%d %d",i,j);
}
junk(int*i,int j)
{
	*i=*i * *i;
	j=j*j;
	
}
