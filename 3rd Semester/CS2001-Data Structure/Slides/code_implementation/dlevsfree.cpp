// comment line 17 and 13 to get the program run correctly.
#include<iostream>
#include<stdlib.h>
int main()
{
	int x;
	int *ptr1 = &x;
	int *ptr2 = (int *)malloc(sizeof(int));
	int *ptr3 = new int;
	int *ptr4 = NULL;

	/* delete Should NOT be used like below because x is allocated
		on stack frame */
	delete ptr1;

	/* delete Should NOT be used like below because x is allocated
		using malloc() */
	delete ptr2;

	/* Correct uses of delete */
	delete ptr3;
	delete ptr4;

	
	return 0;
}

