#include<stdio.h>


int marks(){
	int arr[5];
	int i;
	int j=0;
	int sum=0;
	for (i=0;i<5;i++){
		j++;
		printf("Enter marks for %d course: ",j);
		scanf("%d",&arr[i]);
	}
	
	for(i=0;i<5;i++){
		sum=sum+arr[i];
	}
	int final=sum/5;
	printf("Average of all courses is: %d",final);
}

int main()
{
	marks();
}
