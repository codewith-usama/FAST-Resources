#include<iostream>
using namespace std;

void check_friend(bool **array,int f, int l)
{
    if(array[f][l]==true)
    {
        cout<<"*"<<endl;
    }
    else
    cout<<"NO friends"<<endl;
}

void display(bool** a, int r, int c){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}

int main(){

bool** array;
    int row, col, i, j;
    
    cout << "Enter the number of rows" << endl;
    cin >> row;
    cout << "Enter the number of columns" << endl;
    cin >> col;
 
    //Dynamically allocating row space in heap
    array = new bool*[row];
    //Dynamically allocating column space in heap
    for(i=0; i<row; i++){
        array[i] = new bool[col];
    }
 
    //Taking input in the array
    cout << "Enter "<< (row * col) <<" numbers \n";
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            cout << "Enter element at "<< i+1 << " row " << j+1 << " column"<< endl;
            cin >> array[i][j];
        }
    }
 
    //Displaying array
    display(array, row, col);
    // Function_to_check_friend
    check_friend(array,0,4);
 
    //Free space after the use of array
    delete [] array;
                 
}

