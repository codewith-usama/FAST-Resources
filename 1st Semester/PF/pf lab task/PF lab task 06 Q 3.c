#include<stdio.h>
main()
{
	int a[7], i, j=0, max=0, min=500, max_d, min_d;
	for(i=0;i<=6;i++)
	{
		printf("Enter temperature of day %d: ", j+1);
		j++;
		scanf("%d", &a[i]);
		
		if(max<a[i])
		{
			max=a[i];
			max_d=j;
		}
		if(min>a[i])
		{
			min=a[i];
			min_d=j;
		}
	}
	printf("\nTemperature is max at day %d",max_d);
	printf("\nTemperature is min at day %d",min_d);
}
