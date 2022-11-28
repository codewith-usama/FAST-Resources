#include<stdio.h>
struct candidate
{
	int Firstpart[5];
	int Secondpart[7];
	int Thirdpart;
}can;
int main()
{
	int i, j;
	for(i = 0; i <= 4; i++)
	{
		printf("Enter %d digit: ",i + 1);
		scanf("%d", &can.Firstpart[i + 1]);
	}
	for(j = 6; j <= 12; j++)
	{
		printf("Enter %d digit: ",j);
		scanf("%d", &can.Secondpart[j]);
	}
	printf("Enter 13 digit: ");
	scanf("%d", &can.Thirdpart);
	
	for(i = 0; i <= 4; i++)
	{
		printf("%d", can.Firstpart[i]);
	}
	printf("-");
	for(j = 6; j <= 12; j++)
	{
		printf("%d", can.Secondpart[j]);
	}
	printf("-%d", can.Thirdpart);
	
	if(can.Thirdpart % 2 == 0)
	{
		printf("\nCandidate is Female");
	}
	else
	printf("\nCandidate is Male");
}	
