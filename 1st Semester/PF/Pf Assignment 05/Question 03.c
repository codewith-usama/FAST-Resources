#include<stdio.h>
#include<math.h>

float euclidean(int *p, int *q, int n);
int main()
{
	int i, n;
	int p[n], q[n];
	printf("Enter Limit of Elements: ");
	scanf("%d", &n);
	printf("Enter Values of p: ");
	for(i=0;i<n;i++)
	{
		scanf("%d", &p[i]);
	}
	printf("Enter Values of y: ");
	for(i=0;i<n;i++)
	{
		scanf("%d", &q[i]);
	}
	float e = euclidean(p, q, n);
	printf("Euclidean Distance:  %.2f", e);
}

float euclidean(int *p, int *q, int n)
{
	int i, sum=0;
	for(i=0;i<n;i++)
	{
		sum += ((*(q+i)-*(p+i))*(*(q+i)-*(p+i)));
	}
	
	float d = sqrt(sum);
	return d;
}
