#include<stdio.h>
#include<math.h>

float std_deviation(int x[], int n);
int main()
{
	int i, n;
	int x[n];
	printf("Enter limits of Elements of Array: ");
	scanf(" %d", &n);
	printf("Enter Elements of Array: ");
	for(i=0;i<n;i++)
	{
		scanf(" %d", &x[i]);
	}
	printf("Standard Deviation is:  %.2f", std_deviation(x, n));
}
float std_deviation(int x[], int n)
{
	int  i, s=0;
	for(i=0;i<n;i++)
	{
		s += x[i];
	}
	float m = s/n;
	s=0;
	for(i=0;i<n;i++)
	{
		s += (x[i]-m)*(x[i]-m);
	}
	float D = sqrt(s/n);
	return D;
}
