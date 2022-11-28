#include<stdio.h>
#include<string.h>

void encryption(char arr[] )
{	
	int key,i,l;
	printf("Enter Encryption Key : ");
	scanf("%d",&key);
	for (i=0 ; arr[i]!='\0' ; i++)
	{
		if (arr[i]>=88 && arr[i]<=90)
			arr[i]=(arr[i]+key)-26;
		else	
			arr[i]=(arr[i]+key);
	}
	printf("Your Message is encrypted : \n");
	for (i=0 ; arr[i]!='\0' ; i++)
	{	
		if ( arr[i]==35)
			printf("%c",arr[i]-key);		
		else 
			printf("%c",arr[i]+32);
	}
}

void decryption(char arr[])
{
	int key,i,l;
	printf("Enter Key : ");
	scanf("%d",&key);
	for (i=0 ; arr[i]!='\0' ; i++)
	{
		if (arr[i]>=97 && arr[i]<=99)
			arr[i]=(arr[i]-key)+26;
		else	
			arr[i]=(arr[i]-key);
	}
	printf("Your Message is decrypted : \n");
	for (i=0 ; arr[i]!='\0' ; i++)
	{	
		if ( arr[i]==112)
			printf("%c",arr[i]+key);		
		else 
			printf("%c",arr[i]-32);
	}	
}

int main()
{
	int c,n; 
	char str[1000];
	printf("Enter Message : ");
	gets(str);
	printf("1-Encryption\n2-Decryption\nPlease select any one : ");
	scanf("%d",&c);
	if (c==1)
		encryption(str);
	else 
		decryption(str);	
}

