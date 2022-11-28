#include<iostream>
using namespace std;
class student{
	string name;
	int roll_num;
	float marks[4];
	float percentage, total;
	public:
		void input_data(){
			cout << "Enter name: ";
			getline(cin, name);
			cout << "Enter roll num: ";
			cin >> roll_num;
			for(int i = 0; i < 4; i++){
				cout << "Enter subject " << i + 1 << " marks: ";
				cin >> marks[i];
				total += marks[i];
			}
		}
		void calculate_percentage(){
			cout << "Total marks is: " << total;
			percentage = (total * 100) / 400;
			cout << "\nYour percentage is: " << percentage;
		}
		void display_student(){
			cout << "\nName: " << name;
			cout << "\nRoll num: " << roll_num << endl;
			for(int i = 0; i < 4; i++){
				cout << "Subject " << i + 1 << " marks: " << marks[i] << endl;
			}
		}
};
int main(){
	student ob1;
	ob1.input_data();
	ob1.calculate_percentage();
	ob1.display_student();
}
