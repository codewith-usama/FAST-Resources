#include <iostream>  
using namespace std;  
void function1()  
{  
    cout<<"function1 is called";  
}  
void function2(void (*funcptr)())  
{  
    funcptr();  
}  
int main()  
{  
  function2(function1);  
  return 0;  
}  
