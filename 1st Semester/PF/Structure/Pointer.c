#include<stdio.h>
struct user
{
	char username[10];
	int age;
	char userpassword[10];
};
struct user InitializeUser(struct user par)
{
	strcpy(par.username, "Usama");
	strcpy(par.userpassword, "kk");
	par.age = 17;
	return par;
};
void Displayuser(struct user par)
{
	puts("User information");
	printf("Name %s \n", par.username);
	printf("Password %s \n", par.userpassword);
	printf("Age %d \n", par.age);
};
int main()
{
	struct user var;
	var = InitializeUser(var);
	Displayuser(var);
}
