#include<iostream>
using namespace std;
struct data{
			string name;
			string title;
			string author;
		};
class book{
	string genre;
	string title;
	string name;
	public:
		book(){
		}
		book(string title, string name)
		{
			this->title = title;
			this->name = name;
		}
};
class novel : public book{
	string title;
	string name;
	string author;
	
	public:
	int num;	
		novel()
		{
			cout << "How many Novel you have: ";
			cin >> num;
			struct data o1[num];	
			cout << "Enter Novel data to store in the software\n";
			for(int i = 0; i < num; i++)
			{
				cout << "Enter name of book: ";
				fflush(stdin);
				getline(cin, o1[i].name);
				cout << "Enter title: ";
				getline(cin, o1[i].title);
				cout << "Enter author: ";
				getline(cin, o1[i].author);
			}
		}
};
class narrative : public novel{
	string title;
	string name;
	string author;
	public:
		
		narrative()
		{
			cout << "How many Narrative you have: ";
			cin >> num;
			struct data o2[num];
			cout << "Enter Narrative data to store in the software\n";
			for(int i = 0; i < num; i++)
			{
				cout << "Enter name of book: ";
				fflush(stdin);
				getline(cin, o2[i].name);
				cout << "Enter title: ";
				getline(cin, o2[i].title);
				cout << "Enter author: ";
				getline(cin, o2[i].author);
			}
		}
};
int main()
{
	narrative ob1;
	cout << ob1.num;
//	string title, name;
//	cout << "Enter title of book: ";
//	getline(cin, title);
//	cout << "Enter name of book: ";
//	getline(cin, name);
	
}
