#include <iostream>
#include <string> 
using namespace std;

void swapingStrings(char &a, char &b);

int main(){
  string str;
  cout << "Enter the string to be sorted: ";
  getline(cin, str);
  int len = str.length();
  cout << "\n String before sorting: " << str << " \n";

  for (int i = 0; i < len; i++){

    for (int j = 0; j < len - 1; j++){
      if (str[j] > str[j + 1]){

        swapingStrings(str[j], str[j+1]);
      }
    }
  }

  cout << "\n String after sorting: " << str << " \n";
  return 0;
}

void swapingStrings(char &a, char &b)
{
  char temp = a;
  a = b;
  b = temp;
}
