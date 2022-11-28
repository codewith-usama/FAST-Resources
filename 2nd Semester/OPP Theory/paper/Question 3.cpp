#include<iostream>
#include<string.h>
using namespace std;
class shop
{
	public:
	int book_library_num;
	string author;
	string title;
	int edition_num;
	double price;
	int year_of_publication;
	public:
		void show_info(){
			cout << "Book num: " << book_library_num;
			cout << "\nAuthor name: " << author;
			cout << "\nBook Title: " << title;
			cout << "\nPrice: " << price;
			cout << "\nEdition num: " << edition_num;
			cout << "\nYear of publication: " << year_of_publication;
		}
		void get_bookinfo()
		{
			cout << "Enter book num: ";
			cin >> book_library_num;
			cout << "Enter author name: ";
			fflush(stdin);
			getline(cin,author);
			cout << "Book title: ";
			getline(cin,title);
			cout << "Enter price: ";
			cin >> price;
			cout << "Enter edition num: ";
			cin >> edition_num;
			cout << "Enter year of publication: ";
			cin >> year_of_publication;
		}
};
int main()
{
	int num, num_1;
	cout << "Enter number of books: ";
	cin >> num;
	shop ob1[num];
	for(int i = 0; i < num; i++)
	{
		ob1[i].get_bookinfo();
		system("cls");
	}
	cout << "1. Book Library number";
	cout << "\n2.Book's Name";
	cout << "\n3.Author Name";
	cout << "\n4.Edition Num";
	cout << "\n5.Year of publication";
	cout << "\n6.Price of book\n";
	cin >> num_1;
	string name, a_name;
	int num_2, num_3, num_4, price;
	if(num_1 == 1){
		cout << "Enter Book Library number";
		cin >> num_2;
		for(int i = 0; i < num; i++){
			if(num_2 == ob1[i].book_library_num){
				ob1[i].show_info();		
			}
		}
	}
	else if(num_1 == 2){
		cout << "Enter book name: ";
		fflush(stdin);
		getline(cin, name);
		for(int i = 0; i < num; i++){
			if(name == ob1[i].title){
				ob1[i].show_info();		
			}
		}
	}
	else if(num_1 == 3){
		cout << "Author name: ";
		fflush(stdin);
		getline(cin, a_name);
		for(int i = 0; i < num; i++){
			if(a_name == ob1[i].author){
				ob1[i].show_info();		
			}
		}
	}
	else if(num_1 == 4){
		cout << "Edition num: ";
		cin >> num_3;
		for(int i = 0; i < num; i++){
			if(num_3 == ob1[i].edition_num){
				ob1[i].show_info();		
			}
		}
	}
	else if(num_1 == 5){
		cout << "Enter year of publication: ";
		cin >> num_4;
		for(int i = 0; i < num; i++){
			if(num_4 == ob1[i].year_of_publication){
				ob1[i].show_info();		
			}
		}
	}
	else if(num_1 == 6){
		cout << "Enter price: ";
		cin >> price;
		for(int i = 0; i < num; i++){
			if(price == ob1[i].price){
				ob1[i].show_info();		
			}
		}
	}
}
