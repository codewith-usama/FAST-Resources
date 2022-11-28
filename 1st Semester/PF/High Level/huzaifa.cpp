#include <fstream>
#include <string>
#include <iostream>

using namespace std;
int enroll() 
{

	string each_stud[4];
	cout << "enter name of the student : ";
	cin >> each_stud[0];
	each_stud[0] += "\n";
	cout << "enter the program : ";
	cin >> each_stud[1];
	each_stud[1] += "\n";
	cout << "section : ";
	cin >> each_stud[2];
	each_stud[2] += "\n";
	cout << "enter cources : ";
	cin >> each_stud[3];
	each_stud[3] += "\n";
	fstream file_5;
	file_5.open("enrollment.txt", fstream::out|fstream::app);
	for (int i = 0; i <= 3; ++i) 
	{
		file_5 << each_stud[i];
	}
}
int main()
 {
	int admin;
	while (true)
	 {
		cout << "welcome" << endl;
		cout << "Enter 1 for create or show degree program" << endl;
		cout << "Enter 2 for create or show cources" << endl;
		cout << "Enter 3 for assign at section" << endl;
		cout << "Enter 4 at most courses to the students" << endl;
		cout << "Enter 5 for enroll student in cources and section" << endl;
		cout << "Enter 6 for EXIST" << endl;

		cout << "Enter a number : \n";
		cin >> admin;
if(admin==1)
{

			cout << "Enter 1 to create program \nEnter 2 to show degree program";
			int cp_dp; // a variable decleare for to chose create program or show degree program
			cout << "Enter the number : " << endl;
			cin >> cp_dp;
			cout << endl;
			string deg;
			fstream file_1;
			if (cp_dp == 1) {
				int n;
				cout << "How many degree programs you want to create : ";
				cin >> n;
				file_1.open("degree_program.txt", fstream::out|fstream::app);
				for (int i = 1; i <= n; i++) {
					cout << "Enter the names of programs : ";
					cin >> deg;
					deg += "\n";
					file_1 << deg;   //getline(file_1,deg) it shows no error but value is not storing
				}
				file_1.close();
			}
			if (cp_dp == 2) {
				file_1.open("degree_program.txt");
				cout << "Degree Programs in NUST \n" << endl;
				while (!file_1.eof())      
				{
					cout << deg << endl;
					file_1 >> deg;               
				}		
			}
			break;

		}
		if(admin==2) 
		{

			cout << "Enter 1 to create cources \nEnter 2 to show cources" << endl;
			int cc_sc; // a variable decleare for to chose create cources or show cources
			cout << "Enter the number : " << endl;
			cin >> cc_sc;
			string cource;
			fstream file_2;
			if (cc_sc == 1) {
				int n;
				string program_name;
				cout << "Enter the name of the program in which you want to store the program ";
				cin >> program_name;
				program_name += "\n";
				cout << "how many cources you want to create : ";
				cin >> n;
				file_2.open("cources.txt", fstream::out | fstream::app);
				file_2 << program_name;
				for (int i = 1; i <= n; i++)
				{
					cout << "Enter the name of cources :";
					cin >> cource;
					cource += "\n";
					file_2 << cource;

				}
				file_2.close();
			}
			if (cc_sc == 2) {
				file_2.open("cources.txt", fstream::in);
				cout << "Cources: " << endl;
				while (!file_2.eof())
				{
					cout << cource << endl;
					file_2 >> cource;
				}

			}
			break;

		}
		if(admin==3) 
		{
			cout << "Enter 1 to create section \nEnter 2 to show section" << endl;
			int cs_ss; // a variable decleare for to chose create cources or show cources
			cout << "Enter the number : " << endl;
			cin >> cs_ss;
			string section;
			fstream file_3;
			if (cs_ss == 1) {
				string program_name;
				cout << "Enter the name of the program in which you want to create te section ";
				cin >> program_name;
				program_name += "\n";
				file_3.open("sections.txt", fstream::out | fstream::app);
				file_3 << program_name;
				for (int i = 1; i <= 3; i++)
				{
					cout << "Enter the name of section :";
					cin >> section;
					section += "\n";
					file_3 << section;
				}
				file_3.close();
			}
			if (cs_ss == 2) {
				file_3.open("sections.txt", fstream::in);
				cout << "Sections :" << endl;
				while (!file_3.eof())
				{
					
					file_3 >> section;
					cout << section << endl;
				}
			}
			break;
		}
	
		if(admin==4)  
		{
			cout<<"hissan"<<endl;
			break;
		}

		if(admin==5)  {
			cout << "Enter 1 to enroll student \nEnter 2 to show enrolled student" << endl;;
			int es_se; // a variable decleare for to chose create cources or show cources
			cout << "Enter the number : " << endl;
			cin >> es_se;
			fstream file_5;
	
			if (es_se == 1)
			{
				int i;
				file_5.open("enrollment.txt", fstream::out);
				int n;
				cout << "no of enroll student:";
				cin >> n;
				for ( i=1; i<n; i++)
				{
					cout<<"hissan"<<endl;
				enroll();
				}
				file_5.close();
}
			
			else
				file_5.open("enrollment.txt", fstream::out);
			{ while (!file_5.eof())
			{
				cout << enroll << endl;
			/*	file_5 >> enroll;*/
			}


				break;
			}
			file_5.close();
		}
	}
}
	

//		}
	

//#include <iostream> 
//using namespace std;
//
//// Function to demonstarte std::string::at 
//void atDemo(string str)
//{
//	cout << str.at(5);
//
//	// Below line throws out of 
//	// range exception as 16 > length() 
//	// cout << str.at(16); 
//}
//
//// Driver code 
//int main()
//{
//	string str("GeeksForGeeks");
//	atDemo(str);
//	return 0;
//}
