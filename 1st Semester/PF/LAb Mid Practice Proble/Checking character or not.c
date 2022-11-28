#include<stdio.h>
main()
{
	char ch;
	printf("Enter a character:");
	scanf("%c", &ch);
	
	switch(1)
	{
		case 1:
			{
				if(ch>='a' && ch<='z')
				printf("%c is character", ch);
				else if(ch>='A' && ch<='Z')
				printf("%c is character:", ch);
				else if(ch>='0' && ch<='9')
				printf("%c is number", ch);
				else
				printf("%c special character", ch);
				break;
		    } 
	}
}

