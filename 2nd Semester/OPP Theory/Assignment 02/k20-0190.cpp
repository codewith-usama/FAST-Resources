#include<iostream>
#include<string.h>
using namespace std;
class yagami {
	protected:
		string book_name;
		float annual_fee;
		float rate;
		string fav_book[3];
	public:
		yagami() { }
		yagami(string book_name, float annual_fee) {
			this->book_name = book_name;
			this->annual_fee = annual_fee;
		}
		void Rate(float rate) {
			this->rate = rate;
		}
		void Fav_book(string fav_book) {
			for(int i = 0; i < 3; i++) {
				this->fav_book[i] = fav_book[i];
			}
		}
};
class mangaworm : public yagami {
	protected:
		float mangameter;
	private:
		string book[5];	
	public:
		mangaworm() { }
		void books() { 
			book[0] = "Green-Eggs";
			book[1] = "On The Island";
			book[2] = "Fox-in-Socks";
			book[3] = "Ten-Tigers";
			book[4] = "Fly-Went-By";
		}
		mangaworm(float mangameter, string book_name, float annual_fee) : yagami(book_name, annual_fee) {
			this->mangameter = mangameter;
		}
		void reward() {
			if(mangameter > 50)
				cout << "You are rewarded!" << endl;
			else if(mangameter < 0 || mangameter > 100)
				cout << "Invalid Value." << endl;
			else
				cout << "Not enough points." << endl;		 
		}
	friend class freader;
};
class comicnerd : public yagami {
	protected:
		float comicfactor;
	private:
		string book[5];	
	public:
		comicnerd() { }
		void books() { 
			book[0] = "Vampire";
			book[1] = "Wonder Women";
			book[2] = "Bar-Garden";
			book[3] = "Ten-Tigers";
			book[4] = "Emma-Watson";
		}
		comicnerd(float comicfactor, string book_name, float annual_fee) : yagami(book_name, annual_fee)
		{
			this->comicfactor = comicfactor;
		}
		void reward() {
			if(comicfactor > 8) 
				cout << "You are rewarded!" << endl;
			else if(comicfactor < 0 || comicfactor > 10) 
				cout << "Invalid Value." << endl;
			else
				cout << "Not enough points." << endl;
		}
	friend class freader;
};
class studygeek : public yagami {
	protected:	
		float studyscale;
	private:
		string book[5];	
	public:
		studygeek() { }
		void books() { 
			book[0] = "Programming Fundamentals";
			book[1] = "Object Oriented Programming";
			book[2] = "Data Structure";
			book[3] = "Operating System";
			book[4] = "Data Base";
		}
		studygeek(float studyscale, string book_name, float annual_fee) : yagami(book_name, annual_fee)
		{
			this->studyscale = studyscale;
		}
		void reward() {
			if(studyscale > 0.6) 
				cout << "You are rewarded!" << endl;
			else if(studyscale < 0 || studyscale > 10) 
				cout << "Invalid Value." << endl;
			else
				cout << "Not enough points." << endl;
		}
	friend class freader;	
};
class freader : public mangaworm, public comicnerd, public studygeek {
	static int num_of_user;
	public:
		freader() {}
		int quantity() {  // to restrict system for five user
			++num_of_user;
			if(num_of_user > 5) 
				cout << "You have Reached number of members, Thank You." << endl;
				return num_of_user;
		}
		void read(string book_name) {
			cout << "I Hope you enjoyed " << book_name << " to read: "  << endl;
		}
		void reward() {
			cout << "Enter the value of Mangameter(1-100), Comicfactor(1-10), Studyscale(0-1) for the reader: ";
			cin >> mangameter;  //to get values of user
			cin >> comicfactor;
			cin >> studyscale;
			
			if (mangameter <= 50 && comicfactor <= 8 && studyscale <= 0.6)
				cout << "Your are not worthy for this reward." << endl;
			else if (mangameter <= 100 && comicfactor <= 10 && studyscale <= 1)
				cout << "Congratulations! Your are worthy for this reward." << endl;
			else
				cout << "You have rated out of range!!" << endl;
		}
};
int freader::num_of_user = 0;
int main() {
	char c;
	string book_name;
	freader ob1;
	// to add 5 freader
	for(int i = 0; c = 'y' && i < 100 ; i++) {
		int k = ob1.quantity();
		if(k > 5)
			break;
		else
			cout << "Enter Y to to add more user: ";
			cin >> c;
			system("cls");
	}
	// to restrict system to read only 15 books as a freader
	for(int i = 0; i < 15; i++) {
		cout << "Enter Name of book: ";
		fflush(stdin);
		getline(cin, book_name);
		ob1.read(book_name);
		cout << "Enter Y to read a book as a Freader: ";
		cin >> c;
		system("cls");
		if(i == 15)
			cout << "As a freader you can only read 15 books which you have done, for further you have to pay" << endl;
	}
}

