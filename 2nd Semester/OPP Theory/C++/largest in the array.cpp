#include<iostream>
using namespace std;
int main()
{
	int arr[6];
	for(int i = 0; i < 6; i++){
		cout << "Enter num " << i+1 << ": ";
		cin >> arr[i];
	}
	for(int i = 0; i < 6; i++){
		if(arr[0] < arr[i]){
			arr[0] = arr[0]; 
		}
	}
}
