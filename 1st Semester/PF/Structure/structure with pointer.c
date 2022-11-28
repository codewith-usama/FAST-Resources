#include<stdio.h>
struct campus
{
	int noofcampuses;
	float avgGpa;
};
int main()
{
	struct campus var;
	struct campus * ptr;
	ptr = &var;
	scanf("%d", &(*ptr).noofcampuses);
	printf("%d\n", ptr->noofcampuses);
	printf("%d", (*ptr).noofcampuses);
}
