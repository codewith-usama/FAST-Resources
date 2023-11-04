#include <iostream>
#include <stdio.h>
#include <fstream>
#include <unistd.h>
using namespace std;


/* Print function definition*/
void Print() {
	ifstream fout;
	
	// file openining
	fout.open("E:\\3rd Semester\\Data Structure\\Project\\archive\\Display.txt");
	system("Color 0A");
	
	while(fout.good()) {
		string line;
		getline(fout, line);
		cout << line << endl;
		sleep(1);
		
	}
	
	// file closing
	fout.close();
	
	return; // return back
}
