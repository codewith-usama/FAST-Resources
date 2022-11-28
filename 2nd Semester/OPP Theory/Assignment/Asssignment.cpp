#include <iostream>
#include <fstream>
using namespace std;
const int len = 500;
char input_rec[len];
char output_rec[len];

int main(){
    fstream file;
    file.open("input.txt");
    if(file.is_open()){
        file.read(input_rec, len);
        file.close();
    } else{
        cout<<"Can't open file!"<<endl;
    }
    int c = 0;
    bool cond = false;
    for(int l = 0; l < len; l++){
        cond = false;
            c = 0;
            continue;
        }
        else if(c == 2){
            if(input_rec[l] == 49 && input_rec[l+1] <= 57){
                int cond = (int) input_rec[l+1] + 25;
                output_rec[l] = (char) cond;
            } else if(input_rec[l] == 50 && input_rec[l+1] <= 54){
                int cond = (int) input_rec[l+1] + 36;
                output_rec[l] = (char) cond;
            }
        }
        else if(c == 1){
            int cond = (int) input_rec[l] + 16;
            output_rec[l]= (char) cond;
            c = 0;
        } 
    }
    //ofstream file;
    file.open("definiaz.txt");
    if(file.is_open()){
        for(int l = 0; l<200; l++){
        	if(output_rec[l]!=NULL)
            file.put(output_rec[l]);
            else
            continue;
        }
    } 
	else{
        cout<<"ERROR! Unable to open file!"<<endl;
    }
}
