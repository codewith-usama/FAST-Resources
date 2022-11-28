#include<stdio.h>
#include<string.h>

char reverse_of_string(){
	char arr[1000],rev[1000];
	int l;
	printf("Enter String twice: ");
	gets(arr);
	printf("\n");
	gets(rev);
	
	strrev(rev);

	l=strcmp(arr,rev);
	
	if(l!=0)
		printf("\nPalindrome");
	else	
		printf("\nNot Palindrome");	
}



int main(){
	reverse_of_string();	
}
