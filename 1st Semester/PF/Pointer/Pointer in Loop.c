#include<stdio.h>
main()
{
	char arr[] = "abc";
	char *ptr;
	ptr=arr;
	int i, j=1, k=1, p;
	
	for(i=0;i<=2;i++)
	{
		printf("Press %d to get the value and address of arr[%d]\n",j,k);
		j++;
		k++;
	}
	scanf("\n%d", &p);
	if(p==1)
	{
		printf("Value of arr[1] : %d and address is %d and member in that is %c",*ptr,ptr,*ptr);
	}
	else if(p==2)
	{
		ptr++;
		printf("Value of arr[2] : %d and address is %d and member in that is %c",*ptr,ptr,*ptr);
	}
	else if(p==3)
	{
		ptr +=2;
		printf("Value of arr[3] : %d and address is %d and member in that is %c",*ptr,ptr,*ptr);
	}
	
	
}
