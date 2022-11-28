#include <iostream>
#include <cstring>
using namespace std;

// Sudoku Class Definition
class Sudoku {
private:
	int N;
	int** Matrix;
public:
	// Constructor prototype
	Sudoku();
	
	// Input_In_Sudoku function prototype
	void Input_In_Sudoku();
	
	// Fill_Sudoku function prototype
	void Fill_Sudoku();
	
	//	Print_Sudoku function prototype
	void Print_Sudoku();
};

// Constructor definition
Sudoku::Sudoku(): N(9) {
	Matrix = new int*[N];
		for(int i = 0; i < N; i++)
			Matrix[i] = new int[N];
}

// For Taking Values from the user and Assignnig the last row and last column to "0"
// Input_In_Sudoku function prototype
void Sudoku::Input_In_Sudoku() {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
  			if(j == N-1 || i == N-1) // For initializing last row and column to "0"
				Matrix[i][j] = 0;
			else
				cin >> Matrix[i][j]; // For taking value except of last row and last column
		}
	}
}

// For counting the sum of row and column and filling the element which is missing element
// Fill_Sudoku function prototype
void Sudoku::Fill_Sudoku() {
	int row_sum = 0;
	int col_sum = 0;

	for(int i=0; i<N; i++) {
		for(int j = 0; j < N; j++) {
			if(j == N-1)
				Matrix[i][j] = 45 - row_sum;
			else
				row_sum = row_sum + Matrix[i][j];
		}
		row_sum = 0;
	}

	for(int j = 0; j < N; j++) {
		for(int i = 0; i < N; i++) {
			if(i == N-1)
				Matrix[i][j] = 45 - col_sum;
			else
				col_sum = col_sum + Matrix[i][j];
		}
		col_sum = 0;
	}
}

// For displaying the Solved Sudoku
// Print_Sudoku function prototype
void Sudoku::Print_Sudoku() {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cout << Matrix[i][j] << " ";
		}	cout << endl;
	}
}




// Driver Program
int main() {
	Sudoku S1; // Sudoku Object
	S1.Input_In_Sudoku();
	S1.Fill_Sudoku();
	S1.Print_Sudoku();
	
	return 0;
}
