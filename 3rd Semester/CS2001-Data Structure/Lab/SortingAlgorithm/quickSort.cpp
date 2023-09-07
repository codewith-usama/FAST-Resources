#include<iostream>
using namespace std;

int Partician(int arr[], int lb, int ub)
{
    int pivot = arr[lb];
    int start = lb;
    int end = ub; 


    while (start < end)
    {
        while (arr[start]<=pivot)
        {
            start++;
        }
        while (arr[end]>pivot)
        {
            end--;
        }

        if(start < end)
        {
            swap(arr[start], arr[end]);
        }
        
        
    }

    swap(arr[lb], arr[end]);
    return end;
    
}

void quickSort(int arr[], int lb, int ub)
{
    if(lb<ub)
    {
        int loc = Partician(arr, lb, ub);
        quickSort(arr, loc+1, ub);  
        quickSort(arr,lb,loc-1);
    }
}

void displayArrayValues(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}


int main(){

    int a[8] = {2, 6, 4, 5, 3, 7, -9, 0};
    
    quickSort(a, 0, 7);

    displayArrayValues(a, 8);

    // for (int i = 0; i < 8; i++)
    // {
    //     cout<<a[i]<<" ";
    // }
    

    return 0;
}
