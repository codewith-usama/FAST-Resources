#include<iostream>
using namespace std;

void swapingValues(int &a, int &b);


void combSort(int a[], int size)
{
  int gape = size;
  while (gape != 1)
  {
    if(gape<1)
    gape = 1;

    gape = int(gape/1.3);

    for (int i = 0; i < size-gape; i++)
    {
      if(a[i]>a[i+gape])
      swapingValues(a[i], a[i+gape]);
    }
    
  }
  
}
int main(){

  // int arr  [7] = {-9,8,4,1,0,5,4};


  // combSort(arr, 7);

  for (int i = 0; i < 7; i++)
  {
    /* code */
    cout<<arr[i]<<" ";
  }
  

  return 0;
}

void swapingValues(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}