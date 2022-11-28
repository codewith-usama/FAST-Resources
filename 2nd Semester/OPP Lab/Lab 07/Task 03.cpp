#include<iostream>
using namespace std;
class student{
	int id;
	string name;
	public:
		void get_student_detail()
		{
			cout << "\nName of student is " << name << " ID " << id;
		}
		student()
		{
			cout << "Enter name: ";
			getline(cin, name);
			cout << "Enter ID: ";
			cin >> id;
		}
};
class marks : public student{
				public:
		int marks_oop, marks_pf, marks_ds, marks_db;
			void get_marks()
			{
				cout << "\nOOP marks: " << marks_oop;
				cout << "\nPF marks: " << marks_pf;
				cout << "\nDS marks: " << marks_ds;
				cout << "\nDB marks: " << marks_db;
			}
			marks()
			{
				cout << "Enter OOP marks: ";
				cin >> marks_oop;
				cout << "Enter PF marks: ";
				cin >> marks_pf;
				cout << "Enter DS marks: ";
				cin >> marks_ds;
				cout << "Enter DB marks: ";
				cin >> marks_db;	
				get_student_detail();
			}
		
};
class result : public marks{
	protected:
		int total_marks;
		double avg_marks;
		public:
			void display()
			{
				total_marks = marks_oop + marks_pf + marks_ds + marks_db;
				cout << "\nTotal marks is: " << total_marks;
				avg_marks =  total_marks / 4;
				cout << "\nAverage marks is: " << avg_marks;
			}
			result(){
			}
};
int main()
{
	result ob1;
	ob1.get_marks();
	ob1.display();
}
