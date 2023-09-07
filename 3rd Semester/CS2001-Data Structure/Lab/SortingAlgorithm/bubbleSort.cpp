#include<iostream>
using namespace std;

void bubbleSort(int arr[], int size);
void swapingValues(int &a, int &b);

int main(){

    int size; 
    int arr[size];

    cout<<"Enter the size of the Array: ";
    cin>>size;
    cout<<"Enter the array Elements: ";
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }

    bubbleSort(arr, size);
    for (int i = 0; i < size; i++)
    {
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




void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if(arr[i]>arr[j])
            {
                swapingValues(arr[i], arr[j]);
                // int temp = arr[i];
                // arr[i] = arr[j];
                // arr[j] = temp;
            }
        }
        
    }
    
}