#include<iostream>
using namespace std;
int main()
{
	const int size=10;
	int b[size]={0,1,2,3,4,5,6,7,8,9};
	int *bptr1=&b[0];
	int *bptr2=&b[size-1];
	for (int i=0;i<size;i++)
	{
		if (i==0)
		b[i]=b[i]*b[i];
		else
		b[i]=b[i]*b[i]-b[i-1];
		cout<<b[i]<<endl;
	}
	cout << bptr2[-3] << endl;
	cout << * bptr1 + 4*2 << endl;
	bptr2-=4;
	cout << * (bptr2 - 2) << endl;
	cout << bptr2 - bptr1 <<endl;
	while (bptr1!=bptr2)
	bptr1++;
	cout<< bptr1[0] << " " << *bptr2 << endl;
}
