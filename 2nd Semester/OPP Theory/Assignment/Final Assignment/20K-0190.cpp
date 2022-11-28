#include<iostream>
#include<fstream>
using namespace std;

int main() {
	int length = 200;
	char inp_data[length]; // for the length of input data
	char out_data[length]; // for the length of output data
	fstream fin;
	fin.open("input.txt");
	if(fin.is_open()) {
		fin.read(inp_data, length);
		fin.close();
	}
	else
		cout << "Error in opening File(input.txt)\n";
	bool condition = false;
	for(int i = 0; i < length; i++) {
		condition = false;
		int a;
		if(inp_data[i] > 48 && inp_data[i] < 58) {
			for(int j = i; inp_data[j] > 48 && inp_data[j] > 58; j++) {
			++a;
				if(inp_data[j] > 49 && inp_data[j + 1] > 48)
					condition = true;	
			}
		}
		if(a > 2 && condition == true) {
			out_data[i] = 'Z'; // for number greater than 26 and less than 1
			a = 0;
			continue;
		}
		else if(a == 2) {
			if(inp_data[i] == 49)
				if(inp_data[i+1] < 58) {
					int condition = (int) inp_data[i+1] + 25;
					out_data[i] = (char) condition;
				}
				else if(inp_data[i] == 50 && inp_data[i+1] < 55) {
					int condition = (int) inp_data[i+1] + 36;
	                out_data[i] = (char) condition;
				}
		}
		else if(a == 1) {
			int condition = (int) inp_data[i] + 16;
			out_data[i] = (char) condition;
			a = 0;
		}	
	}
	fin.open("definiaz.txt");
    if(fin.is_open()){
        for(int i = 0; i < 200; i++){
        	if(out_data[i] != 0)
            fin.put(out_data[i]);
            else
            continue;
        }
    }
	else
        cout<<"Error in opening File(definiaz.txt)";
}
