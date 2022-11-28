#include<stdio.h>
long factorial(int n){
	
	if(n>0)
	return(n*factorial(n-1));
	else 
	return 1;
}

main(){
	int n,y;
	printf ("Enter factorial:");
	scanf("%d",&n);
	y=factorial(n);
	printf("Factorial is %ld",y);
	
	
	
}


