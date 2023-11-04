#include <fstream>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
using namespace std;


/* Linked List class definition*/
class Linked_list {	
private:
	string date;
	string country;
	string Confirmed;
	string Deaths;
	string Recovered;
	string Active;
	string New_cases;
	string New_deaths;
	string New_recover;
	string WHO_region;
	Linked_list *next;
	Linked_list *head;
	Linked_list *tail;
	
public:
	
	/* getter funtion definition*/
	Linked_list* Get_head() { return head; }
	Linked_list* Get_tail() { return tail; }
	
	/* default constructor*/
	Linked_list(): head(NULL), tail(NULL), next(NULL) { }
	
	/* Parametrized constructor prototype*/
	Linked_list(string date, string country, string Confirmed, string Deaths, string Recovered, string Active, string New_cases, string New_deaths,
		string New_recover, string WHO_region);
	
	/* Insert_Data function prototype*/
	void Insert_Data(string date, string country, string Confirmed, string Deaths, string Recovered, string Active, string New_cases, string New_deaths,
		string New_recover, string WHO_region);
	
	/* Display_Data function prototype*/
	void Display_Data(Linked_list *p);
	
	/* Binary Search function prototype*/
	Linked_list* Binary_Search(Linked_list *p, string, string);
	
	/*Middle function prototype*/
	Linked_list* Middle(Linked_list *start, Linked_list *last);
	
	/*Delete_Data function prototype*/
	Linked_list* Delete_Data(Linked_list *p, string, string);
};



/* Parametrized constructor definition*/
Linked_list::Linked_list(string date, string country, string Confirmed, string Deaths, string Recovered, string Active, string New_cases, string New_deaths,
		string New_recover, string WHO_region) {
			
		head = tail = next = NULL;
			
		this->date = date;
		this->country = country;
		this->Confirmed = Confirmed;
		this->Deaths = Deaths;
		this->Recovered = Recovered;
		this->Active = Active;
		this->New_cases = New_cases;
		this->New_deaths = New_deaths;
		this->New_recover = New_recover;
		this->WHO_region = WHO_region;
}


/* Insert_Data function definition*/
void Linked_list::Insert_Data(string date, string country, string Confirmed, string Deaths, string Recovered, string Active, string New_cases, string New_deaths,
		string New_recover, string WHO_region) {
		
		Linked_list *NewNode = new Linked_list(date, country, Confirmed, Deaths, Recovered, Active, New_cases, New_deaths, New_recover, WHO_region);
		NewNode->next = NULL;
		
		if(head == NULL) {
			head = tail = NewNode;
			return;
		}
		tail->next = NewNode;
		tail = NewNode;
		return;
}


/* Display_Data function prototype*/
void Linked_list::Display_Data(Linked_list *p) {
	if(p) {
		cout << p->date << "\t  " << p->country << "\t  " << p->Confirmed << "\t  " << p->Deaths << "\t  " << p->Recovered << "\t  " << p->Active << "\t  " << p->New_cases << "\t  " <<
		p->New_deaths << "\t  " << p->New_recover <<  "\t  " << p->WHO_region << endl << endl;
		Display_Data(p->next);
	}
}


/*Middle function definition*/
Linked_list* Linked_list::Middle(Linked_list *start, Linked_list *last) {
	
	if(start == NULL)
		return start;
		
	Linked_list *slow = start;
	Linked_list *fast = start->next;
	
	while(fast != last) {
		fast = fast->next;
		if(fast != last) {
			slow = slow->next;
			fast = fast->next;
		}
	}
	
	return slow;
}

/* Binary Search function definition*/
Linked_list* Linked_list::Binary_Search(Linked_list *p, string country, string date) {
	
	Linked_list *start = head;
	Linked_list *last = NULL;
	
	do {
		Linked_list *mid = Middle(start, last);
		
		if(mid == NULL)
			return mid;
			
		if(mid->date == date && mid->country == country) {
			cout << mid->date << "\t  " << mid->country << "\t  " << mid->Confirmed << "\t  " << mid->Deaths << "\t  " << mid->Recovered << "\t  " << mid->Active << "\t  " << mid->New_cases << "\t  " <<
				mid->New_deaths << "\t  " << mid->New_recover <<  "\t  " << mid->WHO_region << endl << endl;
				return mid;
		}
			
		else if(mid->date < date)
			start = mid->next;
		
		else 
			last = mid;
	} while(last == NULL || last != start);
	
	
	// value not present
	return NULL;
}



/*Delete_Data function definition*/
Linked_list* Linked_list::Delete_Data(Linked_list *p, string date, string country) {
	
	Linked_list *start = head;
	Linked_list *last = NULL;
	
	do {
		Linked_list *mid = Middle(start, last);
		
		if(mid == NULL)
			return mid;
			
		if(mid->date == date && mid->country == country) {
			Linked_list *temp = mid;
			delete mid;
			cout << mid->date << "\t  " << mid->country << "\t  " << mid->Confirmed << "\t  " << mid->Deaths << "\t  " << mid->Recovered << "\t  " << mid->Active << "\t  " << mid->New_cases << "\t  " <<
				mid->New_deaths << "\t  " << mid->New_recover <<  "\t  " << mid->WHO_region << endl << endl;
		}
			
		else if(mid->date < date)
			start = mid->next;
		
		else 
			last = mid;
	} while(last == NULL || last != start);
	
	
	// value not present
	return NULL;
	
}



/*Full_Grouped function definition*/
void Full_Grouped() {
	
	ifstream fout;
    
	// file openining
	fout.open("E:\\3rd Semester\\Data Structure\\Project\\archive\\full_grouped.csv");
    
    string date;
    string country;
	string Confirmed;
	string Deaths;
	string Recovered;
	string Active;
	string New_cases;
	string New_deaths;
	string New_recover;
	string WHO_region;

	Linked_list ob1;
    int i = 0;
    
	while(fout.good()) {
		getline(fout, date, ',');
    	getline(fout, country, ',');
    	getline(fout, Confirmed, ',');
    	getline(fout, Deaths, ',');
    	getline(fout, Recovered, ',');
    	getline(fout, Active, ',');
    	getline(fout, New_cases, ',');
    	getline(fout, New_deaths, ',');
    	getline(fout, New_recover, ',');
    	getline(fout, WHO_region, '\n');
    	
		i++;
		if(i == 1) {
			cout << date << " " << country << " " << Confirmed << " " << Deaths << " " << Recovered << " " << Active << " " << "NCases" << " " <<
		"NDeaths" << " " << "NRecover" << " " << WHO_region << endl;
		}
		
		else 
			ob1.Insert_Data(date, country, Confirmed, Deaths, Recovered, Active, New_cases, New_deaths, New_recover, WHO_region);
	}
	
	
	fout.close();
	
	
	// function calling	
	ob1.Display_Data(ob1.Get_head());
	
	system("Pause");
	system("cls");
	
	
	
	int num = 0;
	
	while(true) {
		cout << "1.Enter country name and date to search data" << endl << "2.Enter country name and date to Delete data "
			<< endl << "3. Diaplsy Data \n 4.Exit \n Enteryour choice: ";
			cin >> num;
			switch(num) {
				case 1:
					cout << "Enter Country name: ";
					fflush(stdin);
					getline(cin, country);
					cout << "Enter Date(dd/mm/yy): ";
					fflush(stdin);
					getline(cin, country);
					ob1.Binary_Search(ob1.Get_head(), date, country);
					break;
				case 2:
					cout << "Enter Country name: ";
					fflush(stdin);
					getline(cin, country);
					cout << "Enter Date(dd/mm/yy): ";
					fflush(stdin);
					getline(cin, country);
					ob1.Delete_Data(ob1.Get_head(), date, country);
					break;
				case 3:
					ob1.Display_Data(ob1.Get_head());
					break;
				case 4:
					return;
			}
			system("pause");
			system("cls");
	}	
	
	
	system("pause");
	
	return; // return back
}



