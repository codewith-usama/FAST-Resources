#include<iostream>
using namespace std;


void __heapify(int a[], int n, int i){
    int largest = i;
    int left = 2*i +1;
    int right = 2*i + 2;

    if(left<n  && a[left] > a[largest]){
        largest = left;
    }      
    if(right< n && a[right] > a[largest]){
        largest = right;
    }      

    if(largest != i){
        swap(a[i], a[largest]);
        __heapify(a, n, largest);
    }
}   //      end __heapify()

void __heapSort(int a[], int n){
    for (int i= n/2-1; i >=0; i--)
    {
        __heapify(a, n, i);
    }

    
    for (int i = n-1; i >= 0; i--)
    {
        swap(a[i], a[0]);
        __heapify(a, i, 0);
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << "\n\t " << a[i];
    }
    
}

int main(){
    int a[] = {15, 5, 20, 1, 17, 10, 30};
    int n = sizeof(a)/sizeof(a[0]);

    __heapSort(a,n);

    return 0;
}