#include<stdio.h>
main()
{
	int a[8], i, j, z=0, p=0, n=0, sum=0;
	for(i=0;i<=7;i++)
	{
		printf("Enter Number %d: ", j);
		scanf("%d", &a[i]);
		j++;
	}
	
	for(i=0;i<=7;i++)
	{
		if(a[i]==0)
	    z++;
	    
	    if(a[i]>0)
	    sum=sum+a[i];
	    p++;
	    
	    if(a[i]<0)
	    n++;
	
	
    }
    
    
    printf("\nNumber of zeros entered are:%d", z);
    printf("\nNumber of positive number entered are:%d", p-z-n);
    printf("\nNumber of negative number entered are:%d", n);
    printf("\nSum of positive number is:%d", sum);
	
}
