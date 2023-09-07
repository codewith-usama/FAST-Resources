#include<iostream>
using namespace std;
int main() {
	int x, n;
	cout << "How many numbers will you type?" << "\n";
	cin >>n;
	int *arr = new int(n);
	cout << "Enter " << n << " numbers" << endl;
	for (x = 0; x < n; x++) {
		cin >> arr[x];
	}
//*arr=*arr+1;//increment in value
//arr++;// next index
//*arr++;// next index
//cout<<*arr<<endl;

	cout << "You typed: ";
	for (x = 0; x < n; x++) {
		cout << *(arr+x)<< " ";
}
	
	cout << endl;
	delete [] arr;
	return 0;
}
