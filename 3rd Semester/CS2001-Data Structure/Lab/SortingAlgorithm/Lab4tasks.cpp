#include<iostream>
using namespace std;

void insertionSort(int arr[], int size);
void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void quickSort(int arr[], int lb, int ub);
void combSort(int arr[], int n);
void swapingValues(int &a, int &b);


int main()
{

    int arr[6] = {9,3,6,1,2,3};
    int size=6; 
    // int arr[size];

    // cout<<"Enter the size of the Array: ";
    // cin>>size;
    // cout<<"Enter the array Elements: ";
    // for (int i = 0; i < size; i++)
    // {
    //     /* code */
    //     cin>>arr[i];
    // }
    
    

    // insertionSort(arr, size);
    // bubbleSort(arr, size);
    // quickSort(arr, 0, size-1);
    // combSort(arr, size);
    // selectionSort(arr, size);

    for (int i = 0; i < size; i++)
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
                swapingValues(arr[i], arr[min]);

                // int temp = arr[i];
                // arr[i] = arr[min];
                // arr[min] = temp;
            }
        
    }
}



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
            // swap(arr[start], arr[end]);
            swapingValues(arr[start], arr[end]);
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
        quickSort(arr,lb,loc-1);
        quickSort(arr, loc+1, ub);  
    }
}


void combSort(int arr[], int n) 
{ 
  int gap = n; 

  while (gap != 1) 
  { 
     // Shrink the gap factor by 1.3
    gap = int(gap/1.3); 
    if (gap < 1) 
       gap= 1;

    for (int i=0; i<n-gap; i++) 
    { 
      if (arr[i] > arr[i+gap]) 
        swapingValues(arr[i], arr[i+gap]); 
    } 
  } 
}