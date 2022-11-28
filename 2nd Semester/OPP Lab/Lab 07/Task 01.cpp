#include<iostream>
using namespace std;
class book 
{
	public:
	string genre;
	book(string g) :genre(g)
	{
	}
};
class book1 :public book  
{
	public:
	string author;
	string  title;
	
	book1(string t,string a,string g) :book(g),title(t),author(a)
	{	
	}	
};
class book2: public book 
{
	public:
	string author;
	string  title;
	book2(string t,string a,string g) :book(g),title(t),author(a)
	{
	}
};
int main()
{
	string author, title, genre;
	cout << "Enter the title of book: ";
	getline(cin, title);
	cout << "Enter the author of book: ";
	getline(cin, author);
	cout << "Enter the genre of book: ";
	getline(cin, genre);
	
	book1 ob1(string t,string a,string g);
	cout << endl;
	book2 ob2("On the Island","Mohammad Usama","Hollywood");
	
	cout << "\nGenre of book is: " << ob2.genre << "\nTitle of book is: " << ob2.title << "\nAuthor of book is: " << ob2.author;
}
