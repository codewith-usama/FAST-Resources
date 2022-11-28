#include<stdio.h>
#include<string.h>
main()
{
	int i, count=0;
	char freq, a[1000];
	printf("Enter a string: ");
	scanf("%s", &a[i]);
//	gets(a);
	printf("\nEnte a character you want to check the frequency of: ");
    scanf(" %c", &freq);
    
    for(i=0;i<a[i];i++)
    {
    	if(a[i]==freq)
    	count++;
	}
    
    printf("\nFrequency of %c is %d", freq,count);
}
