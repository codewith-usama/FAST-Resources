#include<iostream>
#include<string.h>
using namespace std;

struct menu_type
{
	char item_type;
	string item_name;
	int price;	
};

   class Coffeeshop
{
	
		
		string name;
		menu_type
		
		menu[4]={{'z',"zinger",200},{'b',"biryani",70},{'d',"cofee",90},{'f',"bbq",150}};
		string order[5];
		
		public:
			void order_add()
			
			{
				int i;
				for(i=0;i<5;i++)
				
			{
					
					order[i]=menu[i]item_name;
				}
				
				}
				
			void fullfill_order()
			
			{
				cout<<"\nYOUR ORDER IS FULLFILED:"<<endl;
					
			}
				
			
			void food()
			{
				for (int i=0;i<4;i++)
				
				{
					
					if(menu[i].item_type=='f')
					
					cout<<"\nORDER BELONGS TO FOOD TYPE:"<<endl<<menu[i].item_name;
				}
					}
				
				
				void drink()
				
				{
					for(int i=0;i<3;i++)
					
						{
							
						if(menu[i].item_type=='d')
						{
						cout<<"\nORDER BELONGS TO DRINK TYPE:"<<endl<<menu[i].item_name;
					    }
				
				}
			
			}
			
			void cheap()
			
			{
				
			int minimum=500;
		    string cheapest;
		    for(int i=0;i<4;i++)
		    
			{
		    	if(menu[i].price<minimum)
				{
		    	cheapest=menu[i].item_name;	
				
				
				}
				
				cout<<"\ncheapest stuff!"<<endl;
			
			}
		    
	
	}
	
	
	
	void list()
	
	{
		int i;
		for(i=0;i<3;i++)
		
		
		{
//			
             
			cout<<endl<<"LIST"<<i+1<<":"<<order[i];
		
		
		}
	}
	
	
	int due_amount()
	
	{
		int total_amount;
		int i;
		for(i=0;i<8;i++)
		
		{
			total_amount=total_amount+menu[i].price;
		
		}
		
		return total_amount;
	
	}
	

};

int main()


{
	Coffeeshop ob1;
	ob1.list();
	
	cout<<"\nWHAT UH WANA TAKE:"<<endl;
	
	cout<<"\n1 food items."<<endl;
	cout<<"\n2 drink items."<<endl;
	
	cout<<"select your choice:"<<endl;
	
	int choice;
	cin>>choice;
	
	if(choice==1)
	
	{
			ob1.food();
		
			
			
	
}
	else if(choice==2)
	{
	
		ob1.drink();
}



	
	
	
	
	
	//ob1.drink();
//	ob1.food();
//	ob1.fullfill_order();
//	ob1.order_add();
//	ob1.cheap();
//	ob1.due_amount();
//    return 0;



}

