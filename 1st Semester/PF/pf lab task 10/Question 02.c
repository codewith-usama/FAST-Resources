#include<stdio.h>
struct time
{
	int starting, ending, elapsed;
}
t1, t2;
int main()
{
	printf("Enter T1 starting: ");
	scanf("%d", &t1.starting);
	printf("Enter T1 ending: ");
	scanf("%d", &t1.ending);
	t1.elapsed=t1.ending-t1.starting;
	printf("The First elapsed time is %d", t1.elapsed);
	printf("\n\nEnter T2 starting: ");
	scanf("%d", &t2.starting);
	printf("Enter T2 ending: ");
	scanf("%d", &t2.ending);
	t2.elapsed=t2.ending-t2.starting;
	printf("The Second elapsed time is %d", t2.elapsed);
}
