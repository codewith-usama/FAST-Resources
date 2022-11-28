#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
class admin
{
public:
    char id[20];
    char pass[20];
    static int count;
    void setter()
    {
        cout<<"ENTER YOUR ID : "<<endl;
        cin.ignore();
        cin.getline(id,19);
        cout<<"ENTER YOUR PASSWORD : "<<endl;
        cin.ignore();
        cin.getline(pass,19);
    }
    int show()
    {
        cout<<"ID IS: "<<id<<endl;
        cout<<"PASSWORD IS : "<<pass<<endl;
    }
    int write_in_file();
	int read_from_file();
	void search(char *);
};
int admin::count=0;
void admin::search(char *n)
{
	ifstream fin;
	fin.open("admin",ios::in|ios::binary);
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		if(!strcmp(n,id))
		{
		count++;
		show();
	    } 
		fin.read((char*)this,sizeof(*this));
    }
	fin.close();
}
int admin::write_in_file()
{
	ofstream fout;
	fout.open("admin",ios::app|ios::binary);
	fout.write((char*)this,sizeof(*this));
	fout.close();
}
int admin::read_from_file()
{
	ifstream fin;
	fin.open("adminfile",ios::in|ios::binary);
	if(!fin)
	{
		
	}
	else
	{
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		show();
		fin.read((char*)this,sizeof(*this));
	}
	fin.close();
	}
}
class user
{
	public:
	char name[100];
	char cnic[14];
	char phonenum[12];
	static int count;	
	void setter()
	{
		cout<<"ENTER YOUR NAME "<<endl;
		cin.ignore();
		cin.getline(name,24);
		cout<<"ENTER THE CNIC NUMBER "<<endl;
		cin.ignore();
		cin.getline(cnic,13);
		cout<<"ENTER PHONE-NUMBER "<<endl;
		cin.ignore();
		cin.getline(phonenum,13);
	}
	int show()
	{
		cout<<"NAME : "<<name<<endl;
		cout<<"CNIC NUMBER : "<<cnic<<endl;
		cout<<"PHONE-NUMBER : "<<phonenum<<endl;
	}
	int write_in_file();
	int read_from_file();
	void search(char *);	
};
int user::count=0;
void user::search(char *n)
{
	ifstream fin;
	fin.open("userfile",ios::in|ios::binary);
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		if(!strcmp(n,name))
		{
		count++;
		show();
	    } 
		fin.read((char*)this,sizeof(*this));
    }
	fin.close();
}
int user::write_in_file()
{
	ofstream fout;
	fout.open("userfile",ios::app|ios::binary);
	fout.write((char*)this,sizeof(*this));
	fout.close();
}
int user::read_from_file()
{
	ifstream fin;
	fin.open("userfile",ios::in|ios::binary);
	if(!fin)
	{
		
	}
	else
	{
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		show();
		fin.read((char*)this,sizeof(*this));
	}
	fin.close();
	}
}
class parcel
{
	public:
		parcel()
		{
			cout<<"*************HERE YOU CAN EASILY BOOK PARCEL***************"<<endl<<endl;
		}
};
class parceltrains:public parcel
{
	public:
		int selectclass;
		void tezgam_details();
		void bolanmail_details();
		parceltrains()
		{
			cout<<"|*|*|*|*|*|*|*|*|*|*|*|*|*|*| THE TRAINS WHICH ARE AVAILABLE RIGHT NOW ARE |*|*|*|*|*|*|*|*|*|*|*|*|*|*|"<<endl<<endl;
	        cout<<"1: TEZGAM (FIRST-CLASS)"<<endl<<"2: BOLAN-MAIL (SECOND-CLASS) "<<endl<<endl;
	        cout<<"NOW SELECT THE TRAIN WITH THE CLASS "<<endl;
			cin>>selectclass;
			if(selectclass==1)
			{
				cout<<endl;
				tezgam_details();
			}
			else if(selectclass==2)
			{
				cout<<endl;
				bolanmail_details();
			}
	    } 
};
void parceltrains::tezgam_details()
{
	int select;
	int destination;
	cout<<"*************NOW SLELECT THE STATION FROM WHERE YOU WANT TO DEPARTURE********************** "<<endl<<endl;
	cout<<"1: KARACHI\t\t || (10.00 AM)"<<endl<<"2: QUETTA\t\t || (12.00 PM)"<<endl<<"3: LAHORE\t\t || (2.00 PM)"<<endl<<"4: ISLAMABAD\t\t || (5.00 PM)"<<endl<<"5: MULTAN\t\t || (9.00 PM)"<<endl<<"6: PESHAWAR\t\t || (10.00 PM)"<<endl<<endl;
	cin>>select;
	if(select==1)
	{
		cout<<"THE ROUTES WILL BE "<<endl;
		cout<<"1: KARACHI \t(DEPARTURE,10.00 AM)"<<endl<<"2: HYDERABAD \t(12.00 PM)"<<endl<<"3: LARKANA \t(3.00 PM)"<<endl<<"4: SAKHUR \t(4.00 PM)"<<endl<<"5: SIALKOT \t(7.00 PM)"<<endl<<"6: BAHAWALPUR \t(10.00 PM)"<<endl<<"7: LAHORE \t(12.00 AM)"<<endl<<"8: QUETTA \t(5.00 AM)"<<endl<<"9: ISLAMABAD \t(10.00 AM)"<<endl<<"10: PESHAWAR \t(1.00 PM)"<<endl;
		cin>>destination;
	}
	else if(select==2)
	{
		cout<<"THE ROUTES WILL BE "<<endl;
		cout<<"1: QUETTA \t(DEPARTURE,12.00 PM)"<<endl<<"2: PESHAWAR \t(3.00 PM)"<<endl<<"3: PINDI \t(8.00 PM)"<<endl<<"4: LAHORE \t(11.00 PM)"<<endl<<"5: SAILKOT \t(5.00 AM)"<<endl<<"6: LARKANA \t(8.00 AM)"<<endl<<"7: HYDERABAD \t(10.00 AM)"<<endl<<"8: KARACHI \t(12.00 PM)"<<endl;
		cin>>destination;
	}
	else if(select==3)
	{
		cout<<"THE ROUTES WILL BE "<<endl;
		cout<<"1: LAHORE \t(DEPARTURE,2.00 PM)"<<endl<<"2: ISLAMABAD \t(6.00 PM)"<<endl<<"3: PESHAWAR \t(11.00 PM)"<<endl<<"4: QUETTA \t(3.00 AM)"<<endl<<"5: MULTAN \t(11.00 AM)"<<endl<<"6: SAKHUR \t(1.00 PM)"<<endl<<"7: KARACHI \t(5.00 PM)"<<endl;
		cin>>destination;
	}
	else if(select==4)
	{
		cout<<"THE ROUTES WILL BE "<<endl;
		cout<<"1: ISLAMABAD \t(DEPARTURE,5.00 PM)"<<endl<<"2: PESHAWAR \t(9.00 PM)"<<endl<<"3: QUETTA \t(1.00 AM)"<<endl<<"4: LAHORE \t(6.00 AM)"<<endl<<"5: MULTAN \t(8.00 AM)"<<endl<<"6: SAKHUR \t(1.00 PM)"<<endl<<"7: KARACHI \t(5.00 PM)"<<endl;
		cin>>destination;
	}
	else if(select==5)
	{
		cout<<"THE ROUTES WILL BE "<<endl;
		cout<<"1: MULTAN \t(DEPARTURE,9.00 PM)"<<endl<<"2: ISLAMABAD \t(12.00 AM)"<<endl<<"3: PESHAWAR \t(6.00 AM)"<<endl<<"4: QUETTA \t(11.00 AM)"<<endl<<"5: MULTAN \t(6.00 PM)"<<endl<<"6: SAKHUR \t(10.00 PM)"<<endl<<"7: KARACHI \t(3.00 AM)"<<endl;
		cin>>destination;
	}
	else if(select==6)
	{
		cout<<"THE ROUTES WILL BE "<<endl;
		cout<<"1: PESHAWAR \t(DEPARTURE,10.00 PM)"<<endl<<"2: QUETTA \t(2.00 AM)"<<endl<<"3: ISLAMABAD \t(7.00 AM)"<<endl<<"4: LAHORE \t(11.00 AM)"<<endl<<"5: MULTAN \t(1.00 PM)"<<endl<<"6: SAKHUR \t(1.00 PM)"<<endl<<"8: KARACHI \t(5.00 PM)"<<endl;
		cin>>destination;
	}
}
void parceltrains::bolanmail_details()
{
	int select;
	int destination;
	cout<<"*********************NOW SLELECT THE STATION FROM WHERE YOU WANT TO DEPARTURE ****************************"<<endl;
	cout<<"1: KARACHI\t\t || (10.00 AM)"<<endl<<"2: QUETTA\t\t || (12.00 PM)"<<endl<<"3: LAHORE\t\t || (2.00 PM)"<<endl<<"4: ISLAMABAD\t\t || (5.00 PM)"<<endl<<"5: MULTAN\t\t || (9.00 PM)"<<endl<<"6: PESHAWAR\t\t || (10.00 PM)"<<endl<<endl;
	cin>>select;
	if(select==1)
	{
		cout<<"THE ROUTES WILL BE "<<endl;
		cout<<"1: KARACHI \t(DEPARTURE,10.00 AM)"<<endl<<"2: HYDERABAD \t(12.00 PM)"<<endl<<"3: LARKANA \t(3.00 PM)"<<endl<<"4: SAKHUR \t(4.00 PM)"<<endl<<"5: SIALKOT \t(7.00 PM)"<<endl<<"6: BAHAWALPUR \t(10.00 PM)"<<endl<<"7: LAHORE \t(12.00 AM)"<<endl<<"8: QUETTA \t(5.00 AM)"<<endl<<"9: ISLAMABAD \t(10.00 AM)"<<endl<<"10: PESHAWAR \t(1.00 PM)"<<endl;
		cin>>destination;
	}
	else if(select==2)
	{
		cout<<"THE ROUTES WILL BE "<<endl;
		cout<<"1: QUETTA \t(DEPARTURE,12.00 PM)"<<endl<<"2: PESHAWAR \t(3.00 PM)"<<endl<<"3: PINDI \t(8.00 PM)"<<endl<<"4: LAHORE \t(11.00 PM)"<<endl<<"5: SAILKOT \t(5.00 AM)"<<endl<<"6: LARKANA \t(8.00 AM)"<<endl<<"7: HYDERABAD \t(10.00 AM)"<<endl<<"8: KARACHI \t(12.00 PM)"<<endl;
		cin>>destination;
	}
	else if(select==3)
	{
		cout<<"THE ROUTES WILL BE "<<endl;
		cout<<"1: LAHORE \t(DEPARTURE,2.00 PM)"<<endl<<"2: ISLAMABAD \t(6.00 PM)"<<endl<<"3: PESHAWAR \t(11.00 PM)"<<endl<<"4: QUETTA \t(3.00 AM)"<<endl<<"5: MULTAN \t(11.00 AM)"<<endl<<"6: SAKHUR \t(1.00 PM)"<<endl<<"7: KARACHI \t(5.00 PM)"<<endl;
		cin>>destination;
	}
	else if(select==4)
	{
		cout<<"THE ROUTES WILL BE "<<endl;
		cout<<"1: ISLAMABAD \t(DEPARTURE,5.00 PM)"<<endl<<"2: PESHAWAR \t(9.00 PM)"<<endl<<"3: QUETTA \t(1.00 AM)"<<endl<<"4: LAHORE \t(6.00 AM)"<<endl<<"5: MULTAN \t(8.00 AM)"<<endl<<"6: SAKHUR \t(1.00 PM)"<<endl<<"7: KARACHI \t(5.00 PM)"<<endl;
		cin>>destination;
	}
	else if(select==5)
	{
		cout<<"THE ROUTES WILL BE "<<endl;
		cout<<"1: MULTAN \t(DEPARTURE,9.00 PM)"<<endl<<"2: ISLAMABAD \t(12.00 AM)"<<endl<<"3: PESHAWAR \t(6.00 AM)"<<endl<<"4: QUETTA \t(11.00 AM)"<<endl<<"5: MULTAN \t(6.00 PM)"<<endl<<"6: SAKHUR \t(10.00 PM)"<<endl<<"7: KARACHI \t(3.00 AM)"<<endl;
		cin>>destination;
	}
	else if(select==6)
	{
		cout<<"THE ROUTES WILL BE "<<endl;
		cout<<"1: PESHAWAR \t(DEPARTURE,10.00 PM)"<<endl<<"2: QUETTA \t(2.00 AM)"<<endl<<"3: ISLAMABAD \t(7.00 AM)"<<endl<<"4: LAHORE \t(11.00 AM)"<<endl<<"5: MULTAN \t(1.00 PM)"<<endl<<"6: SAKHUR \t(1.00 PM)"<<endl<<"8: KARACHI \t(5.00 PM)"<<endl;
		cin>>destination;
	}
}
class reservation_of_parcel:public parceltrains
{
	public:
		float weight;
		float total;
		int day,month,year;
		int day1,month1,year1;
		void getreserve()
		{
			cout<<"ENETR THE WEIGHT OF THE PARCEL : "<<endl;
			cin>>weight;
			cout<<"ENTER THE DAY OF RESERVATION : "<<endl;
			cin>>day;
			cout<<"ENTER THE MONTH OF RESERVATION : "<<endl;
			cin>>month;
			cout<<"ENTER THE YEAR OF RESERVATION : "<<endl;
			cin>>year;
			if(selectclass==1)
			{
				total=1000*weight;
			}
			else if(selectclass==2)
			{
				total=500*weight;
			}
			if(day>=30&&month>11)
			{
				day1=2;
				month1=1;
				year1=++year;
			}
			else if(day>=30)
			{
				day1=2;
				month1=month+1;
				year1=year;
			}
			else 
			{
				day1=day+2;
				month1=month;
				year1=year;
			}
		}
		void display()
		{
			cout<<"=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.="<<endl;
            cout<<"*********************************************************"<<endl;
			cout<<"	THE PARCEL RECIVED BY THE RAILWAY AT DATE : "<<day<<"/"<<month<<"/"<<year<<endl;
			cout<<" YOUR PARCEL WILL BE REACHED AT "<<day1<<"/"<<month1<<"/"<<year1<<endl;
			cout<<" THE TOTAL AMOUNT WILL BE : "<<total<<endl;
			cout<<"=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.="<<endl;
            cout<<"*********************************************************"<<endl<<endl<<endl;
		}
};
class passenger
{
	public:
		passenger()
		{
			cout<<"|*|*|*|*|*|*|*|*|*|*|*|*|*|*|HERE YOU CAN EASILY BOOK YOUR SEATS |*|*|*|*|*|*|*|*|*|*|*|*|*|*|"<<endl<<endl<<endl;
		}
};
class passengertrains:public passenger
{
	public:
		int selectclass;
		void tezgam_details();
		void bolanmail_details();
		void karachiexpress_details();
		passengertrains()
		{
			cout<<"***************THE TRAINS WHICH ARE AVAILABLE RIGHT NOW ARE****************"<<endl<<endl;
	        cout<<"1: TEZGAM (FIRST-CLASS)"<<endl<<"2: BOLAN-MAIL (SECOND-CLASS) "<<endl<<"3: KARACHI-EXPRESS (THIRD-CLASS)"<<endl<<endl<<endl;
	        cout<<"NOW SELECT THE TRAIN WITH THE CLASS "<<endl;
			cin>>selectclass;
			if(selectclass==1)
			{
				cout<<endl;
				tezgam_details();
			}
			else if(selectclass==2)
			{
				cout<<endl;
				bolanmail_details();
			}
			else if(selectclass==3)
			{
				cout<<endl;
				karachiexpress_details();
			}
		}
};
void passengertrains::tezgam_details()
{
	int select;
	int destination;
	cout<<"==============NOW SLELECT THE STATION FROM WHERE YOU WANT TO DEPARTURE================ "<<endl<<endl;
	cout<<"1: KARACHI\t\t || (10.00 AM)"<<endl<<"2: QUETTA\t\t || (12.00 PM)"<<endl<<"3: LAHORE\t\t || (2.00 PM)"<<endl<<"4: ISLAMABAD\t\t || (5.00 PM)"<<endl<<"5: MULTAN\t\t || (9.00 PM)"<<endl<<"6: PESHAWAR\t\t || (10.00 PM)"<<endl<<endl;
	cin>>select;
	if(select==1)
	{
		cout<<"THE ROUTES WILL BE "<<endl;
		cout<<"1: KARACHI \t(DEPARTURE,10.00 AM)"<<endl<<"2: HYDERABAD \t(12.00 PM)"<<endl<<"3: LARKANA \t(3.00 PM)"<<endl<<"4: SAKHUR \t(4.00 PM)"<<endl<<"5: SIALKOT \t(7.00 PM)"<<endl<<"6: BAHAWALPUR \t(10.00 PM)"<<endl<<"7: LAHORE \t(12.00 AM)"<<endl<<"8: QUETTA \t(5.00 AM)"<<endl<<"9: ISLAMABAD \t(10.00 AM)"<<endl<<"10: PESHAWAR \t(1.00 PM)"<<endl;
		cin>>destination;
	}
	else if(select==2)
	{
		cout<<"THE ROUTES WILL BE "<<endl;
		cout<<"1: QUETTA \t(DEPARTURE,12.00 PM)"<<endl<<"2: PESHAWAR \t(3.00 PM)"<<endl<<"3: PINDI \t(8.00 PM)"<<endl<<"4: LAHORE \t(11.00 PM)"<<endl<<"5: SAILKOT \t(5.00 AM)"<<endl<<"6: LARKANA \t(8.00 AM)"<<endl<<"7: HYDERABAD \t(10.00 AM)"<<endl<<"8: KARACHI \t(12.00 PM)"<<endl;
		cin>>destination;
	}
	else if(select==3)
	{
		cout<<"THE ROUTES WILL BE "<<endl;
		cout<<"1: LAHORE \t(DEPARTURE,2.00 PM)"<<endl<<"2: ISLAMABAD \t(6.00 PM)"<<endl<<"3: PESHAWAR \t(11.00 PM)"<<endl<<"4: QUETTA \t(3.00 AM)"<<endl<<"5: MULTAN \t(11.00 AM)"<<endl<<"6: SAKHUR \t(1.00 PM)"<<endl<<"7: KARACHI \t(5.00 PM)"<<endl;
		cin>>destination;
	}
	else if(select==4)
	{
		cout<<"THE ROUTES WILL BE "<<endl;
		cout<<"1: ISLAMABAD \t(DEPARTURE,5.00 PM)"<<endl<<"2: PESHAWAR \t(9.00 PM)"<<endl<<"3: QUETTA \t(1.00 AM)"<<endl<<"4: LAHORE \t(6.00 AM)"<<endl<<"5: MULTAN \t(8.00 AM)"<<endl<<"6: SAKHUR \t(1.00 PM)"<<endl<<"7: KARACHI \t(5.00 PM)"<<endl;
		cin>>destination;
	}
	else if(select==5)
	{
		cout<<"THE ROUTES WILL BE "<<endl;
		cout<<"1: MULTAN \t(DEPARTURE,9.00 PM)"<<endl<<"2: ISLAMABAD \t(12.00 AM)"<<endl<<"3: PESHAWAR \t(6.00 AM)"<<endl<<"4: QUETTA \t(11.00 AM)"<<endl<<"5: MULTAN \t(6.00 PM)"<<endl<<"6: SAKHUR \t(10.00 PM)"<<endl<<"7: KARACHI \t(3.00 AM)"<<endl;
		cin>>destination;
	}
	else if(select==6)
	{
		cout<<"THE ROUTES WILL BE "<<endl;
		cout<<"1: PESHAWAR \t(DEPARTURE,10.00 PM)"<<endl<<"2: QUETTA \t(2.00 AM)"<<endl<<"3: ISLAMABAD \t(7.00 AM)"<<endl<<"4: LAHORE \t(11.00 AM)"<<endl<<"5: MULTAN \t(1.00 PM)"<<endl<<"6: SAKHUR \t(1.00 PM)"<<endl<<"8: KARACHI \t(5.00 PM)"<<endl;
		cin>>destination;
	}
}
void passengertrains::bolanmail_details()
{
	int select;
	int destination;
	cout<<"NOW SLELECT THE STATION FROM WHERE YOU WANT TO DEPARTURE "<<endl;
	cout<<"1: KARACHI\t\t || (10.00 AM)"<<endl<<"2: QUETTA\t\t || (12.00 PM)"<<endl<<"3: LAHORE\t\t || (2.00 PM)"<<endl<<"4: ISLAMABAD\t\t || (5.00 PM)"<<endl<<"5: MULTAN\t\t || (9.00 PM)"<<endl<<"6: PESHAWAR\t\t || (10.00 PM)"<<endl<<endl;
	cin>>select;
	if(select==1)
	{
		cout<<"THE ROUTES WILL BE "<<endl;
		cout<<"1: KARACHI \t(DEPARTURE,10.00 AM)"<<endl<<"2: HYDERABAD \t(12.00 PM)"<<endl<<"3: LARKANA \t(3.00 PM)"<<endl<<"4: SAKHUR \t(4.00 PM)"<<endl<<"5: SIALKOT \t(7.00 PM)"<<endl<<"6: BAHAWALPUR \t(10.00 PM)"<<endl<<"7: LAHORE \t(12.00 AM)"<<endl<<"8: QUETTA \t(5.00 AM)"<<endl<<"9: ISLAMABAD \t(10.00 AM)"<<endl<<"10: PESHAWAR \t(1.00 PM)"<<endl;
		cin>>destination;
	}
	else if(select==2)
	{
		cout<<"THE ROUTES WILL BE "<<endl;
		cout<<"1: QUETTA \t(DEPARTURE,12.00 PM)"<<endl<<"2: PESHAWAR \t(3.00 PM)"<<endl<<"3: PINDI \t(8.00 PM)"<<endl<<"4: LAHORE \t(11.00 PM)"<<endl<<"5: SAILKOT \t(5.00 AM)"<<endl<<"6: LARKANA \t(8.00 AM)"<<endl<<"7: HYDERABAD \t(10.00 AM)"<<endl<<"8: KARACHI \t(12.00 PM)"<<endl;
		cin>>destination;
	}
	else if(select==3)
	{
		cout<<"THE ROUTES WILL BE "<<endl;
		cout<<"1: LAHORE \t(DEPARTURE,2.00 PM)"<<endl<<"2: ISLAMABAD \t(6.00 PM)"<<endl<<"3: PESHAWAR \t(11.00 PM)"<<endl<<"4: QUETTA \t(3.00 AM)"<<endl<<"5: MULTAN \t(11.00 AM)"<<endl<<"6: SAKHUR \t(1.00 PM)"<<endl<<"7: KARACHI \t(5.00 PM)"<<endl;
		cin>>destination;
	}
	else if(select==4)
	{
		cout<<"THE ROUTES WILL BE "<<endl;
		cout<<"1: ISLAMABAD \t(DEPARTURE,5.00 PM)"<<endl<<"2: PESHAWAR \t(9.00 PM)"<<endl<<"3: QUETTA \t(1.00 AM)"<<endl<<"4: LAHORE \t(6.00 AM)"<<endl<<"5: MULTAN \t(8.00 AM)"<<endl<<"6: SAKHUR \t(1.00 PM)"<<endl<<"7: KARACHI \t(5.00 PM)"<<endl;
		cin>>destination;
	}
	else if(select==5)
	{
		cout<<"THE ROUTES WILL BE "<<endl;
		cout<<"1: MULTAN \t(DEPARTURE,9.00 PM)"<<endl<<"2: ISLAMABAD \t(12.00 AM)"<<endl<<"3: PESHAWAR \t(6.00 AM)"<<endl<<"4: QUETTA \t(11.00 AM)"<<endl<<"5: MULTAN \t(6.00 PM)"<<endl<<"6: SAKHUR \t(10.00 PM)"<<endl<<"7: KARACHI \t(3.00 AM)"<<endl;
		cin>>destination;
	}
	else if(select==6)
	{
		cout<<"THE ROUTES WILL BE "<<endl;
		cout<<"1: PESHAWAR \t(DEPARTURE,10.00 PM)"<<endl<<"2: QUETTA \t(2.00 AM)"<<endl<<"3: ISLAMABAD \t(7.00 AM)"<<endl<<"4: LAHORE \t(11.00 AM)"<<endl<<"5: MULTAN \t(1.00 PM)"<<endl<<"6: SAKHUR \t(1.00 PM)"<<endl<<"8: KARACHI \t(5.00 PM)"<<endl;
		cin>>destination;
	}
}
void passengertrains::karachiexpress_details()
{
	int select;
	int destination;
	cout<<"NOW SLELECT THE STATION FROM WHERE YOU WANT TO DEPARTURE "<<endl;
	cout<<"1: KARACHI\t\t || (10.00 AM)"<<endl<<"2: QUETTA\t\t || (12.00 PM)"<<endl<<"3: LAHORE\t\t || (2.00 PM)"<<endl<<"4: ISLAMABAD\t\t || (5.00 PM)"<<endl<<"5: MULTAN\t\t || (9.00 PM)"<<endl<<"6: PESHAWAR\t\t || (10.00 PM)"<<endl<<endl;
	cin>>select;
	if(select==1)
	{
		cout<<"THE ROUTES WILL BE "<<endl;
		cout<<"1: KARACHI \t(DEPARTURE,10.00 AM)"<<endl<<"2: HYDERABAD \t(12.00 PM)"<<endl<<"3: LARKANA \t(3.00 PM)"<<endl<<"4: SAKHUR \t(4.00 PM)"<<endl<<"5: SIALKOT \t(7.00 PM)"<<endl<<"6: BAHAWALPUR \t(10.00 PM)"<<endl<<"7: LAHORE \t(12.00 AM)"<<endl<<"8: QUETTA \t(5.00 AM)"<<endl<<"9: ISLAMABAD \t(10.00 AM)"<<endl<<"10: PESHAWAR \t(1.00 PM)"<<endl;
		cin>>destination;
	}
	else if(select==2)
	{
		cout<<"THE ROUTES WILL BE "<<endl;
		cout<<"1: QUETTA \t(DEPARTURE,12.00 PM)"<<endl<<"2: PESHAWAR \t(3.00 PM)"<<endl<<"3: PINDI \t(8.00 PM)"<<endl<<"4: LAHORE \t(11.00 PM)"<<endl<<"5: SAILKOT \t(5.00 AM)"<<endl<<"6: LARKANA \t(8.00 AM)"<<endl<<"7: HYDERABAD \t(10.00 AM)"<<endl<<"8: KARACHI \t(12.00 PM)"<<endl;
		cin>>destination;
	}
	else if(select==3)
	{
		cout<<"THE ROUTES WILL BE "<<endl;
		cout<<"1: LAHORE \t(DEPARTURE,2.00 PM)"<<endl<<"2: ISLAMABAD \t(6.00 PM)"<<endl<<"3: PESHAWAR \t(11.00 PM)"<<endl<<"4: QUETTA \t(3.00 AM)"<<endl<<"5: MULTAN \t(11.00 AM)"<<endl<<"6: SAKHUR \t(1.00 PM)"<<endl<<"7: KARACHI \t(5.00 PM)"<<endl;
		cin>>destination;
	}
	else if(select==4)
	{
		cout<<"THE ROUTES WILL BE "<<endl;
		cout<<"1: ISLAMABAD \t(DEPARTURE,5.00 PM)"<<endl<<"2: PESHAWAR \t(9.00 PM)"<<endl<<"3: QUETTA \t(1.00 AM)"<<endl<<"4: LAHORE \t(6.00 AM)"<<endl<<"5: MULTAN \t(8.00 AM)"<<endl<<"6: SAKHUR \t(1.00 PM)"<<endl<<"7: KARACHI \t(5.00 PM)"<<endl;
		cin>>destination;
	}
	else if(select==5)
	{
		cout<<"THE ROUTES WILL BE "<<endl;
		cout<<"1: MULTAN \t(DEPARTURE,9.00 PM)"<<endl<<"2: ISLAMABAD \t(12.00 AM)"<<endl<<"3: PESHAWAR \t(6.00 AM)"<<endl<<"4: QUETTA \t(11.00 AM)"<<endl<<"5: MULTAN \t(6.00 PM)"<<endl<<"6: SAKHUR \t(10.00 PM)"<<endl<<"7: KARACHI \t(3.00 AM)"<<endl;
		cin>>destination;
	}
	else if(select==6)
	{
		cout<<"THE ROUTES WILL BE "<<endl;
		cout<<"1: PESHAWAR \t(DEPARTURE,10.00 PM)"<<endl<<"2: QUETTA \t(2.00 AM)"<<endl<<"3: ISLAMABAD \t(7.00 AM)"<<endl<<"4: LAHORE \t(11.00 AM)"<<endl<<"5: MULTAN \t(1.00 PM)"<<endl<<"6: SAKHUR \t(1.00 PM)"<<endl<<"8: KARACHI \t(5.00 PM)"<<endl;
		cin>>destination;
	}
}
class reser:public passengertrains
{
public:
	int no_of_seats;
	string name[1000];
	int age[1000];
	int category[1000];
	int i,date,month,year;
	static int total;
	static int sum;
      void getresdet()
    {
    	cout<<"!^!^!^!^!^!^!^!^!^!^!^!^!^!^!^! HERE YOU CAN RESERVE THE SEATS OF THE TRAIN !^!^!^!^!^!^!^!^!^!^!^!^!^!^!^!"<<endl<<endl;
    	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-* HERE WE PROVIDE CONCESSION FOR SOME CITIZENS *-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl<<endl;
        cout<<"1: MILITARY\t\t\t\t30%"<<endl<<"2: CITIZEN 60+\t\t\t\t50%"<<endl<<"3: CHILDEREN BELOW 5 YEAR\t\t60%"<<"4: NONE"<<endl<<endl;
        cout<<"ENTER THE NUMBER OF SEATS YOU REQUIRED "<<endl;
        cin>>no_of_seats;
        cout<<endl;
        for(i=0;i<no_of_seats;i++)
        {
            cout<<"ENTER THE NAME OF THE PASSENEGER NO "<<i+1<<endl;
            getline(cin>>ws,name[i]);
            cout<<"ENTER THE AGE OF PASSENGER NO "<<i+1<<endl;
            cin>>age[i];
            cout<<"ENTER THE CATEGORY NUMBER OF THE PASSENGER NO "<<i+1<<endl;
            cin>>category[i];
            cout<<endl<<endl;
        }
        if(selectclass==1)
        {
        	total=5000*no_of_seats;
		}
		else if(selectclass==2)
		{
			total=3000*no_of_seats;
		}
		else if(selectclass==3)
		{
			total=2000*no_of_seats;
		}
        cout<<"ENTER THE DEPARTURE DATE OF BOOKING "<<endl;
        cout<<"DATE : ";
        cin>>date;
        cout<<"MONTH : ";
        cin>>month;
        cout<<"YEAR : ";
        cin>>year;
        cout<<endl;
        for(i=0;i<no_of_seats;i++)
        {
        	if(selectclass==1)
        	{
        		if(category[i]==1)
        		{
        			sum=sum+(5000*0.3);
				}
				else if(category[i]==2)
				{
					sum=sum+(5000*0.5);
				}
				else if(category[i]==3)
				{
					sum=sum+(5000*0.6);
				}
				else if(category[i]==4)
				{
					sum=sum+5000;
				}
			}
			else if(selectclass==2)
			{
        		if(category[i]==1)
        		{
        			sum=sum+(3000*0.3);
				}
				else if(category[i]==2)
				{
					sum=sum+(3000*0.5);
				}
				else if(category[i]==3)
				{
					sum=sum+(3000*0.6);
				}
				else if(category[i]==4)
				{
					sum=sum+3000;
				}

			}
			else if(selectclass==3)
			{
				if(category[i]==1)
        		{
        			sum=sum+(2000*0.3);
				}
				else if(category[i]==2)
				{
					sum=sum+(2000*0.5);
				}
				else if(category[i]==3)
				{
					sum=sum+(2000*0.6);
				}
				else if(category[i]==4)
				{
					sum=sum+2000;
				}
			}
		}
		total=total-sum;
}
 void displayresdet()
    {
        cout<<"=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.="<<endl;
        cout<<"*********************************************************"<<endl;
        for(i=0;i<no_of_seats;i++)
        {
        cout<<"THE NAME OF THE PASSENGER NO "<<i+1<<" WILL BE : "<<name[i]<<endl;
        cout<<"THE AGE OF THE PASSENGER NO "<<i+1<<" WILL BE : "<<age[i]<<endl;
        cout<<"THE DATE OF THE DEPARTURE WILL BE "<<date<<"/"<<month<<"/"<<year<<endl;
        cout<<"=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.="<<endl;
        cout<<"*********************************************************"<<endl<<endl;
        }
        cout<<"THE TOTAL AMOUNT OF "<<no_of_seats<<"PASSENGERS WILL BE "<<total<<endl;
    }
};int reser::sum;
int reser::total;
struct menuItemType
{
	string menuItem;
	double menuPrice;
	int menuquantity;
}menuList;
class Menu 
{
	int choice;
	static int bill;
	static char i;
	public:
	void cal_bill() { // to calculate and show the bill
	while(i == 'y')
	{
	cout << "Press 1-8 for order anything: "<<endl;
	cin >> choice;
	cout << "Please Enter Quantity: "<<endl;
	cin >> menuList.menuquantity;
	switch(choice)
	{
		case 1:
			cout << "\nChicken biryani Order Placed! ";
			menuList.menuPrice += (menuList.menuquantity * 200);
			cout << "\nCurrent Bill: Rs" << menuList.menuPrice; 
			cout << "\nDo u want to order anything else? y/n: ";
			cin >> i;
			system("cls");
			Show_Menu();
			if (i == 'n')
				i = 'n';
			break;
		case 2:
			cout << "\nWater bottle large Order Placed! " ;
			menuList.menuPrice += (menuList.menuquantity * 50);
			cout << "\nCurrent Bill: Rs" << menuList.menuPrice; 
			cout << "\nDo u want to order anything else? y/n: ";
			cin >> i;
			system("cls");
			Show_Menu();
			if (i == 'n')
				i = 'n';
			break;
		case 3:
			cout << "\nCoffe Order Placed! ";
			menuList.menuPrice += (menuList.menuquantity * 120);
			cout << "\nCurrent Bill: Rs" << menuList.menuPrice; 
			cout << "\nDo u want to order anything else? y/n: ";
			cin >> i;
			system("cls");
			Show_Menu();
			if (i == 'n')
				i = 'n';
			break;
		case 4:
			cout << "\nMutton  Order Placed! ";
			menuList.menuPrice += (menuList.menuquantity * 1000);
			cout << "\nCurrent Bill: Rs" << menuList.menuPrice; 
			cout << "\nDo u want to order anything else? y/n: ";
			cin >> i;
			system("cls");
			Show_Menu();
			if (i == 'n')
				i = 'n';
			break;
		case 5:
			cout << "\nChicken rolls  Order Placed! ";
			menuList.menuPrice += (menuList.menuquantity * 90);
			cout << "\nCurrent Bill: Rs" << menuList.menuPrice; 
			cout << "\nDo u want to order anything else? y/n: ";
			cin >> i;
			system("cls");
			Show_Menu();
			if (i == 'n')
				i = 'n';
			break;			
		case 6:
			cout << "\nFresh juices order Order Placed! ";
			menuList.menuPrice += (menuList.menuquantity * 80);
			cout << "\nCurrent Bill: Rs" << menuList.menuPrice; 
			cout << "\nDo u want to order anything else? y/n: ";
			cin >> i;
			system("cls");
			Show_Menu();
			if (i == 'n')
				i = 'n';
			break;
		case 7:
			cout << "\nwhite rice Order Placed! ";
			menuList.menuPrice += (menuList.menuquantity * 180);
			cout << "\nCurrent Bill: Rs" << menuList.menuPrice; 
			cout << "\nDo u want to order anything else? y/n: ";
			cin >> i;
			system("cls");
			Show_Menu();
			if (i == 'n')
				i = 'n';
			break;
		case 8:
			cout << "\nTea  Order Placed! ";
			menuList.menuPrice += (menuList.menuquantity * 35);
			cout << "\nCurrent Bill: Rs" << menuList.menuPrice; 
			cout << "\nDo u want to order anything else? y/n: ";
			cin >> i;
			system("cls");
			Show_Menu();
			if (i == 'n')
				i = 'n';
			break;
	}
}
}
		void Show_Menu() {
			cout << "**************Welcome trains mini cafe***********\n\nITEMS will be served. \n\n";
			cout <<"1.Chicken biryani \tRs-200"<<endl<<"2.Water bottle \t\tRs-50"<<endl<<"3.Coffee \t\tRs-120"<<endl<<"4.Mutton \t\tRs-1000"<<endl<<"5.Chicken rolls \tRs-90"<<endl<<"6.Fresh juices \t\tRs-80"<<endl<<"7.White rice \t\tRs-190"<<endl<<"8.Tea \t\t\tRs-35"<<endl;
		}
		Menu() {
			Show_Menu();
		}		
};
char Menu::i = 'y';
int Menu::bill = 0;          
int main()
{
	int select,temp;
	char a[100];
	cout<<"*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*LOGIN TO PAKISTAN RAILWAY ACCOUNT*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*"<<endl<<endl;
	cout<<"**************YOU WANT TO BOOK PESSENGER SEAT OR YOU WANT TO PARCEL SOMETHING OR YOU ARE ADMIN****************"<<endl;
	cout<<"1: PASSENGER "<<endl<<"2: PARCEL "<<endl<<"3: ADMIN "<<endl;
	cin>>select;
	if(select==1)
	{
		user ob1;
		cout<<"1: NEW USER"<<endl<<"2: OLD USER"<<endl;
		cin>>temp;
		if(temp==1)
		{
			cout<<endl<<endl;
		        ob1.setter();
		        ob1.write_in_file();
		}
		else if(temp==2)
		{
		cout<<"ENTER YOUR NAME "<<endl;
		cin.ignore();
		cin.getline(a,99);
		cout<<endl<<endl;
		user ob2;
		ob2.search(a);
	    }
	    cout<<endl<<endl;
	    reser r1;
	    r1.getresdet();
	    cout<<endl;
	    r1.displayresdet();
	    Menu m1;
	    m1.cal_bill();
	}
	else if(select==2)
	{
		user ob1;
		cout<<"1: NEW USER"<<endl<<"2: OLD USER"<<endl;
		cin>>temp;
		if(temp==1)
		{
		        ob1.setter();
		        ob1.write_in_file();
		}
		else if(temp==2)
		{
		cout<<"ENTER YOUR NAME "<<endl;
		cin.ignore();
		cin.getline(a,99);
		user ob2;
		ob2.search(a);
	    }
	    cout<<endl<<endl;
	    reservation_of_parcel r1;
	    r1.getreserve();
	    cout<<endl;
	    r1.display();
	}
	else if(select==3)
	{
		{
		admin ob1;
		cout<<"1: NEW ADMIN"<<endl<<"2: OLD ADMIN"<<endl;
		cin>>temp;
		if(temp==1)
		{
		        ob1.setter();
		        ob1.write_in_file();
		}
		else if(temp==2)
		{
		cout<<"ENTER YOUR ID "<<endl;
		cin.ignore();
		cin.getline(a,99);
		admin ob2;
		ob2.search(a);
	    }
	    
	    }	
	}
}
