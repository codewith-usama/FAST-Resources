#include<stdio.h>

int factors(){
	
	int start, fin;
	int i;
	printf("Enter starting number: ");
	scanf("%d",&start);
	
	printf("Enter ending number: ");
	scanf("%d",&fin);
	
	for(i=start;i<=fin;i++){
		if(i%3==0)
			printf("%d\n",i);
		else
			printf(" ");
	}
}

int main()
{
	factors();
}
