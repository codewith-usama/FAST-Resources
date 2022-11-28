#include<iostream>
using namespace std;
class shop
{
	public:
	string author;
	string title;
	double price;
	string publisher;
	int stock;
	
		void get_bookinfo()
		{
			cout << "Enter author name: ";
			fflush(stdin);
			getline(cin,author);
			cout << "Book title: ";
			getline(cin,title);
			cout << "Enter price: ";
			cin >> price;
			cout << "Enter publisher name: ";
			fflush(stdin);
			getline(cin,publisher);
			cout << "Enter stock: ";
			cin >> stock;
		}
};
int main()
{
	int num, copies;
	string title, author;
	cout << "Enter number of books: ";
	cin >> num;
	shop ob1[num];
	for(int i = 0; i < num; i++)
	{
		ob1[i].get_bookinfo();
		system("cls");
	}
	cout << "Enter Author name: ";
	fflush(stdin);
	getline(cin,author);
	cout << "Enter title name:";
	getline(cin,title);
	
	for(int i = 0; i < num; i++)
	{
		if(author == ob1[i].author && title == ob1[i].title)
		{
			cout << "Book is avalaible.\n";
			cout << "Enter Requested Copies: ";
			cin >> copies;
			if(copies <= ob1[i].stock)
			{
				cout << "\nBook author is " << ob1[i].author;
				cout << "\nTitle is " << ob1[i].title;
				cout << "\nPrice is " << ob1[i].price * copies;
				cout << "\nPublisher of book is " << ob1[i].publisher;
			}
			else
				cout << "Required copies not in stock.";
				break;
		}
		else
		cout << "Book not Available.";
	}
} 

