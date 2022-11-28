#include<stdio.h>

int admission(){
	int maths, phy, chem;
	
	printf("Enter marks for Maths: ");
	scanf("%d",&maths);
	
	printf("Enter marks for Physics: ");
	scanf("%d",&phy);
	
	printf("Enter marks for Chemistry: ");
	scanf("%d",&chem);
	
	if (maths>=50){
		if (phy>=65){
			if (maths+phy>=140)
				printf("You are eligible for admission");
			else{
				if(chem>=50){
					if (maths+phy+chem>=180)
						printf("You are eligible for admission");
					else
						printf("You are not eligible for admission");
				}
			}
						
		}
	}
	else{
		if (phy>=65){
			if (maths+phy>=140)
				printf("You are eligible for admission");
			else{
				if(chem>=50){
					if (maths+phy+chem>=180)
						printf("You are eligible for admission");
					else
						printf("You are not eligible for admission");
				}
			}
						
		}
	}
		
}

int main()
{
	admission();
}
