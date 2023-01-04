#include <iostream>
#include <fstream>
#include <vector>
#include <omp.h>

using namespace std;
int main(int argc, char** argv) {
	
	ifstream fin("test.txt");
	char ch;
	fin.seekg(0,ios::beg);
	
	vector<char> array;
	int count = 0;
	while(fin){
		fin.get(ch);
		array.push_back(ch);
	}
	
	int x = array.size();
	x = x / 4;
	
	#pragma omp parallel num_threads(4) reduction(+:count)
	{ 
	int j = omp_get_thread_num() * x;
		for(int i = j; i < j+x; i++){
			if( array[i] == ' ' || array[i] == '\n')
				count++;
		}
		cout << endl << "local wordcount of thread " << omp_get_thread_num() << " is: " << count << endl;		
	}
	printf("\n\nTotal wordcount: %d",count);	
	return 0;
}
