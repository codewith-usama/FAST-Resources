#include<stdio.h>
void main(void)
{
	int arr[] = {10, 20, 30, 40, 50};
	int * ptr;
	int i, j=1;
	ptr = arr;
//	for(i=0;i<=4;i++)
//	{
//		printf("Address of arr[%d] : %d ,",j, ptr);
//		printf("Value of arr[%d] : %d\n",j,*ptr);
//		ptr++;
//		j++;
////		printf("Address of arr[1] : %d\n", ptr);
//	}
//	
	printf("Address of arr[1] : %d\n", ptr);
	ptr += 2;
	printf("Value of arr[3] : %d\n", *ptr);

//	ptr = arr;
//	printf("Value of arr[1] : %d\n", *ptr);
//	printf("Address of arr[1] : %d", ptr);
}
