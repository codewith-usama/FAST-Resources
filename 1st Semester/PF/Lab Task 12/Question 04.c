#include <stdio.h>
struct member
{
	char name [100];
};
int main()
{
	FILE *fptr;
	fptr = fopen("Member.bin", "wb");
	
	int n, i;
	system("color 0A");
	printf("Enter Number of Member: ");
	scanf("%d", &n);
	
	struct member m[n];
	
	for(i = 1; i <= n; i++)
	{
		printf("Enter Member %d Name: ", i);
		scanf("%s", m[i].name);
		fwrite(&m[i], sizeof(struct member), 1, fptr);
	}
	fclose(fptr);
	system("Cls");
	
	fptr = fopen("Member.bin", "rb");
	
	if(fptr ==  NULL)
	{
		puts("Error");
		
	}
	
	for(i = 1; i <= n; i++)
	{
		fread(&m[i], sizeof(struct member), 1, fptr);
		printf("%d. Member: %s\n", i, m[i].name);
	}
	fclose(fptr);
}
