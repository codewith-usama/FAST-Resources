#include <stdio.h>
int main()
{
	int hos, tsos;
	float ccos;
	printf("Enter hardness of Steel: ");
	scanf("%d", &hos);
	printf("Enter Carbon Content of Steel: ");
	scanf("%f", &ccos);
	printf("Enter Tensile strength of Steel: ");
	scanf("%d", &tsos);
	
	if(hos > 50 && ccos < 0.7 && tsos > 5600)
	printf("Grade is 10");
	else if(hos > 50 && ccos < 0.7)
	printf("Grade is 9");
	else if(ccos < 0.7 && tsos > 5600)
	printf("Grade is 8");
	else if(hos > 50 && tsos > 5600)
	printf("Grade is 7");
	else if(hos > 50 || ccos < 0.7 || tsos > 5600)
	printf("Grade is 6");
	else 
	printf("Grade is 5");
	
	
}
