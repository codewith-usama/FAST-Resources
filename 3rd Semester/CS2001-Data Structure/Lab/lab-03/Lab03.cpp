// // 1 , 3 , 6 , 10 , 15 , 21 , 28 . . . .

// #include<iostream>
// using namespace std;

// int main(){

//     int n;
//     int sum = 0;
//     cin>>n;
//     for (int i = 0; i < n; i++)
//     {
//         /* code */
//         sum += i;
//         sum+=1;
//         cout<<sum<<" ";

//     }
    

//     return 0;
// }


// #include<iostream>
// using namespace std;

// int main ()
// {
//     int n;
//     int Sum = 0;
//     cout<<"Enter how many numbers: ";
//     cin>>n;
//     for (int i = 0; i < n; i++)
//     {
//         /* code */
//         Sum+=i;
         
//         Sum+=1;
//         cout<<Sum<<" ";
//     }
//     cout<<endl;
    
// }


// 1 , 3 , 6 , 10 , 15 , 21 , 28 . . . .

// #include<iostream>
// using namespace std;

// int seq(int n,int first=0, int second =0)
// {

    

//     if (n==1)
//     return second;
//     second++;
//     return seq(n-1, second, first+second);
// }

// int main(){

//     cout<<seq(5)<<endl;

//     return 0;
// }

// Task 1B Through Loop

// #include<iostream>
// using namespace std;

// int main(){

//     int num, first = 1, second =0;

//     cout<<"Enter the Number of Series: ";
//     cin>>num;

//     for (int i = 0; i < num; i++)
//     {
//         /* code */
//         first = first+second;
//         cout<<first<<" ";
//         second++;
//     }
    

//     return 0;
// }


// Task 1B Through Function recursion

#include<iostream>
using namespace std;
int seq_generate(int n)
{
    int sum = 0;

    if(n==0){
        return 0;
    }

    return n+seq_generate(n-1);
}

int main(){

    int n;
    cout<<"Enter any Number for sequence: ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        /* code */
        cout<<seq_generate(i)+1<<" ";
    }
    return 0;
}


// Task 3
// #include<iostream>
// using namespace std;

// void seq(int);   // Function Prototypes
// void funct(int, int);

// void seq(int x)
// {
//     static int n =1;
//     x = x+n;
//     n++;
//     funct(x,n);
// }

// void funct(int b, int n)
// {
//     if(n>=8)
//     exit(1);
//     else{
//         cout<<b<<"  ";
//         seq(b);
//     }
// }

// int main(){

//     seq(0);

//     return 0;
// }

// Task 4

// #include<iostream>
// using namespace std;

// int fun1(int arr[], int i, int j)
// {
//     if(i==j)
//         return j;

//     int x = fun1(arr,i+1,j);
//     if(arr[i]<arr[x])
//     {
//         return i;
//     }
//     else
//         return x;
// }
// void recursion_fun(int arr[], int N, int index = 0)
// {
//     if(index==N)
//     {
//         return;
//     }
//     int k= fun1(arr, index, N-1);
//     if(k!=index)
//     {

//     }
//     swap(arr[k], arr[index]);
//     recursion_fun(arr,N,index+1);
// }

// int main(){

//     int arr[] = {2, 3, 4, 5, 6};
//     int N = Nof(arr)/Nof(arr[0]);
//     recursion_fun(arr, N);
//     for (int i = 0; i < N; i++)
//     {
//         /* code */
//         cout<<arr[i]<<" ";
//         cout<<endl;
//     }

//     return 0;
// }

// TASK 5


// #include<iostream>
// using namespace std;

// #define N 4

// bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]);

// void printSolution(int sol[N][N])
// {
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < N; j++)
//         {
//             cout<<sol[i][j]<<" ";
//         }
//         cout<<"\n";
        
//     }
    
// }

// bool isSafe(int maze[N][N], int x, int y)
// {
//     if ( x>=0 && x<N && y>=0 && y<N && maze[x][y]==1)
//         return true;

//     return false;
// }

// bool solveMaze(int maze[N][N])
// {
//     int sol[N][N] = {{0, 0, 0, 0},
//                      {0, 0, 0, 0},
//                      {0, 0, 0, 0},
//                      {0, 0, 0, 0}};

//     if (solveMazeUtil(maze, 0, 0, sol)==false) {
//         cout<<"Solution Doesn't Exist ";
//         return false;
//     }

//     printSolution(sol);
//     return true;
// }

// bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
// {
//     if (x == N-1 && y == N -1 && maze[x][y]==1) {
//         sol[x][y] =1;
//         return true;
//     }

//     if(isSafe(maze, x, y)==true) {
//         if (sol[x][y] == 1)
//             return false;

//         sol[x][y] = 1;

//         if(solveMazeUtil(maze, x+1, y, sol)==true)
//             return true;

//         if(solveMazeUtil(maze, x, y+1, sol)==true)
//             return true;

//         sol[x][y] = 0;
//         return false;
//     }

//     return false;


// }

// int main(){\
//     int maze[N][N] = {{1, 0, 0, 0},
//                       {1, 1, 0, 1},
//                       {0, 1, 0, 0},
//                       {1, 1, 1, 1}};

//     solveMaze(maze);
    

//     return 0;
// }