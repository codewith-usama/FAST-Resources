#include<stdio.h>
void printer(void *p, int code)
{
	int *ip;
	float *fp;
	switch(code)
	{
		case 1:
			ip = (int *) p;
			printf("Value of int valiable is %d", *ip);	
			break;
		case 2:
			fp = (float *) p;
			printf("Value of float variale is %.2f", *fp);
			break;	
	}
}

int main()
{
	int ivar= 10;
	float fvar=23.32;
	void *p;
	p=&fvar;
	printer(p, 2);
}
