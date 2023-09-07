#include<iostream> 
#include<stdio.h> 
  
using namespace std; 
  
class Test 
{ 
    public: 
    
    Test() {
	cout<<"default constructor called";
	}
	 Test(int x, int y) {
	cout<<"parmeterized constructor called";
	}
	 
  //  Test(const Test &t) 
  //  { 
   //     cout<<"Copy constructor called "<<endl; 
   // } 
      
    Test& operator = (const Test &t)
    {
        cout<<"Assignment operator called "<<endl;
        return *this;
    } 
}; 
  
// Driver code
int main() 
{   Test t1;
    Test  t2(1,2); 
    t2 = t1;//assignment operator 
    Test t3(t1); //copy constructor
  //  Test t3=t1; //copy constructor
    
    return 0; 
} 
