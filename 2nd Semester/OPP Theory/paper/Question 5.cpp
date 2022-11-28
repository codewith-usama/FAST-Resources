#include<iostream>
using namespace std;
int main(){
	double scores[10] = {2.5, 3.9, 4.8, 6.2, 6.2, 7.4, 7.9, 8.5, 8.5, 9.9};
	cout << "Array in decending order = [";	
	for(int i = 9; i >= 0; i--){
		cout << scores[i] << " ";
	}
	cout <<"]";
}
