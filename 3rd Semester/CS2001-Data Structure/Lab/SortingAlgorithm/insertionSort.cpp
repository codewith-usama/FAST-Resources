#include<iostream>
using namespace std;

void insertionSort(int arr[], int size);


int main(){

    // int size=6; 
    // int arr[size];

    // cout<<"Enter the size of the Array: ";
    // cin>>size;
    // cout<<"Enter the array Elements: ";
    // for (int i = 0; i < size; i++)
    // {
    //     /* code */
    //     cin>>arr[i];
    // }

    int arr[] = {-1, -5, 0, 3};

    insertionSort(arr, 4);

    for (int i = 0; i < 4; i++)
    {
        cout<<arr[i]<<" ";
    }
    

    

    return 0;
}


void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = arr[i]; // 3
        int j = i-1;   // 0

        while (j>=0 && arr[j]>temp)
        {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = temp;
        
    }

}
