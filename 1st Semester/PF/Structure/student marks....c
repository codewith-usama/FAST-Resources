#include<stdio.h>
struct student
{ 
	char name[10];
	int rollnum, attendencemarks, t1, t2, t3;
}s1, s2;
int main()
{ 
	printf("Enter First student name: ");
	gets(s1.name);
	printf("Enter Roll num: ");
	scanf("%d", &s1.rollnum);
	printf("Enter attendence marks: ");
	scanf("%d", &s1.attendencemarks);
	printf("Enter test 1 marks: ");
	scanf("%d", &s1.t1);
	printf("Enter test 2 marks: ");
	scanf("%d", &s1.t2);
	printf("Enter test 3 marks: ");
	scanf("%d", &s1.t3);
	printf("Name: %s\tRoll num: %d\tAttendence marks: %d\nTest 1 Makrk: %d\tTest 2 Makrk: %d\tTest 3 Makrk: %d", s1.name, s1.rollnum, s1.attendencemarks, s1.t1, s1.t2, s1.t3);
	
	printf("\n\n\n\nEnter Second student name: ");
	scanf("%s", s2.name);
	printf("Enter Roll num: ");
	scanf("%d", &s2.rollnum);
	printf("Enter attendence marks: ");
	scanf("%d", &s2.attendencemarks);
	printf("Enter test 1 marks: ");
	scanf("%d", &s2.t1);
	printf("Enter test 2 marks: ");
	scanf("%d", &s2.t2);
	printf("Enter test 3 marks: ");
	scanf("%d", &s2.t3);
	printf("Name: %s\tRoll num: %d\tAttendence marks: %d\nTest 1 Makrk: %d\tTest 2 Makrk: %d\tTest 3 Makrk: %d", s2.name, s2.rollnum, s2.attendencemarks, s2.t1, s2.t2, s2.t3);
} 
