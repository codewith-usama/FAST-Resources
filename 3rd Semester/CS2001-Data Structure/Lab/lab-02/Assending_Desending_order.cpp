#include <iostream>

using namespace std;

int main()
{
	int arr[10] = {66,11,33,44,1,3,0,-9,-88,14};
	int ass_arr[10];
	int des_arr[10];
//	int *arr;
//	arr = new int[6]{3,5,77,88,1,-9};
	
	for(int i=0; i<10; i++)
	{
		for(int j=i+1; j<10; j++)
		{
			if(arr[i]<arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j]= temp;
			}
		}
	}
	cout<<"Desending order ...";
	for(int i=0; i<10; i++)
	{
		des_arr[i] = arr[i];
		cout<<arr[i]<<" ";
		
	}
	cout<<endl;
	int m = 0;
	cout<<"Assending order ...";
	for (int i = 9; i>=0; i--)
	{
		cout<<arr[i]<<" ";
		ass_arr[m] = arr[i];
		m++;
	}

	cout<<endl;

cout<<"Highest maximum and minimum"<<endl;
for (int i=0; i<10; i++)
{
	cout<<"	"<<des_arr[i]<<"<--->"<<ass_arr[i];
	cout<<endl;
	//cout<<des_arr[i]<<" ";
}

cout << "   ";


	return 0;
}
                     