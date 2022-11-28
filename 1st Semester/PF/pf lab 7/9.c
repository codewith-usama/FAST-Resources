#include<stdio.h>

int coordinate(){
	int x,y;
	printf("Enter x coordinate: ");
	scanf("%d",&x);
	
	printf("Enter y coordinate: ");
	scanf("%d",&y);
	
	if(x>0 && y>0)
		printf("\nYour point lies in First quadrant");
	else if (x<0 && y>0)
		printf("\nYour point lies in Second quadrant");
	else if (x<0 && y<0)
		printf("\nYour point lies in Third quadrant");
	else if (x>0 && y<0)
		printf("\nYour point lies in Fourth quadrant");
	
}

int main(){
	coordinate();
}
