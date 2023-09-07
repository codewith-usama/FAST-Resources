#include<stdio.h>
const int* folks(int* money){
	*money=100;
	return money;
	
}
int main(){
	int my_money=200;
	int *my_money_ptr;
	my_money_ptr=folks(&my_money);
	printf("i still need %d \n", *my_money_ptr);
	return 0;
	
	
	
	
}
