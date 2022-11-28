#include<stdio.h>
struct user
{
	char username[10];
	int age;
	char userpassword[10];
};
int main()
{
	struct user *ptr;
	int n ;
	printf("Enter Number of User: ");
	scanf("%d", &n);
	ptr = (struct user*) malloc(n * sizeof(struct user));
	int i;
	for(i = 1; i <= n; i++)
	{
		printf("Enter Name of User %d: ",i);
		scanf("%s", ptr->username);
		printf("Enter Password of User %d: ",i);
		scanf("%s", ptr->userpassword);
		printf("Enter Age of User %d: ",i);
		scanf("%d", &ptr->age);
		(ptr+1)->username;
		(ptr+1)->userpassword;
		(ptr+1)->age;
	}
	system("cls");
	
	for(i = 1; i <= n; i++)
	{
		printf("Name of User %d : %s\n",i,ptr->username);
		printf("Password of User %d : %s\n",i,ptr->userpassword);
		printf("Age of User %d : %d\n",i,ptr->age);
		(ptr+1)->username;
		(ptr+1)->userpassword;
		(ptr+1)->age;
	}
	
	
	
	
	
//	ptr->age = 25;
//	printf("User 1 Age: %d\n", ptr->age);
//	(ptr+1)->age = 30;
//	printf("User 2 Age: %d\n", (ptr+1)->age);
//	(ptr+2)->age = 40;
//	printf("User 3 Age: %d\n", (ptr+2)->age);
}
