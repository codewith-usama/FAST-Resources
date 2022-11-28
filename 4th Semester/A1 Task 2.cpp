#include<iostream>
#include<climits>
using namespace std;
// FindSum function prototype
int FindSubArray(int Arr[], int);

// Display_Sub_Array function definition
void Display_Sub_Array(int Arr[], int, int, int);

// Driver Prgram
int main() {
	int n;
	cin >> n;
	int Arr[n];
	
	for(int i = 0; i < n; i++)
		cin >> Arr[i];
	
	// calling FindSubArray function
	FindSubArray(Arr, n);
	
	return 0;
}

// FindSubArray function definition
int FindSubArray(int Arr[], int n) {
	int Max_sum = 0;
	int Starting_index = 0;
	int Ending_index = 0;
	int count = 0;
	int sum;
	
	if(n <= 0) return 0;
	
	for(int i = 0; i < n; i++) {
		count += Arr[i];
		if(count > Max_sum) {
			Max_sum = count;
			Ending_index = i;
			Starting_index = i;
		}
		if(count < 0){
		  count = 0;};
			
		sum = Max_sum;
	}
	
	Max_sum = 0;
	
	while(Max_sum != sum) {
		Max_sum += Arr[Starting_index];
		if(Starting_index < 0) 
			Starting_index = 0;
		if (Max_sum == sum ) break;
		
		Starting_index--;	
	}
	
	// calling Display_Sub_Array function
	Display_Sub_Array(Arr, Starting_index, Ending_index, sum);
	
}

// Display_Sub_Array function definition
void Display_Sub_Array(int Arr[], int Starting_index, int Ending_index, int sum) {
	for(int i = Starting_index; i <= Ending_index; i++)
		cout << Arr[i] << " ";
		
	cout << endl << sum;
}


