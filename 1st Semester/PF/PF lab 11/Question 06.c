#include <stdio.h>


int main() 
{
	char *str;
	str = malloc(10 *sizeof(char));
	scanf("%[^\n]s", str);
	printf("%s", str);
	free(str);
}
