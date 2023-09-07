#include<iostream>
using namespace std;

int main(){

int **arr = new int*[3];
int Size[3];
int i,j,k;
    for(i=0;i<3;i++){
        cout<<"Row "<<i+1<< " size: ";
        cin>>Size[i];
        arr[i] =new int[Size[i]];
    }
    for(i=0;i<3;i++){
        for(j=0;j<Size[i];j++){
            cout<<"Enter row " <<i+1<<" elements: ";
            cin>>*(*(arr + i) + j);
        }
    }

    for(i=0;i<3;i++){
        for(j=0;j<Size[i];j++){
            //cout<<"Enter row " <<i+1<<" elements: ";
            cout<<*(*(arr + i) + j)<<" ";
        }
    }    
}