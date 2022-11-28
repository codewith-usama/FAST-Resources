#include<iostream>
using namespace std;
class Book
{
	public:
	string book_name;
	int ISBN_num;
	string author_name;
	string publisher;
	void book_info()
	{
		cout << "Book -------------- " << book_name;
		cout << "\nISBN Num ---------- " << ISBN_num;
		cout << "\nAuthor ------------ " << author_name;
		cout << "\nPublisher --------- " << publisher;
	}
	Book()
	{
		
	}
	Book(string book_name, int ISBN_num, string author_name, string publisher)
	{
		this->book_name = book_name;
		this->ISBN_num = ISBN_num;
		this->author_name = author_name;
		this->publisher = publisher;
		book_info();
	}
};
int main()
{
//	Book ob1("On The Islans", 325 , "Tracey Garvis Graves", "Catherine Cover");
	Book ob1;
	string book_name, author_name, publisher;
	int ISBN_num;
	cout << "Enter Book Name: ";
	getline(cin,ob1.book_name);
	book_name = ob1.book_name;
	cout << "Enter ISBN num: ";
	cin >> ob1.ISBN_num;
	ISBN_num = ob1.ISBN_num;
	cout << "Enter Author Name: ";
	fflush(stdin);
	getline(cin,ob1.author_name);
	author_name = ob1.author_name;
	cout << "Enter Publisher Name: ";
	getline(cin,ob1.publisher);
	publisher = ob1.publisher;
	Book ob2(book_name, ISBN_num, author_name, publisher);
	
}
