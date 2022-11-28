#include<stdio.h>
#include<string.h>

int anagram(char str[], char str1[]){
	int x,y,i,j;
	x=strlen(str);
	y=strlen(str1);
	int count;
	if(x==y){
			for (i=0;i<=x-1;i++){
				for(j=0;j<=y-1;j++){
					if(str[i]==str[j])
						count++;
 
						
				}
				
			}
	}
	
	else 
		{
			printf("\n%s and %s are not Anagram.",str, str1 );
			return 0;
		}
		
	if (count==x){
		printf("\n%s and %s are Anagram.",str, str1 );
		return 0;
	}
	else 
		printf("\n%s and %s are not Anagram.",str, str1 );	
			
}



int main(){
	char str[50];
	char str1[50];
	printf("Enter a string: ");
	gets(str);
	printf("Enter another string: ");
	gets(str1);
	
	anagram(str,str1);	
}
