#include <iostream>
using namespace std;

int main () {
   double* pvalue  = NULL; // Pointer initialized with null
   pvalue  = new double;   // Request memory for the variable
 int *p=new int[10]{1,2,3,4,5,6,7,8,9,0,};
 for(int a=0; a<10;a++){
 	cout<<p[a]<<endl;
 }
   *pvalue = 29494.99;     // Store value at allocated address
   cout << "Value of pvalue : " << *pvalue << endl;

   delete pvalue;         // free up the memory.

   return 0;
}
