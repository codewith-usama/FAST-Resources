#include<iostream>
using namespace std;

int Partician(int a[], int lb, int ub) {
    int pivot = a[lb];
    int start = lb;
    int end = ub;

    while(start < end ) {
        while(a[start]<=pivot) {
            start++;
        }
        while(a[end]>pivot) {
            end--;
        }

        if(start < end) {
            swap(a[start], a[end]);
        }
    }

    swap(a[lb], a[end]);
    return end;
}

void quickSort(int a[], int lb, int ub) {
    if(lb<ub) {
        int loc = Partician(a, lb, ub);
        quickSort(a, loc+1, ub);
        quickSort(a, lb, loc-1);
    }
}

int main(){

    int a[] = {-7,0, 5, 2};
    quickSort(a, 0, 3);

    for (int i = 0; i < 4; i++)
    {
        cout<<a[i]<<" ";
    }
    
    return 0;
}