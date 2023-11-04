#include <iostream>
#include <fstream>
#include <windows.h>
#include <unistd.h>
#include <stdlib.h>
#include "BST.cpp"
#include "Display.cpp"
#include "LinkedList.cpp"

using namespace std;


	



/* User_Data function prototype*/
void User_Data();

/* View_User_data function prototype*/
void View_User_data();


/* Driver Function*/

int main() {
	
	// function calling
	Print();
	
	
	system("Color 0A");
	cout << endl;
	system("pause");
	sleep(1);
	system("cls");
	User_Data();
	
	int num = 0;
	
	while(true) {
			cout << "1. To view 6 Months COVID-19's World Wide Data" << endl << "2. To view Country Wise Data" << 
			endl << "3. To view Users Files" << endl << "4.Exit";
			cout << endl << "Enter your choice: ";
			cin >> num;
			
			switch(num) {
				case 1:
					// function calling
					Full_Grouped();
					sleep(1);
					system("cls");
					break;
				case 2:
					// function calling
					All_Country_final_data();
					sleep(1);
					system("cls");
					break;
				case 3:
					// function calling
					View_User_data();
					sleep(1);
					system("cls");
					break;
				case 4:
					exit(0);				
			}
	}

	system("pause");


	return 0; // always return 0 from here
}

/* User_Data function definition*/
void User_Data() {
	
	string name;
	string ID;
	cout << "Enter your name: ";
	getline(cin, name);
	cout << "Enter you nu ID: ";
	getline(cin, ID);
	
	ofstream fin;
	fin.open("E:\\3rd Semester\\Data Structure\\Project\\archive\\User.txt", ios::app);
	
	fin << name << " " << ID << endl;
	
	// closing file
	fin.close();
}




void View_User_data() {
	
	ifstream fout;
	
	// file openining
	fout.open("E:\\3rd Semester\\Data Structure\\Project\\archive\\User.txt");
	system("Color 0A");
	
	while(fout.good()) {
		string line;
		getline(fout, line);
		cout << line << endl;
		
	}
	system("pause");
	
	// file closing
	fout.close();
}
