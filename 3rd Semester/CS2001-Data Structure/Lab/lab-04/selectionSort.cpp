#include<iostream>
using namespace std;

void selectionSort(int arr[], int size);

int main(){

    int arr[6] = {5,3,2,9,7,0};

    // for (int i = 0; i < 5; i++)
    // {
    //     int min = i;
    //     for (int j = i+1; j < 6; j++)
    //     {
    //         if(arr[j]<arr[min])
    //         {
    //             min = j;
    //         }
    //     }

    //     if(min!=i)
    //     {
    //         // swap(arr[i],arr[min]);
    //         // Swapping values
    //         int temp = arr[i];
    //         arr[i] = arr[min];
    //         arr[min] = temp;
    //     }
        
    // }
    selectionSort(arr, 6);

    for (int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    

    return 0;
}


void selectionSort(int arr[], int size)
{
        for (int i = 0; i < size-1; i++)
        {
            int min = i;
            for (int j = i+1; j < size; j++)
            {
                if(arr[j]<arr[min])
                {
                     min = j;
                }
            }

            if(min!=i)
            {
                // swap(arr[i],arr[min]);
                // Swapping values
                int temp = arr[i];
                arr[i] = arr[min];
                arr[min] = temp;
            }
        
    }
}