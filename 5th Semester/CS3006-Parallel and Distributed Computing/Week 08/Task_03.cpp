#include <iostream>
#include <fstream>
#include <omp.h>

using namespace std;

int main() {
	ifstream file("sample.txt");
	string sample;
	int totalLines = 0;
	int i=0;
	
	while (getline (file, sample))
		totalLines++;
	
	ifstream nfile("sample.txt");
	string text[totalLines];
	
	while (getline (nfile, sample))
		text[i++]=sample;
	file.close();
		
	int partition = totalLines/2;
	int globalWords=0;
	
	#pragma omp parallel num_threads(2)
	{
		int localWords=0;
		int tId=omp_get_thread_num();
		int start_index=tId*partition;
		int end_index=start_index+partition;end_index--;
		for(int i=start_index;i<=end_index;i++){
			for(int j=0;j<text[i].length();j++){
				string sentence=text[i];
				if(sentence[j]==' ')
					localWords++;
			}
			localWords++;
		}
		cout<<"Local Tid"<<tId<<" : "<<localWords<<endl;
		#pragma omp critical
		{
			globalWords+=localWords;
		}
	}
	cout<<"global words "<<globalWords;
	
	return 0;
} 
