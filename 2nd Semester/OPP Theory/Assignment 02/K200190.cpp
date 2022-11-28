#include<iostream>
using namespace std;
class Yagami{
	protected:
		string book_name;
		float annual_fee;
		float rate; 
		string fav_book[3]; //to add favourite books
	
	public:
		Yagami(float annual_fee, string book_name) //constructor for Yagami
		{
			this->book_name=book_name;
			this->annual_fee = annual_fee;
		}
		
		void rating(float rate) 
		{
			this->rate = rate;
		}    //rate function will be inherited by all child classes hence an object of child class can call this function
		
		void favourite_book(string fav_book)
		{
			for(int i=1; i<=3; i++)
			{
				this->fav_book[i] = fav_book[i];
			}
		}   //favourite_book function will be inherited by all child classes hence an object of child class can call this function
};


class Mangaworm:public Yagami{
	float mangameter;
	public:
		Mangaworm(string book_name, float annual_fee, float mangameter):Yagami(annual_fee, book_name)
		{
			this->mangameter = mangameter;
		}
		
		void reward()
		{
			if(mangameter>50)
			cout << "you are rewarded";
			else if(mangameter<0 || mangameter>100)
			cout << "Invalid mangameter value";
			else
			cout << "Not enough points for the reward.";
		}
};


class Comicnerd:public Yagami{
	float comicfactor;
	public:
		Comicnerd(string book_name, float annual_fee, float comicfactor):Yagami(annual_fee, book_name)
		{
			this->comicfactor = comicfactor;
		}
		
		void reward()
		{
			if(comicfactor>8)
			cout << "you are rewarded";	
			else if(comicfactor<0 || comicfactor>10)
			cout << "Invaled comicfactor value";
			else
			cout << "Not enough points for the reward.";
		}
};


class Studygeek:public Yagami{
	float studyscale;
	public:
		Studygeek(string book_name, float annual_fee, float studyscale):Yagami(annual_fee, book_name)
		{
			this->studyscale = studyscale;
		}
		
		void reward()
		{
			if(studyscale>0.6)
			cout << "you are rewarded.";
			else if(studyscale<0 || studyscale>10)
			cout << "Invalid studyscale value";
			else
			cout << "Not enough points for the reward.";
		}
};

class Freader:public Mangaworm, public Comicnerd, public Studygeek
{
	//count in freader to check number of books he has read
	void reward()
	{
		
	}
		
};
