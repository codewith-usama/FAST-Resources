// A safe array example.
#include <iostream>
#include <cstdlib>
#include<string.h>
using namespace std;


class DSA{
    int ncols;
    int *dynamicArray;

    public:
    // Default Constructor
        DSA(){
            ncols=0;;
            dynamicArray = NULL;
        }

        //Paramatrized Constructor
        DSA(int col){
            ncols=col;
            dynamicArray = new int[ncols];
        }

        //destructor
        ~DSA(){
            delete [] dynamicArray;
            dynamicArray=NULL;
        }


    //user inserting elements in 2d array
        void fillArray() {
            for (int in=0;in<ncols;++in){
                int value;
                cout<<"enter value";
                cin>>value;
                dynamicArray[in] = value;
            }
        }


    //bound checking-safe array implementation
    int &operator [](int i){
        if(i<0 || i> ncols-1 ) {
            cout << "Boundary Error\n";
            exit(1);
            }
        return dynamicArray[i];
    }


    //copy constructor
    DSA(const DSA& rhs) {
        ncols = rhs.ncols;
        dynamicArray = new int[ncols];
        memcpy(dynamicArray,rhs.dynamicArray, sizeof(int)*ncols);
        // copy all bytes of destination to source
        // memcpy(destination, source, sizeof(source));
    }


    //assignment operator
    DSA& operator=(const DSA& rhs)  {
        if (this == &rhs)
            return *this;

        delete[] dynamicArray;
        dynamicArray = NULL;
        ncols = rhs.ncols;
        dynamicArray = new int[ncols];
        memcpy(dynamicArray,rhs.dynamicArray, sizeof(int)*ncols);

        return *this;
    }
};










int main() {
    int columns;
    cout<<"enter cols"<<endl;
    cin>>columns;
    DSA ob1(columns);
    
    ob1.fillArray();
    DSA ob2=ob1;

    cout << ob1[1] << endl;

    cout<<ob2[4]<<endl; //checking bounds of array

    return 0;
}
