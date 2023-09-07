#include<stdio.h>
int folks(int* money){
	*money=100;
	return *money;
	
}
int main(){
	int my_money=200;
	printf("folks say %d \n",folks(&my_money));
	printf("i still need %d \n", my_money);
	return 0;
	
	
	
	
}
