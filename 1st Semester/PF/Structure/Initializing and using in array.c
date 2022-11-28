#include<stdio.h>

struct user
{
	int userID; // Cannot initilaized values in structure > userID = 9;
	char username[10];
	int age;
}u, u1;
struct loan
{
	int loanAmount;
	float taxRate;
}ff;
struct campus
{
	char name[20];
	int noc;
};
int main()
{
	
//	printf("Enter user ID: ");
//	scanf("%d", &u.userID);
//	printf("Enter user name: ");
//	gets(u.username);
	//strcpy(u.username);
//	printf("\nEnter user age: ");
//	scanf("%d", &u.age);
//	printf("Enter user ID: ");
//	scanf("%d", &u1.userID);
//	printf("\nEnter user age: ");
//	scanf("%d", &u1.age);

	printf("Size of structure is : %d", sizeof(ff));
	
//	printf("\n\n %d \n %d",u.userID, u.age);
//	printf("\n\n %d \n %d",u1.userID, u1.age);

}
