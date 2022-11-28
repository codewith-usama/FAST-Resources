#include<stdio.h>
int main(){
	int dd=0,mm=0,yy=0;
	int I=0,J=0,K=0;
	system("Color 0A");
	
	printf("Enter date in the form dd/mm/yy: ");
	scanf("%d/%d/%d",&dd,&mm,&yy);
	
	if(mm==1||mm==2)
	mm=mm+10;
	
	else
	mm=mm-2;
	K=yy%100;
	J=yy/100;
	
	if(mm==11||mm==12)
	J=J-1;
	I=(dd+(((13*mm)-1)/5)+K+(K/4)+(J/4)-(2*J));
	
	if(I>0)
	I=I%7;
	
	else
	{
		int x=0;
		x=I/7;
		I=-(I%7);
		I=I+x;
	}
	
	if(I==0)
		printf("Sunday");
	if(I==1)
		printf("Monday");
	if(I==2)
		printf("Tuesday");
	if(I==3)
		printf("Wednesday");
	if(I==4)
		printf("Thursday");
	if(I==5)
		printf("Friday");
	if(I==6)
		printf("Saturday");
	
}
