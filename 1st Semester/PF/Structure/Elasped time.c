#include <stdio.h>
struct time
{
	int sec, min, hrs;
	float et;
}s1, s2;
int main()
{
	int hr, mi, se;
	printf("Enter Starting time format(hrs:min:sec): ");
	scanf("%d:%d:%d", &s1.hrs, &s1.min, &s1.sec);
	printf("Enter Ending time format(hrs:min:sec): ");
	scanf("%d:%d:%d", &s2.hrs, &s2.min, &s2.sec);

	hr = s2.hrs - s1.hrs; 
	mi = s2.min - s1.min;
	se = s2.sec - s1.sec;
	printf("Elapsed time id %d hrs : %d min : %d sec", hr, mi, se);	
}
