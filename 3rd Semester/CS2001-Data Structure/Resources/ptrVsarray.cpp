// 1st program to show that array and pointers are different
#include <iostream>
using namespace std;

int main()
{
	int arr[] = { 10, 20, 30, 40, 50, 60 };
	int* ptrtoarray=arr;
	int* intptr;
	char* charptr;
	int i;
	char c;

	// sizof(int) * (number of element in arr[]) is printed
	cout << "Size of arr[] " << sizeof(arr) << "\n";
	

	// sizeof a pointer is printed which is same for all
	// type of pointers (char *, void *, etc)
	cout << "Size of ptr pointing array " << sizeof(ptrtoarray)<<endl;
	cout << "Size of int " << sizeof(i)<<endl;
	cout << "Size of char " << sizeof(c)<<endl;
	cout << "Size of intptr " << sizeof(intptr)<<endl;
	cout << "Size of charptr " << sizeof(charptr)<<endl;
	intptr=&i;//fine
	arr=&i;//compiler error
	return 0;
}

