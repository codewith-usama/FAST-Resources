#include<stdio.h>
main()
{
	int a[100], swap, d;
	int n_o_m, j=1, i, s_o_m, sum=1;
	float avg;
	printf("Enter the number of month:");
	scanf("%d", &n_o_m);
	
	
	for(i=1;i<=n_o_m;i++)
	{
		printf("Enter salary of month %d in K: ", j);   //Salary is in thousand "K"
		scanf("%d", &a[i]);
		j++;
	}
	
	for(i=1;i<=n_o_m;i++)
	{
		sum=sum+a[i];
		
		
	}

		printf("Sum of Salary of all month is:%d K", sum-1);
		
	avg=sum/n_o_m;
	printf("\nAverage of salary of %d month is %.2f K", n_o_m, avg);


	  for (i = 0 ; i < n_o_m - 1; i++)
  {
    for (d = 0 ; d < n_o_m - i - 1; d++)
    {
      if (a[d] > a[d+1]) /* For decreasing order use '<' instead of '>' */
      {
        swap       = a[d];
        a[d]   = a[d+1];
        a[d+1] = swap;
      }
    }
  }

  printf("\nSorted list in ascending order:\n");

  for (i= 0; i < n_o_m; i++)
    {
	 printf(" %d\n", a[i]);
}

	
}
