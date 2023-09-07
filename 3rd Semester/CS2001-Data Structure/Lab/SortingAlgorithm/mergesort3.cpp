#include<iostream>
using namespace std;

void Mergesort(int a[], int a2[], int n, int m, int result[]) {
    int i = 0 , j = 0 , k = 0;

    while(i < n && j < m) {
        if(a[i] <= a2[j]) {
            result[k] = a[i];
            k++;
            i++;
        }

        else {
            result[k] = a2[j];
            k++;
            j++;
        }

    }

    while(i<n) {result[k] = a[i];
        k++; i++;
    }
    while(j<m) {result[k] = a2[j];
        k++; j++;
    }
    for (int i = 0; i < 6; i++) {
        cout<<result[i]<<" ";
    }
}

int main(){

    int a[] = {5,6};
    int a2[] = {1,2, 3, 4};

    int result[6]= {0};

    Mergesort(a, a2, 2, 4, result);

    
    

    return 0;
}