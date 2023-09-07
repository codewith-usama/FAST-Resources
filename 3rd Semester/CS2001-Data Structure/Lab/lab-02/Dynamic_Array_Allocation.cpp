#include <iostream>

using namespace std;

int main()
{
	int *arr { new int[5]{10, 7, 15, 3, 11}};
	
	for(int i=0; i<5; i++)
	{
		cout<<*arr<<" ";
		arr++;
	}
	cout<<endl;
	
	// delete [] arr;
	return 0;
}




//////////////////////////////////
