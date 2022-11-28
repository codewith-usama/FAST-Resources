#include<stdio.h>
#include<string.h>

int fibonacci(int num){
	int a=0, b=1, c;
	int i;
	printf("Fibonacci Series:");
	for(i=1;i<=num;i++){
    	printf("%2d", a);
    	c = a+b;
		a = b;
    	b = c;
   }	
   
}


int main(){
	
	int n, series;

   printf("Enter Number: ");
   scanf("%d", &n);

   series = fibonacci(n);
   return 0;
}
