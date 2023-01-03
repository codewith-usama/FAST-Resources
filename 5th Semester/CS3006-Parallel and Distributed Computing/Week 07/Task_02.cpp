#include <iostream>
#include <omp.h>
using namespace std;
int main() {
	int arr[20] = {1, 2, 3, 4, 5,
					1, 2, 3, 4, 5,
					1, 2, 3, 4, 5,
					1, 2, 3, 4, 5};
					
	int sum = 0;
	int local_sum[4];
	
	#pragma omp parallel num_threads(4) reduction(+:sum)
	
	{
		sum += arr[5*omp_get_thread_num()];
		sum += arr[5*omp_get_thread_num() + 1];
		sum += arr[5*omp_get_thread_num() + 2];
		sum += arr[5*omp_get_thread_num() + 3];
		sum += arr[5*omp_get_thread_num() + 4];
		local_sum[omp_get_thread_num()] = sum;
	}
	
	cout << "Local Thread results: " << endl;
	for(int i = 0; i < 4; i++) {
		cout << "By Thread " << i+1 << ": " << local_sum[i] << endl;
	}
	
	cout << "Total sum: " << sum;
	
	
	return 0;
}
