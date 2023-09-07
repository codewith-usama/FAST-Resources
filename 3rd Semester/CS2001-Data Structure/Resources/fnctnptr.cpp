#include <iostream>  
using namespace std;  
/*
void printname(char *name)  
{  
    std::cout << "Name:" <<name<< std::endl;  
}  
  
int main()  
{  
    char x[30];  // array declaration  
    void (*ptr)(char*);  // function pointer declaration  
    ptr=printname;  // storing the address of printname in ptr.  
    std::cout << "Enter name: " << std::endl;  
    cin>>x;  
    cout<<x<<endl;  
    ptr(x);  // calling printname() function  
   return 0;  
} */
int add(int x , int y)  
{  
    return x+y;  
}  
int main()  
{  
 int (*funcptr)(int,int);  // Declaration of function pointer
 funcptr=add; // In this case we are pointing to the add function  

 int sum=funcptr(7,10);  
 std::cout << "Sum=" <<sum<< std::endl; 
 std::cout << "Sum=" <<&add<< std::endl; 
  return 0;  
}  
